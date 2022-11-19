
#include <stdio.h>
/*
- São tipos especias de listas
- Pilhas (de pratos) - p colocar/tirar prato deve no topo da pilha, tem local certo p botar/retirar - fatorial recursiva - pode ser em uma das extremidades (fim/início) onde ocorrerá inserir/remover, onde for + fácil - Listas: normalmente é melhor no começo pq não precisa percorrer tudo/custa mais - ou insere no final (melhor pq n tem como voltar na lista por causa do NULL) e remove no início ou o contrário (2 ponteiros) - Pilhas:só é possível acessar o topo, ou seja, só pode remover/inserir no começo/o primeiro - n tem alteração, busca(só acessa o topo da pilha, n tem como ver os pratos abaixo) nem exibir
  -- FIFO (First in-First out) - Filas
  -- LIFO (Last in-First out) - a pilha é LIFO (último prato colocado na pilha vai ser o primeiro a ser retirado)

if(!P) = if(P==NULL) - se P está vazio

- Filas (de processos/SOP) - o que está na fila faz mais tempo é o primeiro a ser atendido - pode-se criar fila com prioridades

Listas:        Pilhas:
- Inserir    - Empilhar (inserir no topo)
- Remover    - Desempilhar (remover do topo)
- Alterar    - Topo (diz quem é o elemento no topo da pilha)
- Busca
- Exibir

- Lista encadeada - com ponteiro (o uso de ponteiro - * - indica que ocorrerá uma alteração)
- Topo não usa ponteiro
  */
int main(void) {
  printf("Hello World\n");
  return 0;
}