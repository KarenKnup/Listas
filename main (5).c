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

//implementação das funções
int empilhar (TLista *P, int numero){
	//declaração de variáveis;
	TLista aux;
	
	//1º passo: alocar memória para o novo nó	
	aux = (TLista) malloc (sizeof(TNo));
	
	//verificando se houve erro na alocação de memória
	if (aux == NULL){
		return FALSE;
	}	else {
		//2º passo: armazenar 'numero' na memória recém-alocada
		aux->valor = numero;
		
		//3º passo: mandar o campo 'prox' do novo nó apontar para o "até então" topo da pilha
		aux->prox = *P;
		
		//4º passo: fazer com que P aponte para o novo nó
		*P = aux;
		
		return TRUE;
	}	
}

int desempilhar (TLista *P, int *numero){
	//declaração de variáveis
	TLista aux;
	
	//verificando se a pilha está vazia
	if (!(*P))	{
		return FALSE;
	}	else	{
		//fazer o 'aux' apontar para o topo da pilha
		aux = *P;
		
		//atualizando o P, uma vez que o topo será removido	
		*P = aux->prox;   //ou   *P = (*P)->prox
		
		//armazenando em 'numero' o valor sendo removido
		*numero = aux->valor;
		
		//liberando o nó sendo removido
		free (aux);
		
		return TRUE;
	}
}

int topo (TLista P, int *t){
	//verificando se a pilha está vazia
	//if (P == NULL)
	if (!P)	{
		return FALSE;
	}	else {
		//armazenando em 't' o valor que encontra-se no topo da pilha
		*t = P->valor;
		
		return TRUE;
	}
}

int menu (){
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Empilhar\n");
	printf ("(2) Desempilhar\n");
	printf ("(3) Topo\n");
	printf ("(4) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}

int main(void) {
//declaração de variáveis
	TLista P = NULL;
	int num, op;
	
	do {
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usuário
		op = menu ();
		
		//verificando a opção escolhida
		switch (op)	{
			//Empilhar
			case 1: printf ("\nEntre com o valor a ser empilhado: ");
			        scanf ("%d", &num);
			        
			        //chamando a função
			        if (empilhar (&P, num) == TRUE) {
			        	printf ("\n\tElemento empilhado com sucesso!");
					}	else {
						printf ("\n\tERRO: elemento nao empilhado!");
					}
					break;

			//Desempilhar
			case 2: //chamando a função
			        if (desempilhar (&P, &num) == TRUE)  {
			        	printf ("\n\tO valor %d foi desempilhado!", num);
					}	else {
						printf ("\n\tERRO: pilha vazia!");
					}
					break;

			//Topo
			case 3: if (topo (P, &num) == TRUE) {
			        	printf ("\n\tTopo da pilha: %d", num);
					}	else {
						printf ("\n\tERRO: pilha vazia!");
					}
			
			//Saída
			case 4: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	} while (op != 4);
  
  return 0;
}