
#include <stdio.h>
#include <stdlib.h>

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

//----------------------------------------------------

void funcao01 (TLista *L){//aponta para o o fim da lista, ou seja, esvazia a lista 
  *L=NULL; //(*) ~ indica que a Lista será alterada na main
}

void funcao02 (TLista *L){//o primeiro nó é removido da lista
  free(*L);
}

void funcao03 (TLista *L){ //enquanto a lista existir (diferente de NULL), cada elemento da lista (do começo adiante) serão removidos (os nós) com a ajuda do aux
  TLista aux;

  /* while(!aux)
    ->aux=NULL
    ->Não alocou memória para o aux */
  
    while(*L){ //while( (*L)!=NULL )
      aux=*L;
      *L=(*L)->prox;
      free(aux);
    }
}

void funcao04 (TLista *L){//enquanto a lista existir (diferente de NULL), os nós (elementos) serão removidos de trás para frente
  if(*L){
    funcao04(&((*L)->prox));
    free(*L);
    *L=NULL;
  }
}

int main(void) {
 TLista L1=NULL, L2=NULL, L3=NULL, L4=NULL; //todas essas 4 funções são formas de esvaziar ("destruir") uma lista 

  printf("\n---------- FUNCAO 01 -----------------\n");
    inserir(&L1,6);
    inserir(&L1,5);
    inserir(&L1,4);
    inserir(&L1,3);
    exibir(L1);
  
    funcao01(&L1);
    exibir(L1);

  printf("\n\n---------- FUNCAO 02 -----------------\n");
    inserir(&L2,6);
    inserir(&L2,5);
    inserir(&L2,4);
    inserir(&L2,3);
    exibir(L2);

    funcao02(&L2);
    exibir(L2);

  printf("\n\n---------- FUNCAO 03 -----------------\n");
    inserir(&L3,6);
    inserir(&L3,5);
    inserir(&L3,4);
    inserir(&L3,3);
    exibir(L3);

    funcao02(&L3);
    exibir(L3);

  printf("\n\n---------- FUNCAO 04 -----------------\n");
    inserir(&L4,6);
    inserir(&L4,5);
    inserir(&L4,4);
    inserir(&L4,3);
    exibir(L4);

    funcao02(&L4);
    exibir(L4);
  
  return 0;
}
