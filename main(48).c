/*
  Fazer uma função que, dada uma lista encadeada L, do
tipo TLista, remova as repetições de elementos em L,
de forma que cada valor presente originalmente na
lista passe a figurar nela apenas uma vez.
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

int remover (TLista *L, int numero){
	//declaração de variáveis
	TLista aux1, aux2;
	int cont = 0; //quantidade de remoções feitas
	
	//verificando se o primeiro elemento da lista é o número que deseja-se remover
	while ((*L) && ((*L)->valor == numero))	{
		//fazendo o aux1 apontar para o primeiro elemento da lista
		aux1 = *L;
		
		//fazer o L apontar para o "segundo" elemento da lista
		*L = aux1->prox;     //*L = (*L)->prox;
		
		//liberando a memória do nó apontado por 'aux1'
		free (aux1);
		
		//atualizando o número de remoções realizadas
		cont++;
	}
	
	//verificando se ainda há elementos na lista
	if (*L)	{
		//colocando os auxiliares 'aux2' e 'aux1' no primeiro e segundo nós, respectivamente
		aux2 = *L;
		aux1 = (*L)->prox;	
		
		//percorrendo a lista com 'aux1'
		while (aux1){
			//verificando se o 'aux1' está apontando para 'numero'
			if (aux1->valor == numero){
				//removendo o valor apontado por 'aux1'
				aux2->prox = aux1->prox;
				
				//removendo o nó que guarda o 'numero'
				free (aux1);
				cont++;
				
				//fazendo 'aux1' apontar para o próximo elemento da lista
				aux1 = aux2->prox;				
			} else {
				//andando com os dois auxiliares
				aux2 = aux1;
				aux1 = aux1->prox;
			}
		}
	}
	
	//retornando a quantidade de remoções realizadas
	return cont;
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

void ListaSemRepet (TLista *L){
  TLista aux=*L, temp=NULL;

  while(aux){
    inserir(&temp,aux->valor);
    
    aux=aux->prox;
  }

  *L=NULL;

  while(temp){
    if(buscar(*L,temp->valor)==FALSE){
      inserir(L,temp->valor);
    }

    temp=temp->prox;
  }
}

int main(void) {
  TLista L=NULL;

  printf("\n----------- ANTES ------------");
  inserir(&L,1);
  inserir(&L,2);
  inserir(&L,2);
  inserir(&L,3);
  inserir(&L,3);
  inserir(&L,3);
  exibir(L);

 printf("\n\n----------- DEPOIS ------------");
  ListaSemRepet(&L);
  exibir(L);

  
  
  
  return 0;
}