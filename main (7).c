#include <stdio.h>

/*
FAETERJ-Rio
	Fundamentos de Programação - FPR
	2022/2  -  Turma: Manhã
	
	Data: 23/11/2022
	
	Filas (através de listas encadeadas)


Pilha - ponteiro no início só
Fila - inicio e fim
  */

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//definição de tipos
typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;

//declaração dos protótipos das funções
int enfilar (TLista *F, TLista *U, int numero);
int desenfilar (TLista *F, TLista *U, int *numero);
int primeiro (TLista F, int *p);

int menu ();

//main

//implementação das funções
int enfilar (TLista *F, TLista *U, int numero){
	//declaração de variáveis;
	TLista aux;
	
	//1º passo: alocar memória para o novo nó	
	aux = (TLista) malloc (sizeof(TNo));
	
	//verificando se houve erro na alocação de memória
	if (aux == NULL){
		return FALSE;
	} else {
		//2º passo: armazenar 'numero' na memória recém-alocada
		aux->valor = numero;
		
		//3º passo: fazer com que o campo 'prox' do novo nó aponte para NULL
		aux->prox = NULL;
		
		if (*U){
			//4º passo: fazer o "antigo último nó" apontar para o novo nó
			(*U)->prox = aux;
		}else{
			//Fazer o 'F' apontar para o novo nó (que é o primeiro da fila)
			*F = aux;
		}
	
		//5º passo: fazer o 'U' apontar para o novo nó
		*U = aux;
		
		return TRUE;
	}	
}

int desenfilar (TLista *F, TLista *U, int *numero)
{
	//declaração de variáveis
	TLista aux;
	
	//verificando se a fila está vazia
	if (!(*F)){
		return FALSE;
	}else{
		//verificando se a lista possui apenas um nó
		if (*F == *U){
			*U = NULL;
		}
		
		//fazer o 'aux' apontar para o primeiro elemento da fila
		aux = *F;
		
		//atualizando o F, uma vez que o primeiro será removido	
		*F = aux->prox;   //ou   *F = (*F)->prox
		
		/*
		if (*F == NULL)
		{
			*U = NULL;
		}	
		*/
		
		//armazenando em 'numero' o valor sendo removido
		*numero = aux->valor;
		
		//liberando o nó sendo removido
		free (aux);
		
		return TRUE;
	}
}

int primeiro (TLista F, int *p){
	//verificando se a fila está vazia
	//if (F == NULL)
	if (!F){
		return FALSE;
	}else{
		//armazenando em 'p' o primeiro valor da fila
		*p = F->valor;
		
		return TRUE;
	}
}

int menu (){
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Enfilar\n");
	printf ("(2) Desenfilar\n");
	printf ("(3) Primeiro\n");
	printf ("(4) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}

int main(void) {
//declaração de variáveis
	TLista F = NULL, U = NULL;
	int num, op;
	
	do{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usuário
		op = menu ();
		
		//verificando a opção escolhida
		switch (op){
			//Enfilar
			case 1: printf ("\nEntre com o valor a ser enfilado: ");
			        scanf ("%d", &num);
			        
			        //chamando a função
			        if (enfilar (&F, &U, num) == TRUE){
			        	printf ("\n\tElemento enfilado com sucesso!");
					}else{
						printf ("\n\tERRO: elemento nao enfilado!");
					}
					break;

			//Desenfilar
			case 2: //chamando a função
			        if (desenfilar (&F, &U, &num) == TRUE){
			        	printf ("\n\tO valor %d foi desenfilado!", num);
					}else{
						printf ("\n\tERRO: fila vazia!");
					}
					break;

			//Primeiro
			case 3: if (primeiro (F, &num) == TRUE){
			        	printf ("\n\tPrimeiro elemento da fila: %d", num);
					}else{
						printf ("\n\tERRO: fila vazia!");
					}
			
			//Saída
			case 4: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}	while (op != 4);
  
  return 0;
}