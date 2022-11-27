/*
Fazer uma função que, dados uma lista
encadeada L, do tipo TLista, cujos
elementos estão ordenados
CRESCENTEMENTE, e um número n, remova
todas as ocorrências de n em L.
*/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

//definição de tipos
typedef struct No { //struct No = TNo
	int valor;
	struct No* prox; //TNo ainda n foi declarada
} TNo;

typedef TNo* TLista; //para não precisar usar **

int inserir (TLista *L, int n){	
  //Declaração de variáveis
  TLista aux, aux1, aux2;
  
  if ((*L == NULL) || ((*L)->valor >= n)) {
    //Inserir o primeiro numero da lista
  	//1º passo: alocar memória para o novo nó	
    TLista aux = (TLista)malloc(sizeof(TNo));
    //2º passo: armazenar 'numero' na memória recém-alocada
      aux->valor = n;
    //3º passo: mandar o campo 'prox' do novo nó apontar para o "até então" primeiro elemento	da lista (Fazendo o novo apontar para o antigo primeiro nó)
      aux->prox = *L;
    //4º passo: fazer com que L aponte para o novo nó da lista		
      *L = aux;
    
    return TRUE;
  }

   aux = *L;
   aux1 = (*L)->prox;

  while (aux1 != NULL) { //while(aux1)
    if (aux1->valor >= n) {
      //Inserindo um numero na posição atual
      aux2 = (TLista)malloc(sizeof(TNo));
      aux2->valor = n;
      aux2->prox = aux2;
      aux->prox = aux2;
      }
    
    //andando com os dois auxiliares
    aux = aux->prox;
    aux1 = aux1->prox;
    
  }

  //Último número da lista
  aux = (TLista)malloc(sizeof(TNo));
  aux->valor = n;
  aux->prox = NULL;
  aux1->prox = aux;
  
  return TRUE;
}

int remover (TLista *L, int n){
	//declaração de variáveis
	TLista aux1, aux2;
	int cont = 0; //quantidade de remoções feitas
	
	//verificando se o primeiro elemento da lista é o número que deseja-se remover
	while ((*L) && ((*L)->valor == n))	{
		//fazendo o aux1 apontar para o primeiro elemento da lista
		aux1 = *L;
		
		//fazer o L apontar para o "segundo" elemento da lista
		*L = aux1->prox;     //*L = (*L)->prox;
		
		//liberando a memória do nó apontado por 'aux1'
		free (aux1);
		
		//atualizando o número de remoções realizadas
		cont++;
	}
	
	//verificando se ainda há elementos na lista ~ remover do resto da lista
	if (*L)	{
		//colocando os auxiliares 'aux2' e 'aux1' no primeiro e segundo nós, respectivamente
		aux2 = *L;
		aux1 = (*L)->prox;	
		
		//percorrendo a lista com 'aux1'
		while (aux1){
			//verificando se o 'aux1' está apontando para 'numero'
			if (aux1->valor == n){
				//removendo o valor apontado por 'aux1'
				aux2->prox = aux1->prox;
				
				//removendo o nó que guarda o 'numero'
				free (aux1);
				cont++;
				
				//fazendo 'aux1' apontar para o próximo elemento da lista
				aux1 = aux2->prox;				
			} else {
				//andando com os dois auxiliares
				aux2 = aux1;
				aux1 = aux1->prox;
			}
		}
	}
	
	//retornando a quantidade de remoções realizadas
	return cont;
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
	printf ("\n\n-------- Menu de Operacoes: ---------\n\n");
	printf ("(1) Inserir\n");
  printf ("(2) Remover\n");
  printf ("(3) Exibir\n");
	printf ("(4) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}

int main(void) {
TLista L=NULL;
  int op, n, quant;

  do {
    system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usuário
		op = menu ();

    switch (op){
      //Inserir
			case 1: printf ("\nEntre com o valor a ser inserido: ");
			        scanf ("%d", &n);
			        
			        //chamando a função
			        if (inserir (&L, n) == TRUE){
			        	printf ("\n\n\tInsercao realizada com sucesso!");
					} else {
						printf ("\n\n\tERRO: insercao nao realizada!");
					}
					break;
      
      //Remoção
			case 2: printf ("\nEntre com o valor a ser removido: ");
			        scanf ("%d", &n);
			        
			        //chamando a função
			        quant = remover (&L, n);
			        
					if (quant > 0)
			        {
			        	printf ("\n\t%d remocoes realizadas!", quant);
					}
					else
					{
						printf ("\n\tERRO: remocao nao realizada!");
					}
					break;
      
      //Exibir
			case 3: exibir (L);
					break;
      
      //Saída
			case 4: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
    }
    
  } while (op!=4);

  
    return 0;
}
