/*
Verifica se os elementos da lista L2 são os mesmos da lista L1, porém embaralhados.
  */

#include <stdio.h>
#include <stdlib.h>

//definição de constantes
#define TRUE 1
#define FALSE 0
  
typedef struct No {
	int valor;
  int quant;
	struct No* prox; 
} TNo;

typedef TNo* TLista; 

int inserir (TLista *L, int numero, int n){
	TLista aux; 
  
	aux = (TLista) malloc (sizeof(TNo));

  TLista aux2=aux->prox;
  
	if (aux == NULL){ 
		return FALSE;
	}	else{
		aux->valor = numero; //aux->valor = *aux.valor
    
      aux->quant=n;
     
    
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

int ComparaQtde (TLista L1, TLista L2){
  int qtde1=L1->quant, qtde2=L2->quant;

  /* CONTADOR DE QUANTIDADES DE ELEMENTOS (sem "pos")

qtde1=0;
while(L1){
  qtde1++;

L1=L1->prox;
}

qtde2=0;
while(L2){
  qtde2++;

L2=L2->prox;
}

    */
  
  if(qtde1 == qtde2){
    return TRUE;
  } else {
    return FALSE;
  }
}

int busca (TLista L, int n){
  int qtde=0;
  while(L){
    if(L->valor == n){
      qtde++;
    }

    L=L->prox;
  }

  return qtde;
}

int ComparaListas (TLista L1, TLista L2){
  TLista aux=L1, aux2=L2;
  int qtde=0;

  if(ComparaQtde(L1,L2)==FALSE){
    printf("\n\tAs listas possuem quantidades de elementos diferentes!");
    return FALSE;
  } else {
    //Verifica a qtde de cada elemento de L1 em L2
    while(aux){
      if(busca(L1,aux->valor) != busca(L2,aux->valor)){
        return FALSE;
      } 

      aux=aux->prox;
    }
    return TRUE;
    
      //Verificando se são iguais
    while(aux){
      while(aux2){
        if(aux->valor == aux2->valor){
          return TRUE;
        }

        aux2=aux2->prox;
      }
      aux=aux->prox;
    }

    return FALSE;
  }
}

int main(void){
TLista L1=NULL, L2=NULL;
  int quant=1, quant2=1;

  printf("\n----------- LISTA 1 ----------------------\n");
  inserir(&L1,2,quant);
  quant++;
    inserir(&L1,3,quant);
  quant++;
    inserir(&L1,4,quant);
  quant++;
  inserir(&L1,5,quant);
  quant++;
  inserir(&L1,6,quant);
  quant++;
    exibir(L1);

    printf("\n\n\n----------- LISTA 2 ----------------------\n");
  inserir(&L2,2,quant2);
  quant2++;
    inserir(&L2,4,quant2);
  quant2++;
    inserir(&L2,3,quant2);
  quant2++;
    inserir(&L2,6,quant2);
  quant2++;
    inserir(&L2,5,quant2);
  quant2++;
    exibir(L2);

  if (ComparaListas(L1,L2)){
    printf("\n\n\tAs listas possuem os mesmos valores!");
  } else {
    printf("\n\n\tAs listas são diferentes!");
  }
    
  return 0;
}