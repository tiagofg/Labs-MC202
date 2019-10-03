#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

No* criar_lista(int tamanho) {
    No* no = malloc(sizeof(No));

    no->inicio_segmento = 0;
    no->tamanho_segmento = tamanho;
    // no->tamanho_lista = tamanho;
    no->anterior = NULL;
    no->proximo = NULL;

    // inicio = no;

    return no;
}

void inserir_no(No** lista, No* no){
    No* proximo = *lista;
    No* anterior = NULL;
    
    while (proximo != NULL){
        // // printf("Início: %d %d\n", atual->inicio_segmento, no->inicio_segmento);
        // // printf("Tamanho: %d %d\n", atual->tamanho_segmento, no->tamanho_segmento);
        // // printf("Anterior: %p\n", atual->anterior);
        // // printf("Próximo: %p\n", atual->proximo);
        // if (atual->inicio_segmento > no->inicio_segmento) {
        //     printf("Anterior atual: %p\n", atual->anterior);
        //     printf("Anterior nó: %p\n", no->anterior);
        //     printf("Nó: %p\n", no);
        //     // if (atual == inicio) {
        //     //     no->anterior = inicio->anterior;
        //     //     inicio = no;
        //     //     atual->anterior = inicio;
        //     // } else {
        //     no->anterior = atual->anterior;
        //     atual->anterior = no;
        //     // }
        //     no->proximo = atual;
        //     printf("Pode inserir\n");
        //     break;
        // }
        if (proximo->inicio_segmento > no->inicio_segmento) {
            break;
        }

        anterior = proximo;
        proximo = (*lista)->proximo;
    }

    no->proximo = proximo;
    no->anterior = anterior;

    if (anterior != NULL) {
        anterior->proximo = no;
    }
    if (proximo != NULL) {
        proximo->anterior = no;
    }
}

void remover_no(No* no) {
    no->anterior->proximo = no->proximo;
    no->proximo->anterior = no->anterior;

    free(no);
}

void imprimir_heap(No* lista){
    printf("heap: \n");

    No* atual;
    for (atual = lista; atual != NULL; atual = lista->proximo){
        printf("%d %d\n", atual->inicio_segmento, atual->tamanho_segmento);
    }
}

No* get_melhor_heap(No* heap, int tamanho){
    No* melhor_heap;
    int menor_sobra = tamanho;

    No* atual;
    for (atual = heap; atual != NULL; atual = heap->proximo){
        if (atual->tamanho_segmento >= tamanho && atual->tamanho_segmento - tamanho < menor_sobra) {
            melhor_heap = atual;
            menor_sobra = atual->tamanho_segmento - tamanho;
        }
    }

    return melhor_heap;
}

void alocar_memoria(No* heap, int tamanho) {
    No* no_alocacao = malloc(sizeof(No));

    if (heap->anterior == NULL && heap->proximo == NULL) {
        heap->inicio_segmento = heap->inicio_segmento + tamanho;
        heap->tamanho_segmento = heap->tamanho_segmento - tamanho;
    } else {
        no_alocacao = get_melhor_heap(heap, tamanho);

        if (no_alocacao->tamanho_segmento - tamanho == 0){
            remover_no(no_alocacao);
        } else {
            no_alocacao->inicio_segmento = no_alocacao->inicio_segmento + tamanho;
            no_alocacao->tamanho_segmento = no_alocacao->tamanho_segmento - tamanho;
        }
    }
}

void desalocar_memoria(No* heap, int endereco, int tamanho) {
    No* novo_heap = malloc(sizeof(No));

    novo_heap->inicio_segmento = endereco;
    novo_heap->tamanho_segmento = tamanho;
    novo_heap->anterior = NULL;
    novo_heap->proximo = NULL;

    inserir_no(&heap, novo_heap);
}

void realocar_memoria(No* heap, int endereco, int tamanho, int novo_tamanho) {
    No* atual;
    for (atual = heap; atual != NULL; atual = heap->proximo){
        if (atual->inicio_segmento == endereco) {
            if (novo_tamanho <= tamanho) {
                atual->tamanho_segmento = novo_tamanho;
            } else {
                remover_no(atual);
                alocar_memoria(heap, novo_tamanho);
            }
            break;
        }
    }
}
