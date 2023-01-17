/*
REGRAS DE MANIPULAÇÃO DESSAS ESTRUTURAS:
- Pilha - só o topo é acessível
- Fila - Só o início e o fim são acessíveis

    ALTERAR EM PILHA
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

//implementação das funções
int empilhar (TLista *P, int numero){
	//declaração de variáveis;
	TLista aux;
	
	//1º passo: alocar memória para o novo nó	
	aux = (TLista) malloc (sizeof(TNo));
	
	//verificando se houve erro na alocação de memória
	if (aux == NULL){
		return FALSE;
	}	else {
		//2º passo: armazenar 'numero' na memória recém-alocada
		aux->valor = numero;
		
		//3º passo: mandar o campo 'prox' do novo nó apontar para o "até então" topo da pilha
		aux->prox = *P;
		
		//4º passo: fazer com que P aponte para o novo nó
		*P = aux;
		
		return TRUE;
	}	
}

int desempilhar (TLista *P, int *numero){
	//declaração de variáveis
	TLista aux;
	
	//verificando se a pilha está vazia
	if (!(*P))	{
		return FALSE;
	}	else	{
		//fazer o 'aux' apontar para o topo da pilha
		aux = *P;
		
		//atualizando o P, uma vez que o topo será removido	
		*P = aux->prox;   //ou   *P = (*P)->prox
		
		//armazenando em 'numero' o valor sendo removido
		*numero = aux->valor;
		
		//liberando o nó sendo removido
		free (aux);
		
		return TRUE;
	}
}

int topo (TLista P, int *t){
	//verificando se a pilha está vazia
	//if (P == NULL)
	if (!P)	{
		return FALSE;
	}	else {
		//armazenando em 't' o valor que encontra-se no topo da pilha
		*t = P->valor;
		
		return TRUE;
	}
}

void Auxiliar (TLista P, TLista *A){
  TLista au=NULL;
  int num;
  
  //Passando tudo de "P" para "au"
  while(P){
    topo(P,&num);
    empilhar(&au,num);
    desempilhar(&P,&num);
  }

  //Passando tudo de "au" para "A" - assim, "A" vira cópia de "P"
  while(au){
    topo(au,&num);
    empilhar(A,num);
    desempilhar(&au,&num);
  }
}

void Alterar (TLista *P, TLista A, int numero, int novo){
  TLista AUX=NULL;
  int n, n2;

  //Zerando a Pilha
  *P = NULL;

  //Passando tudo de A para AUX - criando P invertido
  while(A){
    topo(A,&n);
    empilhar(&AUX,n);
    desempilhar(&A,&n);
  }

  //Passando tudo de AUX para P
  while(AUX){
    topo(AUX,&n2);
    if(n2 == numero){
        empilhar(P,novo);
    }
    desempilhar(&AUX,&n2);
  }
}

int main(void) {
  TLista P=NULL, aux=NULL;
  int n, n2, n3, n4, numero=2, novo=8;

  empilhar(&P,5);
  empilhar(&P,4);
  empilhar(&P,3);
  empilhar(&P,2);//topo
  topo(P,&n);
  printf ("\n\tAntes - Topo da pilha: %d",n);//n=2

  Auxiliar (P,&aux);
  topo (aux,&n2);
  printf ("\n\tTopo da pilha Auxiliar: %d",n2);//n=2 

  Alterar(&P,aux,numero,novo);
  topo(P,&n3);
  printf ("\n\n\tDepois - Topo da pilha: %d",n3);//n=3
  
  
  return 0;
}

