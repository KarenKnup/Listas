#include <stdio.h>
#include <stdlib.h>

/*
  Dadas duas listas L1 e L2, ambas do tipo TLista, 
desenvolver uma função que determine se L2 é ou não 
uma sublista de L1.

Exemplo 1:
L1: 1 2 3 4 5 6
L2: 3 2 4 L2 não é uma sublista de L1

Exemplo 2:
L1: 1 2 3 4 5 6
L2: 5 6 7 L2 não é uma sublista de L1

Exemplo 3:
L1: 1 2 3 4 5 6
L2: 2 3 4 L2 é uma sublista de L1
*/

#define TRUE 0
#define FALSE 1

  //definição de tipos
typedef struct No { //struct No = TNo
	int valor;
	struct No* prox; //TNo ainda n foi declarada
} TNo;

typedef TNo* TLista; //para não precisar usar **

int inserir (TLista *L, int numero){  
	//declaração de variáveis;
	TLista aux; 

	//1º passo: alocar memória para o novo nó	
	aux = (TLista) malloc (sizeof(TNo)); 
	
	//verificando se houve erro na alocação de memória
	if (aux == NULL){ //if(!aux) ~~ não conseguiu alocar memória 
    //ponteiro NULL - indica que finalizou a lista
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
	if (L == NULL){ 
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

TLista busca (TLista L, int numero){
	//declaração de variáveis
	TLista aux = L;

	//percorrendo a lista até o final
	while (aux != NULL){
		//testando se é o valor sendo buscado
		if (aux->valor == numero){
		//retornando o endereço do nó que contém o valor buscado
			return aux->valor;
		}
	//atualizando o 'aux' para apontar para o próximo nó
	aux = aux->prox;
	}

//se chegou a este ponto, o número buscado não existe
	return NULL;
}


int Verifica(TLista L1, TLista L2){
  TLista aux=L1, aux2=L2;
  int n=busca(L1,L2->valor);

  while(aux){//Verifica a substring
    if(aux->valor == n){
      while(aux2){        
        if(aux2->valor != aux->valor){
          return FALSE;
        }

        aux2=aux2->prox;
        aux=aux->prox;
      }
    }

    aux=aux->prox;
  }

  while(aux2){//Verifica se tem em L2 algum número que não existe em L1
    if(busca(L1,aux2->valor)==NULL){
      return FALSE;
    }
    aux2=aux2->prox;
  }
  
  return TRUE;
}

int main(void) {
 TLista L1=NULL, L2=NULL, L3=NULL, L4=NULL;

  printf("\n\t-------- LISTA 1 ----------\n");
        inserir(&L1,1);
        inserir(&L1,2);
        inserir(&L1,3);
        inserir(&L1,4);
        inserir(&L1,5);
        inserir(&L1,6);
        exibir(L1);


    printf("\n\n\n\t-------- LISTA 2 ----------\n");
        inserir(&L2,3);
        inserir(&L2,2);
        inserir(&L2,4);
        exibir(L2);
  
    printf("\n\n\n\t-------- LISTA 3 ----------\n");
          inserir(&L3,5);
          inserir(&L3,6);
          inserir(&L3,7);
          exibir(L3);

    printf("\n\n\n\t-------- LISTA 4 ----------\n");
          inserir(&L4,2);
          inserir(&L4,3);
          inserir(&L4,4);
          exibir(L4);

   printf("\n\n\n\t-------- RESULTADO ----------\n");
      if(Verifica(L1,L2)==TRUE){
        printf("\n\t\tL2 é sublista de L1!");
      } else {
        printf("\n\t\tL2 NÃO é sublista de L1!");
      }

      if(Verifica(L1,L3)==TRUE){
            printf("\n\t\tL3 é sublista de L1!");
          } else {
            printf("\n\t\tL3 NÃO é sublista de L1!");
          }
    
      if(Verifica(L1,L4)==TRUE){
            printf("\n\t\tL4 é sublista de L1!");
          } else {
            printf("\n\t\tL4 NÃO é sublista de L1!");
          }
  
  return 0;
}