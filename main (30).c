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

int busca(int num, TLista L){
  while(L){
    if(L->valor ==num){
      return TRUE;
    }
    
    L=L->prox;
  }  
  return FALSE;
}

int novaL(TLista A, TLista B, TLista *AUX, TLista *C){

  if(!A || !B){
    return FALSE;
  } else {
    while(A){
      if(busca(A->valor,B)==FALSE){
        inserir(C,A->valor);
      }

      A=A->prox;
    }
  }
  return TRUE;
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
    Fun(&aux,*L1);
  
  TLista aux2=*L1;
  while(aux2){
    aux2->valor = aux->valor;

    aux=aux->prox;
    aux2=aux2->prox;
  }
}

int main(void) {
  TLista A=NULL, B=NULL, C=NULL, AUX=NULL;

   printf("\n------------ LISTA A --------------\n");
    inserir(&A,6);
    inserir(&A,8);
    inserir(&A,2);
    inserir(&A,3);
    inserir(&A,0);
    exibir(A);

  printf("\n\n\n------------ LISTA B --------------\n");
    inserir(&B,6);
    inserir(&B,7);
    inserir(&B,8);
    inserir(&B,9);
    inserir(&B,0);
    exibir(B);

  printf("\n\n\n------------ LISTA C --------------\n");//todos os elementos de A que NÃO estão em B
    if(novaL(A,B,&AUX,&C)==TRUE){
        Inverte(&C,AUX);
        exibir(C);
      }
  
  return 0;
}