#include <stdio.h>
#include <stdlib.h>

typedef struct ponto{
int x,y;
struct ponto *prox;
} TPonto;

int main(void) {
  TPonto *p_inicial, *prox_ponto;
  int resp;

  p_inicial=(TPonto *)malloc(sizeof(TPonto));

  if (p_inicial==NULL){
    exit(1);
  }
  prox_ponto=p_inicial;

  while(1){
    printf("\nDigite x: ");
    scanf("%d",&prox_ponto->x);
    printf("Digite y: ");
    scanf("%d",&prox_ponto->y);
    printf("Continuar: <1> SIM / <Outro valor> NÃO ");
    scanf("%d",&resp);
    if (resp==1){
      prox_ponto->prox=(TPonto*)malloc(sizeof(TPonto));
      prox_ponto=prox_ponto->prox;
    } else {
      break;
      }
    }
  
    prox_ponto->prox=NULL;
    prox_ponto=p_inicial;
    while (prox_ponto!=NULL){
      printf("x: %d, y: %d \n",prox_ponto->x,prox_ponto->y);
      prox_ponto=prox_ponto->prox;
    }
  
  
  return 0;
}