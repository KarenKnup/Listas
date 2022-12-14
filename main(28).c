#include <stdio.h>
#include <stdlib.h>

/*
Dada uma lista encadeada L, do tipo TLista, desenvolver uma função que exiba seus elementos na ordem inversa. Ou seja, se o ponteiro L estiver apontando para um nó que contém o valor 10, o 10 será o último a ser exibido pela função.
*/

#define TRUE 0
#define FALSE 1

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

void Inverte (TLista L){
   TLista aux;
  TLista parada = NULL;
  int cont = 0;
  int voltas;
  aux = L;

  if (aux == NULL){
    printf("Lista Vazia!");
  }
  else{
    while(aux){
      cont++;
      aux = aux -> prox;
    }
    
    printf ("\nElementos da lista: ");
    while (cont != 0){
      aux = L;
      voltas = 1;
      while (voltas < cont){
        aux = aux -> prox;
        voltas++;
      }
      printf("%d ", aux -> valor);
      cont--;
    }
  }
}

int main(void) {
  TLista L=NULL;

   printf("\n------------ LISTA 1 --------------\n");
    inserir(&L,8);
    inserir(&L,4);
    inserir(&L,2);
    exibir(L);

 printf("\n\n\n------------ Invertida --------------\n");
    Inverte(L);

 
  
  return 0;
}