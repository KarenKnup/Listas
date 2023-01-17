/*
REGRAS DE MANIPULAÇÃO DESSAS ESTRUTURAS:
- Pilha - só o topo é acessível
- Fila - Só o início e o fim são acessíveis

    ALTERAR EM FILA
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

void Alterar (TLista *F, TLista *U, TLista Aux_F, TLista Aux_U, int n, int novo){
  //Zerando F e U
  while(*U){
    desenfilar(F,U,&(*F)->valor);
  }

  //Removendo "n" passando por valores do Auxiliar
 while(Aux_F){
  if(Aux_F->valor != n){
    enfilar(F,U,Aux_F->valor);
  } else {
    enfilar(F,U,novo);
  }
   desenfilar(&Aux_F,&Aux_U,&Aux_F->valor);
 }
}

int main(void) {
  TLista F=NULL, U=NULL, Aux_F=NULL, Aux_U=NULL;
  int num=2, novo=8;

  enfilar(&Aux_F,&Aux_U,5);//Auxiliar - cópia de F e U ~~ primeiro
  enfilar(&F,&U,5);
  enfilar(&Aux_F,&Aux_U,4);
  enfilar(&F,&U,4);
  enfilar(&Aux_F,&Aux_U,3);
  enfilar(&F,&U,3);
  enfilar(&Aux_F,&Aux_U,2); //último
  enfilar(&F,&U,2);
  
  printf ("\n\tAntes - Primeiro elemento da fila: %d", F->valor);
  printf ("\n\tDepois - Último elemento da fila: %d ", U->valor);


  Alterar(&F,&U,Aux_F,Aux_U,num,novo);
  printf ("\n\n\tAntes - Primeiro elemento da fila: %d", F->valor);
  printf ("\n\tDepois - Último elemento da fila: %d ", U->valor);
  
  
  return 0;
}