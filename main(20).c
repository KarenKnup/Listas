
/*
   KAREN DA MOTA KNUP - FPR - MANHÃ

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

/* int Repeticoes (TLista L){//procura repetições em L
  int cont=0;
  
  while(L != NULL){//while(L)
    if (buscar(L->prox,L->valor)==TRUE){//L vai diminuindo desde o começo
      cont++;
    }
     
    //atualizando L
    L = L->prox;
  }

  return cont;
} */

int Verifica (TLista L, TLista U){//todos distintos
 int flag=0;
  int existe;
  int contIguais=0;
  int contQtdValores=0;

  TLista aux1, aux2, aux1VerificaRepetido;
  aux1=L;
  aux2=U;
  
  //checar em l1 se tem em l2 e se o elemento de l1 já não foi contado na lista
  
  if(aux1 && aux2){
    // algumas das listas esta vazia?
    while(aux1){
      flag=0;
      aux1VerificaRepetido=aux1->prox;
      existe = aux1 -> valor;
      
      while (aux1VerificaRepetido){
        if(existe == aux1VerificaRepetido -> valor){
          flag=1;
        }
        aux1VerificaRepetido=aux1VerificaRepetido->prox;
      } 
      if(flag == 0){
        if(buscar(U, existe) == TRUE){
          contIguais++;
        }
      }
      aux1 = aux1 -> prox;
    }
  } else{
    return FALSE;
  }
  return contIguais;
}

int main (void){
TLista L=NULL, U=NULL;

  inserir(&L,1);
  inserir(&L,1);
  inserir(&L,2);
  inserir(&L,2);
  inserir(&L,2);
  inserir(&L,4);
  inserir(&L,6);
  inserir(&L,3);
   exibir(L);
  printf("\n---------------\n");
  inserir(&U,1);
  inserir(&U,2);
  inserir(&U,2);
  inserir(&U,2);
  inserir(&U,6);
  inserir(&U,7);
  inserir(&U,6);
  exibir(U);
  printf("\n---------------\n");
  printf("\n\tAs listas têm %d elementos em comum.",Verifica(L,U)-Repeticoes(L));

  
	return 0;
}
