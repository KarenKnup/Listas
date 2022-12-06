/*
Dada uma lista encadeada L1, do tipo TLista, cujo
primeiro nó está na posição 1, implementar uma
função que crie uma lista encadeada L2 consistindo em
uma sublista de L1, contendo n nós a partir da posição
p da primeira lista.


    Notas:
1. Caso a posição p não exista na lista L1, o valor 0
deverá ser retornado e a sublista L2 não será
criada;
2. Caso o valor de n não seja positivo, o valor 0
deverá ser retornado e a sublista L2 não será
criada;
3. Se a partir da posição p não existirem n nós, a
sublista L2 consistirá em todos os nós de L1 da
posição p de L1, até o seu final;
4. Sempre que a lista L2 puder ser criada, o valor 1
deverá ser retornado.
*/

#include <stdio.h>
#include <stdlib.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//definição de tipos
typedef struct No { //struct No = TNo
	int valor;
	struct No* prox; 
  int pos;
} TNo;

typedef TNo* TLista; //para não precisar usar **

int inserir (TLista *L, int numero){
	//declaração de variáveis;
	TLista aux;
	
	//1º passo: alocar memória para o novo nó	
	aux = (TLista) malloc (sizeof(TNo));
  
	//verificando se houve erro na alocação de memória
	if (aux == NULL){ //if(!aux) ~~ não conseguiu alocar memória 
		return FALSE;
	}	else{
    
		aux->valor = numero; //aux->valor = *aux.valor
		
		aux->prox = *L;
		
		*L = aux;
		
		return TRUE;
	}
}

void pos (TLista *L1){
  TLista aux=*L1;
  int p=1;
  
  while(aux!=NULL){
    aux->pos=p;
    p++;
    aux=aux->prox;
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

int Func (TLista L1, TLista *L2, int n, int p){
  TLista aux;

  while(L1!=NULL){
    if(p==L1->pos){
      while(n>=0){
       //printf("%d ",L1->pos);
       aux = (TLista) malloc (sizeof(TNo));

        if(!aux){
          return FALSE;
        } else { //inserir elemento
          aux->valor=(L1->valor);
          aux->prox=*L2;
          *L2=aux;
        }
        
        L1=L1->prox;
        n--;
      }
      break; //terminou o while, não precisa continuar
    }
    L1=L1->prox;
  }

  return TRUE;
}

void Inverte (TLista *L) {//Inverte valores da lista
    TLista ant = NULL;
    TLista aux = *L;
    TLista prox;

    while (aux != NULL) {
        prox = aux->prox;
        aux->prox = ant;
        ant = aux;
        aux = prox;
    }
    *L = ant;
}

int Verificap(TLista L1, int p){
  while(L1){
    if(L1->pos == p){
      return TRUE;
    }
    L1=L1->prox;
  }
  return FALSE;
}

int qtdeElementosLista(TLista L1){
  int cont=0;

  while(L1){
    cont++;

    L1=L1->prox;
  }

  return cont;
}

int main(void) {
  TLista L1=NULL, L2=NULL;
  int n,p;

  printf("\n---------- LISTA 1 ------------\n");
  inserir(&L1,1);
  inserir(&L1,2);
  inserir(&L1,3);
  inserir(&L1,4);
  inserir(&L1,5);
  pos(&L1);
  exibir(L1);

  printf("\n\n---------- LISTA 2 ------------\n");
  printf("A partir de qual posição da lista: ");
  scanf("%d",&p);
  if(Verificap(L1,p)==TRUE){
    printf("Quantos números a partir dessa posição: ");
    scanf("%d",&n);
    if (n>=0){
      if(n<qtdeElementosLista(L1)){
        if (Func(L1,&L2,n,p)==TRUE){
        pos(&L2);
        Inverte(&L2);
        exibir(L2);
          } else {
          printf("\n\tErro durante a criação da lista!");
          }
        } else {
        n=qtdeElementosLista(L1)-p;
        if (Func(L1,&L2,n,p)==TRUE){
          pos(&L2);
          Inverte(&L2);
          exibir(L2);
            } else {
          printf("\n\tErro durante a criação da lista!");
            }
        }
      } else {
      printf("\n\tA quantidade de números deve ser positiva!");
      }
    } else {
    printf("\n\tEssa posição não existe na lista!");
    }
  
  return 0;
}
