#ifndef PILHA_H
#define PILHA_H

#endif

typedef struct No {
    char dado;
    int numero;

    struct No* esquerdo;
    struct No* direito;
    struct No* pai;
    struct No* proximo;
} No;

typedef struct {
    No* topo;
} Pilha;

Pilha* criar_pilha();

void empilhar(Pilha* pilha, No* no);

No* desempilhar(Pilha* pilha);
