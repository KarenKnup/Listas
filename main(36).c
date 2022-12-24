/*
Fazer uma função que, dadas duas listas encadeadas L1 e L2, ambas do tipo TLista e com quant elementos, determine se elas possuem os mesmos valores, porém na ordem inversa
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
  
  if(qtde1 == qtde2){
    return TRUE;
  } else {
    return FALSE;
  }
}

void Inverter (TLista *L){//*L - lista que quer inverter
  TLista Aux=NULL, aux2=*L;
  int n, quant=1;
  
  while(aux2){
    n=inserir(&Aux,aux2->valor, quant);
    quant++;
      if(n==TRUE){
        aux2=aux2->prox;
      } else {
        break;
      }
  }
  TLista aux3=*L;
  while(Aux){
    aux3->valor = Aux->valor;
    Aux=Aux->prox;
    aux3=aux3->prox;
  }
}

int ComparaListas (TLista L1, TLista L2){
  if(ComparaQtde(L1,L2)==FALSE){
    printf("\n\tAs listas possuem quantidades de elementos diferentes!");
    return FALSE;
  } else {
    Inverter(&L1);

    while(L1){
      if(L1->valor != L2->valor){
        return FALSE;
      }

      L1=L1->prox;
      L2=L2->prox;
    }

    Inverter(&L1);
    return TRUE;
  }
}

int main(void){
TLista L1=NULL, L2=NULL;
  int quant=1, quant2=1;

  printf("\n----------- LISTA 1 ----------------------\n");
  inserir(&L1,6,quant);
  quant++;
    inserir(&L1,8,quant);
  quant++;
    inserir(&L1,2,quant);
  quant++;
    exibir(L1);

    printf("\n\n\n----------- LISTA 2 ----------------------\n");
  inserir(&L2,2,quant2);
  quant2++;
    inserir(&L2,8,quant2);
  quant2++;
    inserir(&L2,6,quant2);
  quant2++;
    exibir(L2);

  if (ComparaListas(L1,L2)){
    printf("\n\n\tAs listas possuem os mesmos valores na ordem inversa!");
  } else {
    printf("\n\n\tAs listas são diferentes!");
  }
    
  return 0;
}