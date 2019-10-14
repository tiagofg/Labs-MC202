#ifndef PILHA_H
#define PILHA_H

#endif

#include "lista.h"

typedef struct No_pilha {
    int dado;
    struct No_pilha* proximo;
} No_pilha;

typedef struct {
    No_pilha* topo;
    int tamanho;
} Pilha;

Pilha* criar_pilha();

void empilhar(Pilha* pilha, char num);

int desempilhar(Pilha* pilha);

void inverter_pilha(Pilha* pilha);

void inserir_lista_na_pilha(Pilha* pilha, Lista* lista);

void find_maior_valor(Pilha* pilha, Lista* lista, int n);

int get_valor_sequencia(Pilha* pilha);

void imprimir_pilha(Pilha* pilha);

void limpar_pilha(Pilha* pilha);
