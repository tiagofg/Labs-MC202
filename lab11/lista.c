#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

Lista* criar_lista() {
    Lista* lista = malloc(sizeof(Lista)); //alocando memória da lista

    //setando ínicio da lista
    lista->inicio = NULL;

    return lista;
}

void destruir_lista(No* inicio) {
    if (inicio != NULL) {
        destruir_lista(inicio->proximo);
        free(inicio);
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
    return iterador->proximo;
}

void imprimir_lista(Lista* lista) {
    No* no = lista->inicio;

    while (no->proximo != NULL) {
        printf("%d ", no->variacao);
        no = no->proximo;
    }

    printf("%d ", no->variacao);
    
    printf("\n");
}

// int eh_vazia(Lista* lista) {
//     if (lista->tamanho == 0) {
//         return 1;
//     }

//     return 0;
// }
