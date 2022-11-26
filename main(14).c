/*
  QUESTÃO 05:
Implementar uma função que, dadas duas listas dinâmicas do tipo TLista, verifique se elas possuem os mesmos elementos, independente da ordem na qual apareçam.

Exemplos:
	L1: 1 2 3 4
	L2: 4 3 2 1 - SIM

	L1: 1 2 3
	L2: 4 3 2 1 - NÂO

	L1: 1 2 3 4
	L2: 4 1 2 3 1 2 3 - SIM - o enunciado não falou de mesma quantidade
*/

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
int inserir (TLista *L, int numero){//(*)Ou seja, pode alterar tudo que estiver em TLista
  /*
1° Alocar memória p o novo elemento com um aux
2° Armazenar o elemento novo no novo nó
3° Armazenar no campo prox do novo nó o endereço daquele que, até então, era o primeiro elemento
4° Fazer o L apontar para o novo nó
*/
  
	//declaração de variáveis;
	TLista aux; 
//aux: endereço do nó que armazena o 10 (primeiro valor)
//aux-> : o nó que armazena o valor 10

	
	//1º passo: alocar memória para o novo nó	
	aux = (TLista) malloc (sizeof(TNo));
  //malloc (alloc.h) - comando em C p alocar memória- memory allocation - ele dá como retorno um (*void) ponteiro void, um valor indeterminado que n sabe praq vai usar, por isso se acompanha pela Tlista

//sizeof-diz quantos bytes ocupa 
	
	//verificando se houve erro na alocação de memória
	if (aux == NULL){ //if(!aux) ~~ não conseguiu alocar memória 
    //ponteiro NULL - indica que finalizou a lista
		return FALSE;
	}	else{
    //1°passo OK
    //Inserindo o valor 
		//2º passo: armazenar 'numero' na memória recém-alocada
		aux->valor = numero; //aux->valor = *aux.valor
		
		//3º passo: mandar o campo 'prox' do novo nó apontar para o "até então" primeiro elemento	da lista (Fazendo o novo apontar para o antigo primeiro nó)
		aux->prox = *L;
		
		//4º passo: fazer com que L aponte para o novo nó da lista		
		*L = aux;
		
		return TRUE;
	}
}

void exibir (TLista L){
	//declaração de variáveis
	TLista aux = L;
	
	//testando se a lista está vazia
	if (L == NULL){ 
		printf ("\nLista vazia!");
	}	else	{
		printf ("\n---------- Elementos da lista: ----------\n");
		
		//percorrendo a lista até o seu final
		while (aux != NULL)	{
			//exibindo o valor apontado pelo 'aux'
			printf ("Valor do nó: %d\n", aux->valor);
			
			//atualizando o 'aux' para apontar para o próximo nó
			aux = aux->prox;
		}
	}
}

TLista buscar (TLista L, int numero){
	//declaração de variáveis
	TLista aux = L;

	//percorrendo a lista até o final
	while (aux != NULL){
		//testando se é o valor sendo buscado
		if (aux->valor == numero){
		//retornando o endereço do nó que contém o valor buscado
			return aux;
		}
	//atualizando o 'aux' para apontar para o próximo nó
	aux = aux->prox;
	}

//se chegou a este ponto, o número buscado não existe
	return NULL;
}

int estaContida (TLista L1, TLista L2){ //saber se todos L1 estão em L2
	//declaração de variáveis
	TLista aux; //vai percorrer a lista

	//inicializando 'aux' com o endereço do primeiro nó de 'L1'
	aux = L1;

	//percorrendo 'L1' com 'aux'
	while (aux){
		//testando cada elemento de 'L1' em 'L2'
		if (buscar(L2, aux->valor) == NULL){
			return FALSE;
		}
		//atualizando 'aux'
		aux = aux->prox;
	}
//se chegou aqui, todos os elementos de 'L1' foram encontrados em 'L2'
	return TRUE;
}

int verificarMesmosElementos (TLista lista1, TLista lista2){//agora vai responder a questão
	/*if(estaContida(lista1, lista2)==TRUE) && (estaContida(lista2, lista1)==TRUE)){
		return TRUE;
	} else {
		return FALSE;
	}*/

//se uma delas for F, o resultado será F
	return estaContida(lista1, lista2) && estaContida(lista2, lista1);
}

int menu (){
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Inserir\n");
	printf ("(2) Exibir\n");
	printf ("(3) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}

int main(void) {
//declaração de variáveis
	TLista L = NULL;
  TLista L2 = NULL;
	int num1, op;

printf("\n+++++++++++++++ Lista 1 +++++++++++++++++\n");
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
      
			//Exibir
			case 2: exibir (L);
					break;
					
			//Saída
			case 3: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}	while (op != 3);

  printf("\n\n+++++++++++++++ Lista 2 +++++++++++++++++\n");
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
			        if (inserir (&L2, num1) == TRUE){
			        	printf ("\n\tInsercao realizada com sucesso!");
					} else {
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;
      
			//Exibir
			case 2: exibir (L2);
					break;
					
			//Saída
			case 3: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}	while (op != 3);
  
  printf("\n\n+++++++++++++++ RESULTADO +++++++++++++++++\n");
  if(verificarMesmosElementos(L,L2)==TRUE){
    printf("\n\tAs duas listas possuem os mesmos valores!");
  } else {
    printf("\n\tAs listas são diferentes!");
  }
  
  return 0;
}