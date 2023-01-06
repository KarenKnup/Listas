/*
Implementar uma função que tenha como parâmetros 
uma lista encadeada do tipo TLista e uma posição p
(considerando que o primeiro nó da lista está na 
posição p = 0). A função deverá buscar o menor 
elemento da posição p ao final da lista.
Se este menor elemento estiver em uma posição p2 que seja diferente 
de p, os conteúdos desses dois nós deverão ser 
trocados. 

Nota: Se o valor de p for inválido, a função deverá retorna 0; 
caso contrário, fará o proposto e, em seguida, retornará 1.

     busca --->
num:  3 6 6 2 5 - menor:2
pos:  4 3 2 1 0
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

int inserir (TLista *L, int numero, int p){
	TLista aux; 
  
	aux = (TLista) malloc (sizeof(TNo));

  TLista aux2=aux->prox;
  
	if (aux == NULL){ 
		return FALSE;
	}	else{
		aux->valor = numero; //aux->valor = *aux.valor
    aux->pos = p;
    
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

int VerificaMenor (TLista L, int num){
  while(L){
    if(L->valor < num){
      return FALSE;
    }
    
    L=L->prox;
  }
  return TRUE;
}

int PosMenor (TLista L){
  TLista aux=L, aux2=L->prox;
  int p;
  
  while(aux2){
    if(aux->valor < aux2->valor){
      p=aux->pos;
    }

    aux=aux->prox;
    aux2=aux2->prox;
  }

  return p;
}

void Inverte (TLista *L, int p, int p2){//inverte os números de 2 posicoes
  TLista aux=*L, aux2=*L;
  int temp;

  while(aux){
    if(aux->pos == p){
      while(aux2){
        if(aux2->pos == p2){
          temp=aux->valor;
          aux->valor=aux2->valor;
          aux2->valor=temp;
        }

        aux2=aux2->prox;
      }
    }

    aux=aux->prox;
  }
}

int buscaMenor (TLista L, int *posicao, int p){
  TLista aux=L, aux2;
  //num:  3 6 6 2 5 - menor:2
  //pos:  4 3 2 1 0

  if (PosMenor(L) > p){
      Inverte(&L,p,PosMenor(L));
      exibir(L);
    }
  
  while (aux){    
    if(aux->pos == p){
      aux2=aux;
      while(aux2){
          if(VerificaMenor(L,aux2->valor)==TRUE){
            (*posicao)=aux2->pos;
            return aux2->valor;
          } 

        aux2=aux2->prox;
      }
    }

    aux=aux->prox;
  }  
}

/* void Pos (TLista *L){
num:  3 6 6 2 5 - menor:2
pos:  0 1 2 3 4
  TLista aux=L;
  int p=0;

  while(aux){
    aux->pos=p;
    p++;
  
  aux=aux->prox;
  }
  
} */

int Verifica_p (TLista L, int p){
  while (L){
    if(L->pos == p){
      return TRUE;
    }

    L=L->prox;
  }
  return FALSE;
}

int main(void){
  TLista L=NULL;
  int pos=0, posicao, p;

  inserir(&L,5,pos);
  pos++;
  inserir(&L,2,pos);
  pos++;
  inserir(&L,6,pos);
  pos++;
  inserir(&L,6,pos);
  pos++;
  inserir(&L,3,pos);
  exibir(L);
   
  printf("\n\n------------- RESULTADO -----------\n");
  printf("\nBuscar a partir da posição: ");
  scanf("%d",&p);
  if(Verifica_p(L,p)==TRUE){
  printf("\n\tO menor número é %d e está na posição %d",buscaMenor(L,&posicao,p),posicao);
    } else {
    printf("\n\tValor de p inválido.");
    }

  return 0;
}