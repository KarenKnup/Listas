/*
Implementar uma função que, dada uma
lista encadeada L, do tipo TLista, determine
se todos os seus elementos são distintos.
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
int menu (){
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf ("\n\n-------- Menu de Operacoes: ---------\n\n");
	printf ("(1) Inserir\n");
	printf ("(2) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}

/* VERIFICANDO SE OS ELEMENTOS DA STRING SÃO DISTINTOS

int busca (char s[]){
  int i, j, apareceu;

  for (i=0; s[i]; i++){//esse for percorre todo o s[i]
    apareceu=FALSE; //por enquanto não achou nada, então apareceu é falso
    for (j=0; j<i; j++){//esse for percorre todo s[j], sendo que "i" está na frente e "j" atrás -- cada posição de "i" é comparada com  todas de "j"
      if(s[j]==s[i]){
        apareceu=TRUE;
        break; //significa que já achou, então não precisa procurar adiante
      }
    }
  }
  return apareceu;
} */

int Verifica (TLista L){//todos distintos
  TLista aux;

  aux=L->prox;
  
  //percorrendo a lista até o seu final
  while(L != NULL){//while(L)
	  while (aux != NULL)	{//while(aux)
  		if ((L->valor)==(aux->valor)){//comparando cada L com aux
        return FALSE;
      }
      //atualizando o 'aux' para apontar para o próximo nó
  		aux = aux->prox;
  	}
    //atualizando L
    L = L->prox;
  }

	return TRUE;	
}

int main(void) {
TLista L=NULL;
  int op, num;

  do {
    system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usuário
		op = menu ();

    switch (op){
      //Inserir
			case 1: printf ("\nEntre com o valor a ser inserido: ");
			        scanf ("%d", &num);
			        
			        //chamando a função
			        if (inserir (&L, num) == TRUE){
			        	printf ("\n\n\tInsercao realizada com sucesso!");
					} else {
						printf ("\n\n\tERRO: insercao nao realizada!");
					}
					break;
      
      //Saída
			case 2: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
    }
    
  } while (op!=2);

  if(Verifica(L)==TRUE){
    printf("\n\n\t\tOs elementos são distintos! :)");
  }else {
    printf("\n\n\t\tHá elementos iguais! :(");
  }
  
    return 0;
}