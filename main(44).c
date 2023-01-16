/*
Pede-se a descrição dos algoritmos que realizem a 
remoção de um determinado número inteiro (de todas 
as suas ocorrências) nas seguintes estruturas de dados:
    i. Em uma pilha;
    ii. Em uma fila.

REGRAS DE MANIPULAÇÃO DESSAS ESTRUTURAS:
- Pilha - só o topo é acessível
- Fila - Só o início e o fim são acessíveis

Observações: as regras de manipulação destas estruturas 
(implementação clássica) devem ser respeitadas. Ou seja, 
apenas o topo é acessível na pilha, assim como os 
elementos extremos da fila (em um lado, remoção; no 
outro, inserção). Caso alguma estrutura de dados 
auxiliar seja necessária, deverá obrigatoriamente ser 
uma pilha ou uma fila.

      REMOÇÃO EM FILA  
  */

#include <stdio.h>
#include <stdlib.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//definição de tipos
typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;

int enfilar (TLista *F, TLista *U, int numero){
	//declaração de variáveis;
	TLista aux;
	
	aux = (TLista) malloc (sizeof(TNo));
	
	if (aux == NULL){
		return FALSE;
	} else {
		aux->valor = numero;
		
		aux->prox = NULL;
		
		if (*U){
			(*U)->prox = aux;
		}else{
			*F = aux;
		}
	
		*U = aux;
		
		return TRUE;
	}	
}

int desenfilar (TLista *F, TLista *U, int *numero){
	TLista aux;
	
	if (!(*F)){
		return FALSE;
	}else{
		if (*F == *U){
			*U = NULL;
		}
		
		aux = *F;
		
		*F = aux->prox;   
		
		*numero = aux->valor;
		
		free (aux);
		
		return TRUE;
	}
}

int primeiro (TLista F, int *p){
	if (!F){
		return FALSE;
	}else{
		*p = F->valor;
		
		return TRUE;
	}
}

void Remove (TLista *L, TLista *U, int n){
   TLista aux_L=NULL, aux_U=NULL;

  //Criando uma cópia da Lista - aux
  while(*L){
      enfilar(&aux_L,&aux_U,(*L)->valor);
      desenfilar(L,U,&(*L)->valor);
    }

  //*L e *U esvaziados - inserir novamente os valores do aux que não forem "n", porém começando no fim
  TLista aux1=*L, aux2=*U;
  
  while(aux_L){
    if(aux_U->valor != n){
       enfilar(L,U,aux_U->valor);
    }
    desenfilar(&aux_L,&aux_U,&aux_U->valor);
  }  
}

int main(void) {
  TLista F=NULL, U=NULL;
  int num=2;

  enfilar(&F,&U,5);//F->valor ~~~primeiro
  enfilar(&F,&U,4);
  enfilar(&F,&U,3);
  enfilar(&F,&U,2);//U->valor ~~~ último
  printf ("\n\tAntes - Último elemento da fila: %d", U->valor);

  Remove(&F,&U,num);
  printf ("\n\tDepois - Último elemento da fila: %d", U->valor);
  
  
  return 0;
}