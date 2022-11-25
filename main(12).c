#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct No {
  int valor;
  struct No *prox;
} TNo;

typedef TNo *TLista;

// Função para imprimir a Lista
void imprimirLista(TLista L) {
  TLista aux = L;

  if (!aux) {
    printf("Lista vazia!");
    return;
  }

  while (aux) {
    printf("%d\n", aux->valor);
    aux = aux->prox;
  }
}

// Função para inserir um elemento no começo da lista
void inserirInicioLista(TLista *L, int valor) {
  TLista aux = (TLista)malloc(sizeof(TNo));
  aux->valor = valor;
  aux->prox = *L;
  *L = aux;
}

// Função para inserir um elemento no final da Lista
void inserirFinalLista(TLista *L, int valor) {
  TLista aux1 = (TLista)malloc(sizeof(TNo));
  TLista aux2 = *L;

  aux1->valor = valor;
  aux1->prox = NULL;

  if (*L == NULL) {
    *L = aux1;
    return;
  }

  while (aux2->prox != NULL) {
    aux2 = aux2->prox;
  }

  aux2->prox = aux1;
}

// Função para inserir um elemento no final de Listas ordenadas
void inserirFinalListaOrdenada(TLista *L, TLista *aux, int valor) {
  TLista aux2 = (TLista)malloc(sizeof(TNo));
  aux2->valor = valor;
  aux2->prox = NULL;
  (*aux)->prox = aux2;
}

// Função para inserir um elemento na posição atual
void inserirPosicaoAtual(TLista *aux1, TLista *aux2, int valor) {
  TLista aux3 = (TLista)malloc(sizeof(TNo));
  aux3->valor = valor;
  aux3->prox = *aux1;
  (*aux2)->prox = aux3;
}

// Função para remover o nó atual de uma lista
void removerPosicaoAtual(TLista *L, TLista *aux1, TLista *aux2) {
  (*aux2)->prox = (*aux1)->prox;
  free(*aux1);
  (*aux1) = (*aux2)->prox;
}

// Função para copiar uma Lista para outra
void copiarLista(TLista *LDestino, TLista LOrigem) {
  TLista aux1 = LOrigem;
  TLista aux2 = (TLista)malloc(sizeof(TNo));

  while (aux1) {
    inserirFinalLista(LDestino, aux1->valor);
    aux1 = aux1->prox;
  }
}

//===============================================================//

// Função para buscar um valor listas crescentes
int busca(TLista L, int valor) {
  TLista aux = L;

  while (aux) {
    if (aux->valor == valor)
      return TRUE;
    if (aux->valor > valor)
      return FALSE;

    aux = aux->prox;
  }

  return FALSE;
}

// Função para inserir nós em listas crescentes
int insercao(TLista *L, int valor) {
  if (busca(*L, valor))
    return FALSE;
  if ((*L == NULL) || ((*L)->valor > valor)) {
    inserirInicioLista(L, valor);
    return TRUE;
  }

  TLista aux2 = *L;
  TLista aux1 = (*L)->prox;

  while (aux1 != NULL) {
    if (aux1->valor > valor) {
      inserirPosicaoAtual(&aux1, &aux2, valor);
      return TRUE;
    }
    aux1 = aux1->prox;
    aux2 = aux2->prox;
  }

  inserirFinalListaOrdenada(L, &aux2, valor);

  return TRUE;
}

// Função para remover nós em listas crescentes
int remocao(TLista *L, int valor) {
  TLista aux1 = (*L)->prox;
  TLista aux2 = *L;

  if ((*L)->valor == valor) {
    (*L) = (*L)->prox;
    free(aux2);
    return TRUE;
  }

  while (aux1) {
    if (aux1->valor == valor) {
      removerPosicaoAtual(L, &aux1, &aux2);
      return TRUE;
    }

    aux1 = aux1->prox;
    aux2 = aux2->prox;
  }
  return FALSE;
}

// Função para alterar o valor de um nó em listas crescentes
int alteracao(TLista *L, int valorAntigo, int valorNovo) {
  if (busca(*L, valorAntigo)) {
    if (busca(*L, valorNovo))
      return FALSE;
    if ((*L)->valor == valorAntigo) {
      (*L)->valor = valorNovo;
      return TRUE;
    }

    TLista aux1 = (*L)->prox;
    TLista aux2 = *L;

    while (aux1) {
      if (aux1->valor == valorAntigo) {
        insercao(L, valorNovo);
        remocao(L, valorAntigo);
        return TRUE;
      }
      aux1 = aux1->prox;
      aux2 = aux2->prox;
    }
  }
  return FALSE;
}

int main(void) {
  TLista L = NULL;
  TLista L2 = NULL;

  inserirInicioLista(&L, 50);
  inserirInicioLista(&L, 40);
  inserirInicioLista(&L, 30);
  inserirInicioLista(&L, 20);
  inserirInicioLista(&L, 10);
  imprimirLista(L);
  
  return 0;
}