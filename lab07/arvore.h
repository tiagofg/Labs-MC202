#ifndef ARVORE_H
#define ARVORE_H

#endif

#include "pilha.h"

typedef struct Arvore {
    No* raiz;
} Arvore;

Arvore* criar_arvore();

void limpar_arvore(Arvore* arvore);

No* criar_no(char dado, int numero);

No* iniciar_operacao(Arvore* arvore, No* no, No* atual);

void inserir_variavel(No* no, No** atual);

No* procurar_no(No* raiz, char dado);

void printar_arvore(No* raiz);