/*
Desenvolver uma função que, dado um arquivo com números inteiros, um por linha, crie uma lista encadeada L com a seguinte característica:

Cada nó de L terá os seguintes campos: valor (cada número distinto existente no arquivo), quantidade (quantas vezes o número armazenado no campo valor encontra-se no arquivo), prox (endereço do próximo nó da lista).
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 0
#define FALSE 1
  
/* int gerarArquivo (int n, char nomeArq[]){
  //Declaração de variáveis
  int i;
  FILE *arquivo;  //1. Declarar uma variável do tipo FILE*
		
	//2. Abrir o arquivo (associa a variável FILE à string que representa o arquivo / define o tipo de acesso)
	arquivo = fopen (nomeArq, "w");  //w - write / r - read / a - append

  //Testando se houve falha na abertura do arquivo
  if (arquivo==NULL){ //if(arquivo)
    return FALSE;
  } else {
    //Escrevendo os números de 1 a N no arquivo
    for (i=1; i<=n; i++){
      fprintf(arquivo, "%d\n",i); //3. Manipular o arquivo
    }

    //4. Fecha arquivo
    fclose(arquivo);
    
    return TRUE;
  }  
} */

typedef struct No {
  int valor;
  int quantidade;
	struct No* prox; //TNo ainda n foi declarado
} TNo;

typedef TNo* TLista; //para não precisar usar **

//Questão 01
int busca (TLista L, int numero){ 
	//declaração de variáveis
	TLista aux = L;
  int qtde=1;//começa tendo 1 elemento no nó
	
	//percorrendo a lista até o seu final
	while (aux != NULL)	{//while(aux)
		//testando se é o valor sendo buscado
		if (aux->valor == numero)	{//se o valor for achado, atualiza a quantidade 
      aux->quantidade++;
      qtde++;
		}
			
		//atualizando o 'aux' para apontar para o próximo nó
		aux = aux->prox;
	}

  if (qtde==1){
    return FALSE;
  }
	
	return qtde;	
}

int Func(TLista *L, char nomeArq[]){
  //declaração de variáveis;
	TLista aux;
  FILE *arquivo;
  int numero; 
  
  arquivo=fopen(nomeArq,"r");

  if (!arquivo){//if(arq==NULL)
    return FALSE;
  } else { //Se o arquivo existe:
    while (fscanf(arquivo,"%d",&numero)!=EOF){
      if(busca(*L,numero)==FALSE){//lista vazia ***
        //1º passo: alocar memória para o novo nó	
	      aux = (TLista) malloc (sizeof(TNo));
	
	      //Verificando se houve erro na alocação de memória
        if(!aux){//if(aux==NULL)
          return FALSE;
        } else {
          //2º passo: Armazenar 'numero' na memória recém-alocada e incluir qtde dele
	        	aux->valor = numero;
            aux->quantidade = 1;
		
		      //3º passo: mandar o campo 'prox' do novo nó apontar para o "até então" primeiro elemento	da lista
		        aux->prox = *L;
		
		      //4º passo: fazer com que L aponte para o novo nó da lista		
		        *L = aux;
        }
      }
		}
  }

		return TRUE;
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
      printf("Quantidade de valores no nó: %d\n\n", aux->quantidade);
			
			//atualizando o 'aux' para apontar para o próximo nó
			aux = aux->prox;
		}
	}
}

int main(void) {
  char nomeArquivo[50];
  int n;
  TLista L=NULL;
  
/*
  printf("\nNome do arquivo: ");
  scanf(" %[^\n]",nomeArquivo);
  printf("Números de 1 até: ");
  scanf("%d",&n);

  switch(gerarArquivo(n,nomeArquivo)){
    case FALSE:
    printf("\n\tErro na abertura do arquivo!");
      break;

    case TRUE:
    printf("\n\tArquivo gerado com sucesso!");
      break;
  } */

  printf("\nNome do arquivo: ");
  scanf(" %[^\n]",nomeArquivo);

  if (Func(&L,nomeArquivo)==TRUE){
    printf("\n\tSucesso!\n\n");
  } else {
    printf("\n\tFalha!\n\n");
  }

  exibir(L);
  
    return 0;
}