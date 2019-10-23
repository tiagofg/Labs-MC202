#include <stdio.h>
#include <stdlib.h>

#include "abb.h"

ArvoreBusca* criar_arvore() {
    ArvoreBusca* arvore = malloc(sizeof(ArvoreBusca));
    arvore->raiz = NULL;

    return arvore;
}

No* inserir(ArvoreBusca* arvore, No* raiz, int identificador, char* dado) {
    No* novo;

    if (arvore->raiz == NULL) {
        novo = malloc(sizeof(No));
        novo->esquerdo = novo->direito = NULL;
        novo->identificador = identificador;
        novo->dado = dado;
        arvore->raiz = novo;
        return novo;
    } else if (raiz == NULL) {
        novo = malloc(sizeof(No));
        novo->esquerdo = novo->direito = NULL;
        novo->identificador = identificador;
        novo->dado = dado;
        return novo;
    }

    if (identificador < raiz->identificador) {
        raiz->esquerdo = inserir(arvore, raiz->esquerdo, identificador, dado);
    } else {
        raiz->direito = inserir(arvore, raiz->direito, identificador, dado);
    }

    return raiz;
}

No* buscar(No* raiz, int identificador) {
    if (raiz == NULL || identificador == raiz->identificador) {
        return raiz;
    }

    if (identificador < raiz->identificador) {
        return buscar(raiz->esquerdo, identificador);
    } else {
        return buscar(raiz->direito, identificador);
    }
}

void imprimir_mensagem(ArvoreBusca* arvore, int qtde_dados) {
    No* buscado;

    for (int i = 1; i <= qtde_dados; i++) {
        buscado = buscar(arvore->raiz, i);

        printf("%s", buscado->dado);
    }
}
