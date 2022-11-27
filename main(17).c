
/*
Desenvolver uma função que insira um número inteiro N na i-ésima posição de uma lista encadeada L.

Observação: caso a posição i informada seja inválida, a função deverá retornar o valor 0; caso contrário, o retorno será igual a 1.
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

void InserirComeco(TLista *L, int numero, TLista *aux1)
{
  TLista novo;
  novo = (TLista) malloc(sizeof(TNo));

  novo->valor = numero;
  novo->prox = *L;
  *L = novo;
  *aux1 = novo;
}

void InserirAqui(TLista *L, int numero, TLista *aux1, TLista *aux2)
{
  TLista novo;
  novo = (TLista) malloc(sizeof(TNo));
  
  novo->valor = numero;
  novo->prox = *aux1;
  (*aux2)->prox = novo;
}


void InserirPosicaoLista(TLista *L, int numero, int posicao)
{
  TLista aux1,aux2;
  int cont = 1;
  
  aux1 = *L;
  
  while(aux2)
  {
    if(cont == posicao)
    {
        if(posicao == 1)
        {
          printf("\nPosicao: %d, Numero: %d", posicao, numero);
          InserirComeco(L, numero, &aux1);
        }
        else if(posicao == cont)
        {
          printf("\nPosicao: %d, Numero: %d", posicao, numero);
          InserirAqui(L, numero, &aux1, &aux2);
        }
    }
    cont++;
    aux2 = aux1;
    aux1 = aux1->prox;
  }
}

int main(void) {
//declaração de variáveis
	TLista L = NULL;
  int n, pos;

  inserir(&L, 1);
  inserir(&L, 2);
  inserir(&L, 3);
  exibir(L);

  printf("\n------------------------------------\n");
  printf("Entre com o valor a ser inserido: ");
  scanf("%d",&n);
  printf("Posição desejada: ");
  scanf("%d",&pos);

  InserirPosicaoLista(&L,n,pos);
  exibir(L);
  
  return 0;
  }