/*
Desenvolver uma função que, dadas duas listas
encadeadas L1 e L2, do tipo TLista, determine a
quantidade de elementos que elas têm em comum (de
forma que um mesmo número não seja contabilizado
mais de uma vez).
*/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

  //definição de tipos
typedef struct No { //struct No = TNo
	int valor;
	struct No* prox; //TNo ainda n foi declarada
} TNo;

typedef TNo* TLista; //para não precisar usar **

//implementação das funções
int inserir (TLista *L, int numero){//(*)Ou seja, pode alterar tudo que estiver em TLista
  /*
1° Alocar memória p o novo elemento com um aux
2° Armazenar o elemento novo no novo nó
3° Armazenar no campo prox do novo nó o endereço daquele que, até então, era o primeiro elemento
4° Fazer o L apontar para o novo nó
*/
  
	//declaração de variáveis;
	TLista aux; 
//aux: endereço do nó que armazena o 10 (primeiro valor)
//aux-> : o nó que armazena o valor 10

	
	//1º passo: alocar memória para o novo nó	
	aux = (TLista) malloc (sizeof(TNo));
  //malloc (alloc.h) - comando em C p alocar memória- memory allocation - ele dá como retorno um (*void) ponteiro void, um valor indeterminado que n sabe praq vai usar, por isso se acompanha pela Tlista

//sizeof-diz quantos bytes ocupa 
	
	//verificando se houve erro na alocação de memória
	if (aux == NULL){ //if(!aux) ~~ não conseguiu alocar memória 
    //ponteiro NULL - indica que finalizou a lista
		return FALSE;
	}	else{
    //1°passo OK
    //Inserindo o valor 
		//2º passo: armazenar 'numero' na memória recém-alocada
		aux->valor = numero; //aux->valor = *aux.valor
		
		//3º passo: mandar o campo 'prox' do novo nó apontar para o "até então" primeiro elemento	da lista (Fazendo o novo apontar para o antigo primeiro nó)
		aux->prox = *L;
		
		//4º passo: fazer com que L aponte para o novo nó da lista		
		*L = aux;
		
		return TRUE;
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

int Verifica (TLista L, TLista U){//todos distintos
  TLista aux=U;
  int cont=0;

  //percorrendo a lista até o seu final
  while(L != NULL){//while(L)
    if (buscar(L,aux->valor)==TRUE){
      cont++;
    }
      //atualizando o 'aux' para apontar para o próximo nó
  		aux = aux->prox;
    //atualizando L
    L = L->prox;
  }

	return cont;	
}

int main (void){
TLista L=NULL, U=NULL;

  inserir(&L,1);
  inserir(&L,2);
  inserir(&L,3);
  exibir(L);
  printf("\n---------------\n");
  inserir(&U,1);
  inserir(&U,2);
  inserir(&U,6);
  exibir(U);
  printf("\n---------------\n");
  printf("\n\tAs listas têm %d elementos em comum.",Verifica(L,U));

  
	return 0;
}
  