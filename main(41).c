/*
Dados uma lista encadeada L, do tipo TLista, uma 
posição p (representando a posição de um de seus nós, 
sendo que o primeiro está na posição 0) e uma 
quantidade n, fazer uma função que remova de L n nós 
a partir de p.

Observações: 
▪ Se o valor de p ou de n for inválido, nada será feito e 
o código 0 será retornado (caso contrário, a função 
deverá retornar, ao final, 1);
▪ Caso não existam n nós a partir da posição p, 
deverão ser removidos todos os nós da lista a partir 
de p.
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

int inserir (TLista *L, int numero, int p){
	TLista aux; 
  
	aux = (TLista) malloc (sizeof(TNo));

  TLista aux2=aux->prox;
  
	if (aux == NULL){ 
		return FALSE;
	}	else{
		aux->valor = numero; //aux->valor = *aux.valor
    aux->pos=p;
    
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

int ProcuraP(TLista L, int p){
  TLista aux=L;
  
  while(aux){
    if(aux->pos == p){
      return TRUE;
    }

    aux=aux->prox;
  }
  return FALSE;
}

int ContaPos (TLista L){
  int qtde=0;

  while(L){
    qtde++;

    L=L->prox;
  }

  return qtde;
}

int RemoveNos(TLista *L, int n, int p){
  TLista aux=*L;
  
  //remoção --->
  //4 3 2 1 - números 
  //3 2 1 0 - posições 

  //Verificando se n e p existem
  if(!(n>0 && ProcuraP(*L,p)==TRUE)){
   return FALSE; 
  } 

  if(p==0){
    n=0;
  }

  int cont=n;  
  //Removendo n nós a partir de p --- Caso não existam n nós a partir da posição p, deverão ser removidos todos os nós da lista a partir de p.
 while(aux){
   if(aux->pos == p){
     while(cont>0){
       remover(L,aux->prox->valor);
       if(aux->prox == NULL){
         break;
       }
       
       cont--;
     }
     break;
   }

   aux=aux->prox;
 }
  
  return TRUE;
}

int main(void){
  TLista L=NULL;
  int p=0, n, posicao; 
  
  inserir(&L,1,p);
  p++;
  inserir(&L,2,p);
  p++;
  inserir(&L,3,p);
  p++;
  inserir(&L,4,p);
  p++;
  exibir(L);

  printf("\nRemover quantos nós: ");
  scanf("%d",&n);
  printf("A partir da posição: ");
  scanf("%d",&posicao);

  if(RemoveNos(&L,n,posicao)==TRUE){
    printf("\n\n\tSucesso na remoção!");
    exibir(L);
  } else {
    printf("\n\n\tERRO!");
  }
  
  return 0;
}
