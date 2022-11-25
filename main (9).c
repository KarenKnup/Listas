/*
Desenvolver uma função que, dado um
vetor com quant números inteiros, crie
uma lista encadeada L, do tipo TLista,
contendo os números do vetor ordenados
CRESCENTEMENTE e SEM repetição.

Nota: os elementos do vetor devem ser
transferidos diretamente para a lista; ou
seja, nenhuma estrutura auxiliar deve ser
utilizada, assim como os elementos
originais do vetor devem ser preservados.
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

int buscar (TLista L, int numero){//busca crescente
	//declaração de variáveis
	TLista aux = L;
	
	//percorrendo a lista até o seu final
	while (aux != NULL)	{//while(aux)
		//testando se é o valor sendo buscado
		if ((aux->valor == numero) || (aux->valor < numero))	{
			return TRUE;
		}
			
		//atualizando o 'aux' para apontar para o próximo nó
		aux = aux->prox;
	}
	
	//se chegou a este ponto, o número buscado não existe
	return FALSE;	
}

void inserir(TLista *L, int numero){
    //declaração de variáveis;
  TLista aux, aux1, aux2;

  //verificando se o elemento não existe na lista
  if(buscar(*L, numero)==FALSE){ //elemento não existe
    if((*L == NULL) || ((*L)->valor > numero)){ //lista vazia --- deve ser crescente
    		//1º passo: alocar memória para o novo nó	
      aux = (TLista) malloc(sizeof(TNo));
       //2º passo: armazenar 'numero' na memória recém-alocada
      aux->valor = numero;
  			//3º passo: mandar o campo 'prox' do novo nó apontar para o "até então" primeiro elemento	da lista
      aux->prox = *L;
    	//4º passo: fazer com que L aponte para o novo nó da lista		
      *L = aux;
     }
    } else { //elemento já existe na lista     
    aux = *L;
    aux1 = (*L)->prox;    
      while(aux != NULL){ //'aux' vai andar pela lista
        if(aux->valor > numero){
          //1º passo: alocar memória para o novo nó
          aux2 = (TLista) malloc(sizeof(TNo));
          //2º passo: armazenar 'numero' na memória recém-alocada
          aux2->valor = numero;
          //o próximo nó de 'aux2' vira 'aux'
          aux2->prox = aux;
          //o próximo nó de 'aux1' vira 'aux2'
          aux1->prox = aux2;
        }
        
    //atualizando o 'aux' para apontar para o próximo nó
      aux = aux1->prox;
      aux1 = aux1->prox;
    }
    //Quando 'aux' chega em NULL -- atualiza aux2
      aux2 = (TLista) malloc(sizeof(TNo));       
      aux2->valor = numero;
      aux2->prox = NULL;
      aux->prox = aux2;    
  }
}

void inserirAux(TLista *L, int quant, int v[quant]) {
  // declaração de variável
  int i;

  for (i=0; i<quant; i++) {
      // Chamar uma função para inserir esse número na lista
      inserir(L , v[i]); 
  }
}

void exibir (TLista L){
	//declaração de variáveis
	TLista aux = L;
	
	//testando se a lista está vazia
	if (L == NULL){ 
		printf ("\nLista vazia!");
	}	else	{
		printf ("\n---------- Elementos da lista: ----------\n");
		
		//percorrendo a lista até o seu final
		while (aux != NULL)	{
			//exibindo o valor apontado pelo 'aux'
			printf ("Valor do nó: %d\n", aux->valor);
			
			//atualizando o 'aux' para apontar para o próximo nó
			aux = aux->prox;
		}
	}
}

int main(void) {
TLista L=NULL;
  int quant=5;
 int v[]={5,4,3,2,1};

 inserirAux(&L, quant, v);

  exibir(L);
  
    return 0;
}