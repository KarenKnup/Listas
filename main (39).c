/*
Dadas duas listas L1 e L2, ambas do tipo TLista, 
implementar uma função que crie uma lista L3, 
também do tipo TLista, com as seguintes 
características:
a. Os elementos de L2 devem estar no final de L3, na 
mesma ordem que aparecem em L2;
b. Os elementos de L1 devem estar no início de L3, na 
ordem inversa à que aparecem em L1
*/

#include <stdio.h>
#include <stdlib.h>

//definição de constantes
#define TRUE 1
#define FALSE 0
  
typedef struct No {
	int valor;
  int pos;
	struct No* prox; 
} TNo;

typedef TNo* TLista; 

int inserir (TLista *L, int numero){
	TLista aux; 
  
	aux = (TLista) malloc (sizeof(TNo));

  TLista aux2=aux->prox;
  
	if (aux == NULL){ 
		return FALSE;
	}	else{
		aux->valor = numero; //aux->valor = *aux.valor
    
		aux->prox = *L;
		
		*L = aux;
		
		return TRUE;
	}
}

void exibir (TLista L){
	//declaração de variáveis
	TLista aux = L;
	
	//testando se a lista está vazia
	if (!L){ //L==NULL 
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

void Lista3 (TLista L1, TLista L2, TLista *L3){
    //Lista 2 - final
  TLista aux=NULL;
  while(L2){
    inserir(&aux,L2->valor);

    L2=L2->prox;
  }

  while(aux){
    inserir(L3,aux->valor);

    aux=aux->prox;
  }

  //Lista 1 - início
  while(L1){
    inserir(L3,L1->valor);

    L1=L1->prox;
  }
}

int main(void){
  TLista L1=NULL, L2=NULL, L3=NULL;

  printf("\n-------- LISTA 1 ---------\n");
  inserir(&L1,1);
  inserir(&L1,2);
  inserir(&L1,3);
  exibir(L1);

  printf("\n\n-------- LISTA 2 ---------\n");
  inserir(&L2,6);
  inserir(&L2,5);
  inserir(&L2,4);
  exibir(L2);

  printf("\n\n-------- LISTA 3 ---------\n");
  printf("--> Elementos de L2 no final de L3, mantendo a mesma ordem");
  //4 5 6
  printf("\n--> Elementos de L1 no início de L3, na ordem inversa\n"); 
  //1 2 3
  Lista3(L1,L2,&L3); //1 2 3 4 5 6
  exibir(L3);

  return 0;
}
