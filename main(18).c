
/*
 Implementar uma função que crie uma lista encadeada (dinâmica) com os N primeiros termos de uma PA (progressão aritmética) de razão R e primeiro termo igual a A1.
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

int inserirInicio(TLista *L,TLista *U,int n){
  TLista aux;
  
  aux=(TLista)malloc(sizeof(TNo));
  
  if(!aux){
     return FALSE; 
  }
  
  aux->valor=n;
  aux->prox=*L;
  *L=aux;
  
  if(aux->prox==NULL){
    *U=aux;
  }
    
  return TRUE;
}

int inserirFinal(TLista *L,TLista *U,int n){
  TLista aux;
  if(!*L){
     return inserirInicio(L,U,n);
  }
   
  aux=(TLista)malloc(sizeof(TNo));
  
  if(!aux){
    return FALSE;
  }
    
  aux->valor=n;
  aux->prox=NULL;
  (*U)->prox=aux;
  *U=aux;
  
  return TRUE;
}

void exibir(TLista L){
  TLista aux=L;
  if(!aux){
     printf("Lista Vazia!");
  }   
  while(aux){
    printf("%d ", aux->valor);
    aux=aux->prox;
  }
}

int PA(TLista *L,TLista *U,int a1,int n,int r){
  int i;
  for(i=0;i<n;i++){
    if(!inserirFinal(L,U,a1)){
     return FALSE; 
    }
    a1+=r;
  }
  return TRUE;
}

int main(void) {
//declaração de variáveis
TLista L=NULL,U=NULL;
  int a1,n,r;
  
  printf("Digite o termo inicial da PA: ");
  scanf("%d",&a1);
  printf("Digite a quantidade de termos da PA: ");
  scanf("%d",&n);
  printf("Digite a razão da PA: ");
  scanf("%d",&r);
  
  if(n){
    if(PA(&L,&U,a1,n,r)==TRUE){
      printf("PA criada com sucesso!\n");
      printf("%d termos da PA:\n",n);
      exibir(L);
    } else{
            printf("Erro na criação da PA!");
    }
  } else{
        printf("PA sem termos a exibir.");
  } 
  
  return 0;
  }