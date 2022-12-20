#include <stdio.h>
#include <stdlib.h>

/*
Dada uma lista encadeada L, do tipo TLista,
desenvolver uma função que inverta a ordem de seus
elementos.
  */
#define TRUE 1
#define FALSE 0

//definição de tipos
typedef struct No { //struct No = TNo
	int valor;
	struct No* prox; //TNo ainda n foi declarada
} TNo;

typedef TNo* TLista; //para não precisar usar **


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

int inserir (TLista *L, int numero){
	//declaração de variáveis;
	TLista aux; 
  
	aux = (TLista) malloc (sizeof(TNo));
 
	if (aux == NULL){
		return FALSE;
	}	else{
		aux->valor = numero; //aux->valor = *aux.valor
		
		aux->prox = *L;
		
		//4º passo: fazer com que L aponte para o novo nó da lista		
		*L = aux;
		
		return TRUE;
	}
}

int Fun (TLista *aux, TLista L1){
int n;
  TLista aux2=L1, aux3=*aux;
  
  while(aux2){
    n=inserir(aux,aux2->valor);

    if(n == TRUE){
    aux2=aux2->prox;
      } else {
      break;
      }
  }
}

void Inverte (TLista *L1, TLista aux){
  TLista aux2=*L1;
  while(aux2){
    aux2->valor = aux->valor;

    aux=aux->prox;
    aux2=aux2->prox;
  }
}


int main(void){
  TLista L1=NULL, aux=NULL;
  
    inserir(&L1,5);
    inserir(&L1,4);
    inserir(&L1,3);
    inserir(&L1,2);
    exibir(L1);

    printf("\n\n------- LISTA INVERTIDA --------\n");
    Fun(&aux,L1);
    Inverte(&L1,aux);
    exibir(L1);

  
return 0;
  }

//---------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#define TRUE 0
#define FALSE 1
  
typedef struct No {
	int valor;
	struct No* prox; 
} TNo;

typedef TNo* TLista; 

int inserir (TLista *L, int numero){
	TLista aux; 

  
	aux = (TLista) malloc (sizeof(TNo));

  
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

void Inverte (TLista A, TLista *B){
  TLista aux=A;

  if(aux){
    Inverte(aux->prox,B);
    inserir(B,A->valor);
    aux=NULL;
  }
}

void Normal (TLista A, TLista *B){
  while(A){
    inserir(B,A->valor);
    
    A=A->prox;
  }
}

int main(void) {
  TLista A=NULL, B=NULL;

   printf("\n------------ LISTA A --------------\n");
    inserir(&A,1);
    inserir(&A,2);
    inserir(&A,3);
    inserir(&A,4);
    inserir(&A,5);
    exibir(A);

  printf("\n\n\n------------ LISTA B --------------\n");
    //Normal(A,&B); //ordem oposta de A
    Inverte(A,&B); //mesma ordem de A
    exibir(B);

  
  return 0;
}
