#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

Fila* criar_fila() {
    Fila* fila = malloc(sizeof(Fila));

    fila->inicio = NULL;
    fila->fim = NULL;

    return fila;
}

void destroi_fila(Fila* fila) {
    Item* item = fila->inicio;

    while (item != NULL) {
        desenfileira(fila);
        item = item->proximo;
    }

    free(fila);
}

void enfileira(Fila* fila, int v) {
    Item* novo = malloc(sizeof(Item));

    novo->vertice = v;
    novo->proximo = NULL;

    if (fila->inicio == NULL) {
        fila->inicio = novo;
    } else {
        fila->fim->proximo = novo;
    }

    fila->fim = novo;
}

int desenfileira(Fila* fila) {
    Item* primeiro = fila->inicio;
    int x = primeiro->vertice;

    fila->inicio = fila->inicio->proximo;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    
    free(primeiro);
    return x;
}

int fila_vazia(Fila* fila) {
    if (fila->inicio == NULL && fila->fim == NULL) {
        return 1;
    }

    return 0;
}