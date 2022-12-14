#include <stdio.h>
#include <stdlib.h>

/*
Fazer uma função que, dada uma lista encadeada L, do tipo TLista, e duas posições p1 e p2, remova todos os elementos de L existentes entre estas posições.
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

int remover (TLista *l, int p1, int p2){
  TLista aux1;
  TLista aux2;
  int cont = 1;
  aux1 = *l;
  aux2 = (*l) -> prox;

  if ( (p2 < p1) || (p1 < 1) || (p2 < 1) ){
    return FALSE;
  }

  while ( aux1 -> prox ){
    aux1 = aux1 -> prox;
    cont++;
  }
  
  if (cont < p2){
    return FALSE;
  }

  aux1 = *l;
  cont = 1;  //talvez mudar depois para excluir inclusivo
  
    while (cont < p1-1){
      aux1 = aux1 -> prox;
      cont++;
    }
    while (cont < p2){
      aux2 = aux1 -> prox;
      aux1 -> prox = aux2 -> prox;
      free(aux2);
      aux2 = aux1 -> prox;
      cont++;
    }
  
  
  return TRUE;

}

int main(void) {
  TLista L=NULL;

   printf("\n------------ LISTA 1 --------------\n");
    inserir(&L,6);
    inserir(&L,5);
    inserir(&L,4);
    inserir(&L,3);
    inserir(&L,2);
    inserir(&L,1);

    exibir(L);

 printf("\n\n\n------------ Invertida --------------\n");
    remover(&L,2,4);
    exibir(L);
  
  return 0;
}