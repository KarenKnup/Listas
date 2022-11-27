
/*
Implementar uma função que, dada uma lista dinâmica do tipo TLista, verifique se os elementos da estrutura encontram-se ordenados de forma crescente ou não.
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

int menu (){
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf ("\n\nMenu de Operacoes:\n\n");
	printf ("(1) Inserir\n");
	printf ("(2) Exibir\n");
	printf ("(3) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}

int busca(TLista L) {
  TLista aux=L, aux2=L->prox;

  while (aux2) {
    if ((aux->valor) > (aux2->valor)){
      return FALSE;
    } 
    
    aux = aux->prox;
    aux2 = aux2->prox;
  }

  return TRUE;
}

int main(void) {
//declaração de variáveis
	TLista L = NULL;
	int num1, num2, op, quant, resp;
	
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

  printf("\n\n-----------RESULTADO-----------\n");
  if (busca(L)==TRUE){
    printf("\tLista em ordem CRESCENTE!");
  } else {
    printf("\tNÃO está na ordem crescente!");
  }
  
  return 0;
  }