#include <stdio.h>
#include <stdlib.h>

/*
Fazer uma função que, dada uma lista encadeada L, do
tipo TLista, determine se seus elementos formam uma
Progressão Geométrica (PG), retornando 0 ou 1,
dependendo do resultado.
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

int Verifica (TLista L1){
  TLista aux=L1, aux2=L1->prox;
  int q=(aux2->valor)/(aux->valor);
  float q2;
  
  while(aux2){
    if(aux2->valor != ((aux->valor)*q)){ 
      q2=(aux->valor)/(aux2->valor);
      if(aux2->valor != ((aux->valor)/q2)){ 
        return FALSE;
        }
    }

    aux2=aux2->prox;
    aux=aux->prox;
  }
  
  return TRUE;
}

int main(void){
  TLista L1=NULL, L2=NULL;

  printf("\n------------ LISTA 1 --------------\n");
    inserir(&L1,8);
    inserir(&L1,4);
    inserir(&L1,2);
    exibir(L1);

  if(Verifica(L1)==TRUE){
       printf("\n\n\tEssa lista é uma PG!");
     } else {
       printf("\n\n\tEssa lista NÃO é uma PG!");
     }

 printf("\n\n\n------------ LISTA 2 --------------\n");
    inserir(&L2,9);
    inserir(&L2,4);
    inserir(&L2,2);
    exibir(L2);
     
  if(Verifica(L2)==TRUE){
       printf("\n\n\tEssa lista é uma PG!");
     } else {
       printf("\n\n\tEssa lista NÃO é uma PG!");
     }

  
    return 0;
  }
