/*
  QUESTÃO 04:
Implementar uma função que, dadas duas listas dinâmicas do tipo TLista, verifique se estas são iguais; isto é, contêm os mesmos elementos, na mesma ordem.
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

int verificarIguais (TLista L1, TLista L2){
	//declaração de variáveis
	TLista aux1, aux2;
	
	//inicializando os auxiliares
	aux1=L1;
	aux2=L2;

	//percorrendo enquanto existirem elementos nas listas
	while(aux1 && aux2){
		//verificando se os elementos apontados por 'aux1' e 'aux2' são diferentes
		if(aux1->valor != aux2->valor){
			return FALSE;
		}
		//atualizando 'aux1' e 'aux2'
		aux1 = aux1->prox;
		aux2 = aux2->prox;
	}

	//verificando se as duas listas terminaram (uma pode ter mais/menos elementos que a outra)
	if (!aux1 && !aux2){ //as duas listas terminaram
		return TRUE;
		} else { //uma lista ainda não terminou
		return FALSE; //OBS: valor não pode ser comparado com NULL, só ponteiro
	}
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

  printf("\n\n+++++++++++++++ Lista 2 +++++++++++++++++\n");
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
			        if (inserir (&L2, num1) == TRUE){
			        	printf ("\n\tInsercao realizada com sucesso!");
					} else {
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;
      
			//Exibir
			case 2: exibir (L2);
					break;
					
			//Saída
			case 3: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}	while (op != 3);
  
  printf("\n\n+++++++++++++++ RESULTADO +++++++++++++++++\n");
  if(verificarIguais(L,L2)==TRUE){
    printf("\n\tAs duas listas são iguais --- possuem os mesmos valores e estão na mesma ordem!");
  } else {
    printf("\n\tAs listas são diferentes!");
  }
  
  return 0;
}