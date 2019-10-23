#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "abb.h"

ArvoreBusca* criar_arvore() {
    ArvoreBusca* arvore = malloc(sizeof(ArvoreBusca));
    arvore->raiz = NULL;

    return arvore;
}

void destruir_arvore(ArvoreBusca* arvore, int qtde_dados) {
    No* no_remocao;

    for (int i = 1; i <= qtde_dados; i++) {
        no_remocao = buscar(arvore->raiz, i);

        //remover_no
    }

    free(arvore);
}


No* inserir(ArvoreBusca* arvore, No* raiz, int identificador, char* dado) {
    No* novo;

    if (raiz == NULL) {
        novo = malloc(sizeof(No));
        novo->esquerdo = novo->direito = NULL;
        novo->identificador = identificador;
        novo->dado = malloc(9 * sizeof(char));
        strcpy(novo->dado, dado);

        if (arvore->raiz == NULL) {
            arvore->raiz = novo;
        }

        return novo;
    }

    if (identificador < raiz->identificador) {
        raiz->esquerdo = inserir(arvore, raiz->esquerdo, identificador, dado);
    } else if (identificador > raiz->identificador) {
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
    char* mensagem = malloc(8 * qtde_dados * sizeof(char) + 1);

    for (int i = 1; i <= qtde_dados; i++) {
        buscado = buscar(arvore->raiz, i);

        strcat(mensagem, buscado->dado);
    }

    printf("%s\n", mensagem);
    free(mensagem);
}
