#include <stdio.h>
#include <stdlib.h>

/*
Dadas duas listas encadeadas L1 e L2, ambas do 
tipo TLista, ordenadas crescentemente e sem 
repetição de elementos, criar uma terceira lista 
L3, contendo todos os elementos de L1 e L2. 
Como as duas originais, a nova lista deve ter 
seus elementos ordenados crescentemente, e 
sem repetição de valores.
  */

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

void CriaL3 (TLista L1, TLista L2, TLista *L3){
  TLista aux=L1, aux2=L2, aux3=*L3;

  while(aux && aux2){
    inserir(L3,aux->valor);
    inserir(L3,aux2->valor);

    aux=aux->prox;
    aux2=aux2->prox;
  }
}

int main(void) {
  TLista L1=NULL, L2=NULL, L3=NULL;

  printf("\n------------- LISTA 1 ---------------");
  inserir(&L1,1);
  inserir(&L1,2);
  inserir(&L1,3);
  inserir(&L1,4);
  inserir(&L1,5);
  exibir(L1);

  printf("\n\n\n------------- LISTA 2 ---------------");
  inserir(&L2,6);
  inserir(&L2,7);
  inserir(&L2,8);
  inserir(&L2,2);
  exibir(L2);

  printf("\n\n\n------------- LISTA 3 ---------------");
  CriaL3(L1,L2,&L3);
  exibir(L3);
  
  return 0;
}