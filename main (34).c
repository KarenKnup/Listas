/*
FILA INVERTIDA
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
	
	//1º passo: alocar memória para o novo nó	
	aux = (TLista) malloc (sizeof(TNo));
	
	//verificando se houve erro na alocação de memória
	if (aux == NULL){
		return FALSE;
	} else {
		//2º passo: armazenar 'numero' na memória recém-alocada
		aux->valor = numero;
		
		//3º passo: fazer com que o campo 'prox' do novo nó aponte para NULL
		aux->prox = NULL;
		
		if (*U){
			//4º passo: fazer o "antigo último nó" apontar para o novo nó
			(*U)->prox = aux;
		}else{
			//Fazer o 'F' apontar para o novo nó (que é o primeiro da fila)
			*F = aux;
		}
	
		//5º passo: fazer o 'U' apontar para o novo nó
		*U = aux;
		
		return TRUE;
	}	
}

int desenfilar (TLista *F, TLista *U, int *numero)
{
	//declaração de variáveis
	TLista aux;
	
	//verificando se a fila está vazia
	if (!(*F)){
		return FALSE;
	}else{
		//verificando se a lista possui apenas um nó
		if (*F == *U){
			*U = NULL;
		}
		
		//fazer o 'aux' apontar para o primeiro elemento da fila
		aux = *F;
		
		//atualizando o F, uma vez que o primeiro será removido	
		*F = aux->prox;   //ou   *F = (*F)->prox
		
		/*
		if (*F == NULL)
		{
			*U = NULL;
		}	
		*/
		
		//armazenando em 'numero' o valor sendo removido
		*numero = aux->valor;
		
		//liberando o nó sendo removido
		free (aux);
		
		return TRUE;
	}
}

int primeiro (TLista F, int *p){
	//verificando se a fila está vazia
	//if (F == NULL)
	if (!F){
		return FALSE;
	}else{
		//armazenando em 'p' o primeiro valor da fila
		*p = F->valor;
		
		return TRUE;
	}
}

void Inverte (TLista *L, TLista *U){
  TLista aux1=*L, aux2=*U;
  int temp;

  if((aux1->prox)!=(aux2->prox)){
    if(aux2->prox == NULL){
        temp=aux1->valor;
        aux1->valor = aux2->valor;
        aux2->valor=temp;
      
      aux1=aux1->prox;
      } else {
      Inverte(L, &(aux2->prox));
        temp=aux1->valor;
        aux1->valor = aux2->valor;
        aux2->valor=temp;
      aux1=aux1->prox;
      aux2=NULL;
      }
  }
}

int main(void) {
 TLista F=NULL, U=NULL;
  //F - aponta para o começo da fila
  //U - aponta para o final da fila
  int p, p2;

  enfilar(&F,&U,5);//F->valor ~~~primeiro
  enfilar(&F,&U,4);
  enfilar(&F,&U,3);
  enfilar(&F,&U,2);//U->valor ~~~ último
  primeiro(F,&p);
  printf ("\n\tAntes - Primeiro elemento da fila: %d", p);
  
  Inverte(&F,&U);
  primeiro(F,&p2);
  printf ("\n\tDepois - Primeiro elemento da fila: %d", p2);
  
  
  return 0;
}