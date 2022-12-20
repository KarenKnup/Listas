
/*
LISTA ENCADEADA COM POSIÇÕES DE ELEMENTOS - COM REPETIÇÃO

lista:     2  8  6
posições:  3  2  1

6 foi o primeiro inserido
*/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 0
#define FALSE 1
  
typedef struct No {
	int valor;
  int pos;
	struct No* prox; 
} TNo;

typedef TNo* TLista; 

int inserir (TLista *L, int numero, int n){
	TLista aux; 
  
	aux = (TLista) malloc (sizeof(TNo));

  TLista aux2=aux->prox;
  
	if (aux == NULL){ 
		return FALSE;
	}	else{
		aux->valor = numero; //aux->valor = *aux.valor
    
      aux->pos=n;
     
    
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

int buscar (TLista L, int pos){
	//declaração de variáveis
	TLista aux = L;
	
	//percorrendo a lista até o seu final
	while (aux != NULL)	{//while(aux)
		//testando se é o valor sendo buscado
		if (aux->pos == pos)	{
			return aux->valor;
		}
			
		//atualizando o 'aux' para apontar para o próximo nó
		aux = aux->prox;
	}
	
	//se chegou a este ponto, o número buscado não existe
	return FALSE;	
}

int menu (){
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf ("\n\nMenu de Operacoes:\n\n");
	printf ("(1) Inserir\n");
	printf ("(2) Buscar\n");
	printf ("(3) Exibir\n");
	printf ("(4) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}


int main(void) {
//declaração de variáveis
	TLista L = NULL;
  int op, num, resp, p=1;

  /*  inserir(&L,6,p);
  p++;
    inserir(&L,8,p);
  p++;
    inserir(&L,2,p);
  p++;
    exibir(L);

    printf("\n\n 'p' total: %d",p-1);  */

  do{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usuário
		op = menu ();
		
		//verificando a opção escolhida
		switch (op){
			//Inserir
			case 1: printf ("\nEntre com o valor a ser inserido: ");
			        scanf ("%d", &num);
			        
			        //chamando a função
			        if (inserir (&L, num, p) == TRUE){
			        	printf ("\n\tInsercao realizada com sucesso!");
                p++;
					} else {
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;

			//Busca
			case 2: printf ("\nEntre com uma posição a ser buscada: ");
			        scanf ("%d", &num);
			        
			        //chamando a função
			        resp = buscar (L, num);
			        
					if (resp != FALSE) {
			        	printf ("\n\tO valor %d foi encontrado na posicao %d da lista!", resp,num);
					}	else{
						printf ("\n\tEssa posicao NAO foi encontrada na lista!");
					}
					break;

			//Exibir
			case 3: exibir (L);
					break;
					
			//Saída
			case 4: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}	while (op != 4);
  

  
  return 0;
}