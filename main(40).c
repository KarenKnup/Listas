/*
Pede-se o desenvolvimento de uma função que, dado 
um arquivo texto contendo números inteiros, um por 
linha, copie-os para uma lista encadeada, do tipo 
TLista, porém garantindo que nesta última estrutura 
não haverá repetição de elementos
*/

#include <stdio.h>
#include <stdlib.h>

//definição de constantes
#define TRUE 1
#define FALSE 0
  
typedef struct No {
	int valor;
  int pos;
	struct No* prox; 
} TNo;

typedef TNo* TLista; 

int inserir (TLista *L, int numero){
	TLista aux; 
  
	aux = (TLista) malloc (sizeof(TNo));

  TLista aux2=aux->prox;
  
	if (aux == NULL){ 
		return FALSE;
	}	else{
		aux->valor = numero; //aux->valor = *aux.valor
    
		aux->prox = *L;
		
		*L = aux;
		
		return TRUE;
	}
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

int buscar (TLista L, int numero){
	//declaração de variáveis
	TLista aux = L;
	
	//percorrendo a lista até o seu final
	while (aux != NULL)	{//while(aux)
		//testando se é o valor sendo buscado
		if (aux->valor == numero)	{
			return TRUE;
		}
			
		//atualizando o 'aux' para apontar para o próximo nó
		aux = aux->prox;
	}
	
	//se chegou a este ponto, o número buscado não existe
	return FALSE;	
}

int Lista (TLista *L, char nomeArq[]){
  FILE *arquivo;
  int n;
  TLista aux=*L;

  arquivo=fopen(nomeArq,"r");

  if(!arquivo){
    return FALSE;
  } else {
    while(fscanf(arquivo,"%d",&n)!=EOF){
      if(buscar(*L,n)==FALSE){
        inserir(L,n);
      }
    }  
  }
  
  return TRUE;
}

int main(void){
  TLista L=NULL;
  char nomeArq[50];

  printf("\nLer o arquivo: ");
  scanf(" %[^\n]",nomeArq);

  if(Lista(&L,nomeArq)==TRUE){
    printf("\n\tLista gerada com sucesso!");
    exibir(L);
  } else {
    printf("\n\tErro na criação da lista!");
  }

  return 0;
}
