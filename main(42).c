#include <stdio.h>

/*
Desenvolver uma função que, dada uma lista 
encadeada L do tipo TLista e dois números 
inteiros A e B, retorne o número de elementos 
de L que encontram-se no intervalo [A, B].
  */

#include <stdlib.h>

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

int QtdeNoIntervalo (int A, int B, TLista L){
  TLista aux=L;
  int qtde=0;

  while(aux){
    if(aux->valor >= A && aux->valor <= B){
      qtde++;
    }

    aux=aux->prox;
  }
  
  return qtde;
}

int main(void) {
  TLista L=NULL;
  int A,B;

  inserir(&L,1);
  inserir(&L,2);
  inserir(&L,3);
  inserir(&L,4);
  inserir(&L,5);
  inserir(&L,6);
  inserir(&L,7);
  inserir(&L,8);
  exibir(L);
  
  printf("\n\nA: ");
  scanf("%d",&A);
  printf("B: ");
  scanf("%d",&B);
    while(B<A){
      printf("B deve ser maior que A! Digite B: ");
      scanf("%d",&B);
    }

  printf("\n\tTem %d números no intervalo [%d,%d]",QtdeNoIntervalo(A,B,L),A,B);
  
  return 0;
  }