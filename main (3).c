#include <stdio.h>
#include <stdlib.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//definição de tipos
typedef struct No { //struct No = TNo
	int valor;
	struct No* prox; //TNo ainda n foi declarada
} TNo;

typedef TNo* TLista; //para não precisar usar **

//implementação das funções
TLista buscar (TLista L, int numero){
	//declaração de variáveis
	TLista aux = L;
	
	//percorrendo a lista até o seu final
	while (aux != NULL)	{
		//testando se é o valor sendo buscado
		if (aux->valor == numero)	{
			return aux;
		}
			
		//atualizando o 'aux' para apontar para o próximo nó
		aux = aux->prox;
	}
	
	//se chegou a este ponto, o número buscado não existe
	return NULL;	
}

int inserir (TLista *L, int numero){
  //declaração de variáveis;
	TLista aux;
	
	//verificando se o elemento não existe na lista
	if (buscar (*L, numero) == FALSE)	{	
		//1º passo: alocar memória para o novo nó	
		aux = (TLista) malloc (sizeof(TNo));
		
		//verificando se houve erro na alocação de memória
		if (aux == NULL){
			return FALSE;
		}	else {
			//2º passo: armazenar 'numero' na memória recém-alocada
			aux->valor = numero;
			
			//3º passo: mandar o campo 'prox' do novo nó apontar para o "até então" primeiro elemento	da lista
			aux->prox = *L;
			
			//4º passo: fazer com que L aponte para o novo nó da lista		
			*L = aux;
			
			return TRUE;
		}
	}	else {
		return FALSE;
	}
}

int remover (TLista *L, int numero){
	//declaração de variáveis
	TLista aux1, aux2;
	
	//verificando se o primeiro elemento da lista é o número que deseja-se remover
	if ((*L) && ((*L)->valor == numero)) {
		//fazendo o aux1 apontar para o primeiro elemento da lista
		aux1 = *L;
		
		//fazer o L apontar para o "segundo" elemento da lista
		*L = aux1->prox;     //*L = (*L)->prox;
		
		//liberando a memória do nó apontado por 'aux1'
		free (aux1);
		
		//retornando TRUE, pois a remoção foi realizada
		return TRUE;		
	}
	
	//verificando se ainda há elementos na lista
	if (*L)	{
		//colocando os auxiliares 'aux2' e 'aux1' no primeiro e segundo nós, respectivamente
		aux2 = *L;
		aux1 = (*L)->prox;	
		
		//percorrendo a lista com 'aux1'
		while (aux1) {
			//verificando se o 'aux1' está apontando para 'numero'
			if (aux1->valor == numero) {
				//removendo o valor apontado por 'aux1'
				aux2->prox = aux1->prox;
				
				//removendo o nó que guarda o 'numero'
				free (aux1);
								
				//retornando TRUE, pois o elemento foi removido
				return TRUE;
			}	else {
				//andando com os dois auxiliares
				aux2 = aux1;
				aux1 = aux1->prox;
			}
		}
	}
	
	//retornando FALSE, pois o elemento não pertence à lista
	return FALSE;
}

int alterar (TLista L, int velho, int novo){
	//declaração de variáveis
	TLista aux = L;
	int respVelho, respNovo;
	
	//verificando se o 'velho' existe
	respVelho = buscar (L, velho);
	
	//verificando se o 'novo' existe
	respNovo = buscar (L, novo);
	
	if (respVelho && !respNovo)
	{
		//realizando a alteração
		respVelho->valor = novo;
		//(*respVelho).valor = novo;
		
		return TRUE;
	}

	//retornando FALSE, pois a operação não foi realizada
	return FALSE;
}

void exibir (TLista L){
	//declaração de variáveis
	TLista aux = L;
	
	//testando se a lista está vazia
	if (L == NULL){ 
		printf ("\nLista vazia!");
	}	else	{
		printf ("\nElementos da lista: ");
		
		//percorrendo a lista até o seu final
		while (aux != NULL)	{
			//exibindo o valor apontado pelo 'aux'
			printf ("%d ", aux->valor);
			
			//atualizando o 'aux' para apontar para o próximo nó
			aux = aux->prox;
		}
	}
}


int menu (){
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Inserir\n");
	printf ("(2) Remover\n");
	printf ("(3) Alterar\n");
	printf ("(4) Buscar\n");
	printf ("(5) Exibir\n");
	printf ("(6) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}

int main(void) {
//declaração de variáveis
	TLista L = NULL;
	int num1, num2, op, quant, resp;
	
	do{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usuário
		op = menu ();
		
		//verificando a opção escolhida
		switch (op){
			//Inserir
			case 1: printf ("\nEntre com o valor a ser inserido: ");
			        scanf ("%d", &num1);
			        
			        //chamando a função
			        if (inserir (&L, num1) == TRUE){
			        	printf ("\n\tInsercao realizada com sucesso!");
					} else {
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;

			//Remoção
			case 2: printf ("\nEntre com o valor a ser removido: ");
			        scanf ("%d", &num1);
			        
			        //chamando a função
			        quant = remover (&L, num1);
			        
					if (quant > 0)
			        {
			        	printf ("\n\t%d remocoes realizadas!", quant);
					}
					else
					{
						printf ("\n\tERRO: remocao nao realizada!");
					}
					break;

			//Alteração
			case 3: printf ("\nEntre com o valor a ser alterado: ");
			        scanf ("%d", &num1);
			        
			        printf ("\nEntre com o novo valor: ");
			        scanf ("%d", &num2);
			        
			        //chamando a função
			        quant = alterar (L, num1, num2);
			        
			        if (quant > 0){
			        	printf ("\n\t%d alteracoes realizadas!", quant);
					} else {
						printf ("\n\tERRO: alteracao nao realizada!");
					}
					break;

			//Busca
			case 4: printf ("\nEntre com o valor a ser buscado: ");
			        scanf ("%d", &num1);
			        
			        //chamando a função
			        resp = buscar (L, num1);
			        
					if (resp == TRUE) {
			        	printf ("\n\tO valor %d foi encontrado na lista!", num1);
					}	else{
						printf ("\n\tO valor %d NAO foi encontrado na lista!", num1);
					}
					break;

			//Exibir
			case 5: exibir (L);
					break;
					
			//Saída
			case 6: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}	while (op != 6);
  
  return 0;
}
