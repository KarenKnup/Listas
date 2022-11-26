/*
  QUESTÃO 06:
Desenvolver uma função que, dada uma lista L1, crie uma nova lista L2, cópia de L1.
*/

#include <stdio.h>
#include <stdlib.h>

//definição de constantes
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

int copiarLista (TLista L1, TLista *L2){//Lista 1 por valor e a L2 por referência pq L2 terá seus valores alterados -- valores de L1 vão para L2 -- inserir deve ser no final, senão as listas ficarão invertidas
	//declaração de variáveis
	TLista aux1, aux2, novo;

	//'aux1' percorrerá a Lista L1
	aux1 = L1;
	
	while (aux1){
		//alocando memória para o novo nó
		novo = (TLista)malloc(sizeof(TNo));

		//armazenando os dados no novo nó
		novo->valor = aux1->valor;
		novo->prox=NULL; //inserindo no final

		//verificando se L2 está vazia -- apenas na primeira inserção
		if (*L2 == NULL){
			*L2=novo;
			aux2=novo;
		} else {//L2 tem elementos
			aux2->prox = novo;
			aux2 = aux2->prox;
		}
		
		//atualizando 'aux1'
		aux1 = aux1->prox;
	}

  return TRUE;
}

int menu (){
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Inserir\n");
	printf ("(2) Exibir\n");
	printf ("(3) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}

int main(void) {
//declaração de variáveis
	TLista L = NULL;
  TLista L2 = NULL;
	int num1, op;

printf("\n+++++++++++++++ Lista 1 +++++++++++++++++\n");
	do{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usuário
		op = menu ();
		
		//verificando a opção escolhida
		switch (op){
			//Inserir
			case 1: printf ("\nEntre com o valor a ser inserido: ");
			        scanf ("%d", &num1);
			        
			        //chamando a função
			        if (inserir (&L, num1) == TRUE){
			        	printf ("\n\tInsercao realizada com sucesso!");
					} else {
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;
      
			//Exibir
			case 2: exibir (L);
					break;
					
			//Saída
			case 3: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}	while (op != 3);
  
  printf("\n\n+++++++++++++++ RESULTADO +++++++++++++++++\n");
  if(copiarLista(L,&L2)==TRUE){
    printf("\n\tLista copiada com sucesso!\n");
    printf("\nLista 2: ");
    exibir(L2);
  } else {
    printf("\n\tERRO: cópia não realizada!");
  }
  
  return 0;
}