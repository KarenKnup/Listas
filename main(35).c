/*
INVERTE ELEMENTOS DE LISTA ATÉ A METADE

Lista:       2 3 4 5
Invertida:   3 2 5 4
  */

#include <stdio.h>
#include <stdlib.h>

//definição de constantes
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

void troca(int *a, int *b) {
  int k = *a;
  *a = *b;
  *b = k;
}

void trocaListaRec(TLista aux1, TLista aux2) {
  if (aux2) {
    troca(&(aux1->valor), &(aux2->valor));
    if (aux1->prox && aux2 -> prox){
      trocaListaRec(aux2->prox, (aux2->prox)->prox);
    }
  }
}

void questao3(TLista L) { trocaListaRec(L, L->prox); }

int main(void){
TLista L1=NULL;
  
    inserir(&L1,5);
    inserir(&L1,4);
    inserir(&L1,3);
    inserir(&L1,2);
    exibir(L1);
  
  questao3(L1);
  exibir(L1);
  
  return 0;
}