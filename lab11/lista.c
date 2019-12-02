#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

Lista* criar_lista() {
    Lista* lista = malloc(sizeof(Lista)); //alocando memória da lista

    //setando ínicio da lista
    lista->inicio = NULL;

    return lista;
}

void destruir_lista(Lista* lista) {
    No* no = lista->inicio;

    if (no->proximo != NULL) {
        No* aux = no;
        no = no->proximo;
        free(aux);
    }
}

Lista* inserir(Lista* lista, int numero, int peso, int variacao, char elevador) {
    if (lista->inicio != NULL) {
        No* no = lista->inicio;

        while (no->proximo != NULL) {
            no = no->proximo;    
        }

        No* novo = malloc(sizeof(No));

        novo->numero = numero;
        novo->peso = peso;
        novo->variacao = variacao;
        novo->elevador = elevador;

        no->proximo = novo;
    } else {
        No* novo = malloc(sizeof(No));

        novo->numero = numero;
        novo->peso = peso;
        novo->variacao = variacao;
        novo->elevador = elevador;
        novo->proximo = NULL;

        lista->inicio = novo;
    }

    return lista;
}

No* obter_iterador(Lista* lista) {
    return lista->inicio;
}

No* avancar_posicao(No* iterador) {
    if (iterador != NULL) {
        return iterador->proximo;
    }

    return NULL;
}

void imprimir_lista(Lista* lista) {
    No* no = lista->inicio;

    while (no->proximo != NULL) {
        printf("%d ", no->numero);
        no = no->proximo;
    }

    printf("%d ", no->numero);
    
    printf("\n");
}

int esta_na_lista(Lista* lista, int vertice) {
    if (lista->inicio == NULL) {
        return 0;
    }

    No* no = lista->inicio;

    while (no != NULL) {
        if (no->numero == vertice) {
            return 1;
        }

        no = no->proximo;
    }

    return 0;
}

int get_variacao(Lista* lista, int vertice) {
    if (lista->inicio == NULL) {
        return 0;
    }

    No* no = lista->inicio;

    while (no != NULL) {
        if (no->numero == vertice) {
            return no->variacao;
        }

        no = no->proximo;
    }

    return 0;
}
