/*
Considerando as implementações de listas encadeadas
feitas em aula, apresentar o código das funções de
inserção, remoção, alteração, busca e exibição para
uma lista cujos elementos estejam ordenados
CRESCENTEMENTE, além de PERMITIR repetição de valores.
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
int inserir (TLista *L, int n){	
  //Declaração de variáveis
  TLista aux = *L, novo;

  //abrindo espaço para o novo nó que vai ser inserido
  novo=(TLista)malloc(sizeof(TNo));

  if(!novo){
    return FALSE;
  }
  
  //insere n digitado no novo nó
  novo -> valor = n;

  if (!(*L)){ //lista vazia
    novo->prox = NULL;
    *L = novo;
  } else{
    if (n <= (aux->valor)){ 
      novo -> prox = aux;
      *L = novo;      
    } else{
      while ((aux->prox->valor) < n && (aux->prox)){
        aux = aux-> prox;
      }
      novo->prox=aux->prox;
      aux->prox=novo;
    } 
  }
  return TRUE;
}

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
			if (aux1->valor <= numero){
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

TLista buscar (TLista L, int numero){
	//declaração de variáveis
	TLista aux = L;

	//percorrendo a lista até o final
	while (aux != NULL){
		//testando se é o valor sendo buscado
		if (aux->valor == numero){
		//retornando o endereço do nó que contém o valor buscado
			return aux;
		}
	//atualizando o 'aux' para apontar para o próximo nó
	aux = aux->prox;
	}

//se chegou a este ponto, o número buscado não existe
	return NULL;
}

int alterar (TLista *L, int velho, int novo){
  int cont=0, n;//quantas alterações 
  TLista aux=(*L), aux2=(*L), aux3;
  
  while(aux){
    if(aux->valor == velho){
      if((aux->prox->valor) >= novo){//está na ordem crescente
        aux->valor=novo;//substitui velho pelo novo
        cont++;
      } else {//não está na ordem        
       cont=remover(L,velho);
        n=cont;
        while(n){
          inserir(L,novo);
          n--;
        }
      }
    } 

    aux=aux->prox;
  }

  return cont;
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


int menu (){
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf ("\n\nMenu de Operacoes:\n\n");
	printf ("(1) Inserir\n");
	printf ("(2) Remover\n");
	printf ("(3) Alterar\n");
	printf ("(4) Buscar\n");
	printf ("(5) Exibir\n");
	printf ("(6) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}

int main(void) {
//declaração de variáveis
	TLista L = NULL;
	int num1, num2, op, quant;
	
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

			//Remoção
			case 2: printf ("\nEntre com o valor a ser removido: ");
			        scanf ("%d", &num1);
			        
			        //chamando a função
			        quant = remover (&L, num1);
			        
					if (quant > 0)
			        {
			        	printf ("\n\t%d remocoes realizadas!", quant);
					}
					else
					{
						printf ("\n\tERRO: remocao nao realizada!");
					}
					break;

			//Alteração
			case 3: printf ("\nEntre com o valor a ser alterado: ");
			        scanf ("%d", &num1);
			        
			        printf ("\nEntre com o novo valor: ");
			        scanf ("%d", &num2);
			        
			        //chamando a função
			        quant = alterar (&L, num1, num2);
			        
			        if (quant > 0){
			        	printf ("\n\t%d alteracoes realizadas!", quant);
					} else {
						printf ("\n\tERRO: alteracao nao realizada!");
					}
					break;

			//Busca
			case 4: printf ("\nEntre com o valor a ser buscado: ");
			        scanf ("%d", &num1);
			        
			        //chamando a função			        
					if (buscar(L,num1) == NULL) {
			     printf ("\n\tO valor %d NAO foi encontrado na lista!", num1);   	
					}	else{
						printf ("\n\tO valor %d foi encontrado na lista!", num1);
					}
					break;

			//Exibir
			case 5: exibir (L);
					break;
					
			//Saída
			case 6: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}	while (op != 6);
  
  return 0;
  }

//--------------------------------------------------------------------------------------------------------------------------------------
/*
Considerando as implementações de listas encadeadas
feitas em aula, apresentar o código das funções de
inserção, remoção, alteração, busca e exibição para
uma lista cujos elementos estejam ordenados
CRESCENTEMENTE, SEM repetição de valores.
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
TLista buscar (TLista L, int numero){
	//declaração de variáveis
	TLista aux = L;

	//percorrendo a lista até o final
	while (aux != NULL){
		//testando se é o valor sendo buscado
		if (aux->valor == numero){
		//retornando o endereço do nó que contém o valor buscado
			return aux;
		}
	//atualizando o 'aux' para apontar para o próximo nó
	aux = aux->prox;
	}

//se chegou a este ponto, o número buscado não existe
	return NULL;
}

int inserir (TLista *L, int n){	
  //Declaração de variáveis
  TLista aux = *L, novo;

  //abrindo espaço para o novo nó que vai ser inserido
  novo=(TLista)malloc(sizeof(TNo));

  if(!novo){
    return FALSE;
  }
  
  //insere n digitado no novo nó
  novo -> valor = n;

  if (!(*L)){ //lista vazia
    novo->prox = NULL;
    *L = novo;
  } else{
  if(buscar(*L,n)==NULL){
    if (n <= (aux->valor)){ 
      novo -> prox = aux;
      *L = novo;      
    } else{
      while ((aux->prox->valor) < n && (aux->prox)){
        aux = aux-> prox;
      }
      novo->prox=aux->prox;
      aux->prox=novo;
    } 
  } else {
    return FALSE;
  }
 }
  return TRUE;
}

int remover (TLista *L, int numero){
	TLista aux1 = (*L)->prox;
  TLista aux2 = *L;

  if ((*L)->valor == numero) {
    (*L) = (*L)->prox;
    free(aux2);
    return TRUE;
  }

  while (aux1) {
    if (aux1->valor == numero) {
       aux2->prox = aux1->prox;
       free(aux1);
       aux1 = aux2->prox;
      return TRUE;
    }

    aux1 = aux1->prox;
    aux2 = aux2->prox;
  }
  return FALSE;
}


int alterar (TLista *L, int velho, int novo){
  TLista aux=(*L), aux2=(*L), aux3;
  
 while(aux){
  if(buscar(*L,novo)==NULL){
    if(aux->valor == velho){
      if((aux->prox->valor) >= novo){//está na ordem crescente
        aux->valor=novo;//substitui velho pelo novo
        return TRUE;
      } else {//não está na ordem        
          remover(L,velho);
          inserir(L,novo);
          return TRUE;
        }
      } 
    }

    aux=aux->prox;
  }

  return FALSE;
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


int menu (){
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf ("\n\nMenu de Operacoes:\n\n");
	printf ("(1) Inserir\n");
	printf ("(2) Remover\n");
	printf ("(3) Alterar\n");
	printf ("(4) Buscar\n");
	printf ("(5) Exibir\n");
	printf ("(6) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}

int main(void) {
//declaração de variáveis
	TLista L = NULL;
	int num1, num2, op;
	
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

			//Remoção
			case 2: printf ("\nEntre com o valor a ser removido: ");
			        scanf ("%d", &num1);
			        
			        //chamando a função
			        
					if (remover(&L, num1)==TRUE)
			        {
			        	printf ("\n\tRemocao realizada!");
					}
					else
					{
						printf ("\n\tERRO: remocao nao realizada!");
					}
					break;

			//Alteração
			case 3: printf ("\nEntre com o valor a ser alterado: ");
			        scanf ("%d", &num1);
			        
			        printf ("\nEntre com o novo valor: ");
			        scanf ("%d", &num2);
			        
			        //chamando a função			        
			        if (alterar(&L, num1, num2)==TRUE){
			        	printf ("\n\tAlteracao realizada!");
					} else {
						printf ("\n\tERRO: alteracao nao realizada!");
					}
					break;

			//Busca
			case 4: printf ("\nEntre com o valor a ser buscado: ");
			        scanf ("%d", &num1);
			        
			        //chamando a função			        
					if (buscar(L,num1) == NULL) {
			     printf ("\n\tO valor %d NAO foi encontrado na lista!", num1);   	
					}	else{
						printf ("\n\tO valor %d foi encontrado na lista!", num1);
					}
					break;

			//Exibir
			case 5: exibir (L);
					break;
					
			//Saída
			case 6: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}	while (op != 6);
  
  return 0;
  }
