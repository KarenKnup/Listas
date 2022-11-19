#include <stdio.h>

/*
  Listas (encadeadas): agenda / inicialmente vazia - armazena valores sem desperdiçar memória
    1- Listas estáticas - aloca memória antes da execução - trabalha com vetor - deve prever quanta memória usará
    2- Listas dinâmicas - usa memória durante a execução/fica espalhado, não é predefinido

  Exibir uma lista - por um for do vetor
    vetor-endereço da 1ª posição
    v[2] - posição 2
    int v[20]-capacidade de 20

  ponteiro NULL - indica que finalizou a lista

  buscar,exibir,inserir,remover,alterar
  */

typedef struct No { //struct No = TNo
  int valor;
  struct No* prox;//TNo ainda n foi declarada
} TNo;

void exibir (Tlista L) {//exibir todos os elementos da lista
  
}

//----------------------------------------

//Exibir:

TLista aux=L; // aponte p onde o L aponta
//Aux: endereço do nó que armazena o 10 (primeiro valor)
//aux-> : o nó que armazena o valor 10

//*b - conteúdo de b
//aux->valor = *aux.valor
While(aux!=NULL){//while(aux)
  printf("%d",aux->valor);
  aux=aux->prox; }

void exibir (Tlista L) {
 Tlista aux;
   if (L==NULL){ //if (!L)
    printf("Lista vazia")
} else {
printf("Lista: ")
aux=L
while (aux) {
 printf ("%d",aux->valor)
}
aux=aux->valor
}
printf(\n\n)
}

Inserir(TNo** L, int numero) == Inserir (Tlista* L, int numero)


int buscar(Tlista L, int numero) {
 Tlista aux=L

 While (aux){
    If (numero==aux->valor){
        Return 1
} 
aux=aux->prox
}
Return 0
}

int alterar (Tlista L, int vetor, int novo) {
 Tlista aux=L
 Int cont=0 //quantas alterações teve

While(aux){
 If (aux->valor==velho){
  aux->valor=novo
  Cont++
}
aux=aux->prox
}
Return cont
}

/*
1° Alocar memória p o novo elemento com um aux
2° Armazenar o elemento novo no novo nó
3° Armazenar no campo prox do novo nó o endereço daquele que, até então, era o primeiro elemento
4° Fazer o L apontar para o novo nó
*/
Int inserir (Tlista *L, int numero) {
 Tlista aux;
//malloc (alloc.h) - comando em C p alocar memória- memory allocation - ele dá como retorno um (*void) ponteiro void, um valor indeterminado que n sabe praq vai usar, por isso se acompanha pela Tlista

//sizeof-diz quantos bytes ocupa 

//Tentando alocar memória p o novo nó
aux = (Tlista)malloc(sizeof(TNo))
 
//Verificando se foi alocado
If(!aux){//não conseguiu alocar memória 
 Return 0
} else {//1°passo OK
//Inserindo o valor 
aux->valor=numero

//Fazendo o novo apontar para o antigo primeiro nó
aux->prox=*L

//Fazer o L apontar para o novo nó
*L=aux
}
Return 1

}

//If (*L) se L for verdadeiro


int main(void) {
 TNo* Tlista; //guarda endereço do primeiro No - Lista é ponteiro p/ TNo - os endereços n mudam
  
  return 0;
}

