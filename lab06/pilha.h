#ifndef PILHA_H
#define PILHA_H

#endif

typedef struct No {
    int dado;
    struct No* proximo;
} No;

typedef struct {
    No* topo;
} Pilha;

Pilha* criar_pilha();

void empilhar(Pilha* pilha, int num);

int desempilhar(Pilha* pilha);

void remover_menor_dado(Pilha* pilha);

void imprimir_pilha(Pilha* pilha);

void limpar_pilha(Pilha* pilha);
