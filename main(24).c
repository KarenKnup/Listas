#include <stdio.h>
#include <stdlib.h>

/*
 Considere uma lista L1, do tipo TLista, contendo 
números inteiros ordenados crescentemente. Pede-se 
a implementação de uma função que crie uma nova 
lista, L2, também do tipo TLista, com os mesmos 
elementos de L1, também ordenados crescentemente, 
porém sem repetições.
*/

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
  TLista aux = *L, novo;

  //abrindo espaço para o novo nó que vai ser inserido
  novo=(TLista)malloc(sizeof(TNo));

  if(!novo){
    return FALSE;
  }
  
  //insere n digitado no novo nó
  novo -> valor = n;

  if (!(*L)){ //lista vazia
    novo->prox = NULL;
    *L = novo;
  } else{
    if (n <= (aux->valor)){ 
      novo -> prox = aux;
      *L = novo;      
    } else{
      while ((aux->prox->valor) < n && (aux->prox)){
        aux = aux-> prox;
      }
      novo->prox=aux->prox;
      aux->prox=novo;
    } 
  }
  return TRUE;
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

int inserirSemRepet (TLista *L, int n){	
  //Declaração de variáveis
  TLista aux = *L, novo;

  //abrindo espaço para o novo nó que vai ser inserido
  novo=(TLista)malloc(sizeof(TNo));

  if(!novo){
    return FALSE;
  }
  
  //insere n digitado no novo nó
  novo -> valor = n;

  if (!(*L)){ //lista vazia
    novo->prox = NULL;
    *L = novo;
  } else{
  if(buscar(*L,n)==NULL){
    if (n <= (aux->valor)){ 
      novo -> prox = aux;
      *L = novo;      
    } else{
      while ((aux->prox->valor) < n && (aux->prox)){
        aux = aux-> prox;
      }
      novo->prox=aux->prox;
      aux->prox=novo;
    } 
  } else {
    return FALSE;
  }
 }
  return TRUE;
}

void ListaSemRepet (TLista L1, TLista *L2){
  TLista aux=L1;
  while(aux){
   inserirSemRepet(L2,aux->valor);

    aux=aux->prox;
  }
}

int main(void) {
  TLista L1=NULL, L2=NULL;

  printf("\n\t------------- LISTA 1 ---------------\n");
    inserir(&L1,5);
    inserir(&L1,4);
    inserir(&L1,2);
    inserir(&L1,2);
    inserir(&L1,3);
    inserir(&L1,1);
    exibir(L1);


  printf("\n\n\n\t------------- LISTA 2 ---------------\n");
    ListaSemRepet(L1,&L2);
    exibir(L2);
  
  
  return 0;
}