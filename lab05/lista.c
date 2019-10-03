#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

Lista* criar_lista(int tamanho) {
    Lista* lista = malloc(sizeof(Lista));

    No* no = malloc(sizeof(No));

    no->inicio_segmento = 0;
    no->tamanho_segmento = tamanho;
    no->anterior = NULL;
    no->proximo = NULL;

    lista->inicio = no;
    lista->dados = no;

    return lista;
}

void inserir_no(Lista* lista, No* no){
    No* proximo = lista->inicio;
    No* anterior = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = no;
    } else {    
        while (proximo != NULL){
            if (proximo->inicio_segmento > no->inicio_segmento) {
                break;
            }

            anterior = proximo;
            proximo = proximo->proximo;
        }

        no->proximo = proximo;
        no->anterior = anterior;

        if (anterior != NULL) {
            anterior->proximo = no;
        } else {
            lista->inicio = no;
        }

        if (proximo != NULL) {
            proximo->anterior = no;
        }
    }
}

void remover_no(Lista* heap, No* no) {
    if (heap->inicio == no){
        heap->inicio = no->proximo;
    }

    if (no->anterior != NULL) {
        no->anterior->proximo = no->proximo;
    }
    
    if (no->proximo != NULL) {
        no->proximo->anterior = no->anterior;
    }

    free(no);
}

void imprimir_heap(Lista* lista){
    printf("heap:\n");

    No* atual;
    for (atual = lista->inicio; atual != NULL; atual = atual->proximo){
        printf("%d %d\n", atual->inicio_segmento, atual->tamanho_segmento);
    }
}

No* get_melhor_heap(Lista* heap, int tamanho){
    No* melhor_heap;
    int menor_sobra = tamanho;

    No* atual;
    for (atual = heap->inicio; atual != NULL; atual = atual->proximo){
        if (atual->tamanho_segmento >= tamanho && atual->tamanho_segmento - tamanho < menor_sobra) {
            melhor_heap = atual;
            menor_sobra = atual->tamanho_segmento - tamanho;
        }
    }

    return melhor_heap;
}

void juntar_segmentos_se_possivel(Lista* heap) {
    No* atual = heap->inicio;
    No* proximo;

    while (atual->proximo != NULL) {
        proximo = atual->proximo;

        if (atual->inicio_segmento + atual->tamanho_segmento >= proximo->inicio_segmento) {
            atual->tamanho_segmento = atual->tamanho_segmento + proximo->tamanho_segmento;
            remover_no(heap, proximo); 
            continue;
        }
        
        atual = atual->proximo;
    }
}

int esta_livre(Lista* heap, int endereco, int tamanho) {
    No* atual;
    for (atual = heap->inicio; atual != NULL; atual = atual->proximo) {
        // printf("Endereço + tamanho: %d \n", endereco + tamanho);
        // printf("Início segmento %d \n", atual->inicio_segmento);
        // printf("Tamanho segmento: %d \n", atual->tamanho_segmento);
        if (endereco + tamanho >= atual->inicio_segmento && endereco + tamanho <= atual->inicio_segmento + atual->tamanho_segmento) {
            return 1;
        }
    }

    return 0;
}


void alocar_memoria(Lista* heap, int tamanho) {
    No* no_alocacao = malloc(sizeof(No));
    No* inicio = heap->inicio;

    if (inicio->anterior == NULL && inicio->proximo == NULL) {
        if (inicio->tamanho_segmento - tamanho == 0) {
            remover_no(heap, inicio);
        } else {   
            inicio->inicio_segmento = inicio->inicio_segmento + tamanho;
            inicio->tamanho_segmento = inicio->tamanho_segmento - tamanho;
        }
    } else {
        no_alocacao = get_melhor_heap(heap, tamanho);

        if (no_alocacao->tamanho_segmento - tamanho == 0){
            remover_no(heap, no_alocacao);
        } else {
            no_alocacao->inicio_segmento = no_alocacao->inicio_segmento + tamanho;
            no_alocacao->tamanho_segmento = no_alocacao->tamanho_segmento - tamanho;
        }
    }
}

void desalocar_memoria(Lista* heap, int endereco, int tamanho) {
    No* novo_heap = malloc(sizeof(No));

    novo_heap->inicio_segmento = endereco;
    novo_heap->tamanho_segmento = tamanho;
    novo_heap->anterior = NULL;
    novo_heap->proximo = NULL;

    inserir_no(heap, novo_heap);

    juntar_segmentos_se_possivel(heap);
}

void realocar_memoria(Lista* heap, int endereco, int tamanho, int novo_tamanho) {
    if (novo_tamanho < tamanho) {
        desalocar_memoria(heap, endereco + novo_tamanho, tamanho - novo_tamanho);
    } else if (esta_livre(heap, endereco, novo_tamanho) == 1) {
        No* atual;
        for (atual = heap->inicio; atual != NULL; atual = atual->proximo){
            if (endereco + tamanho >= atual->inicio_segmento && endereco + tamanho <= atual->inicio_segmento + atual->tamanho_segmento) {
                if (atual->tamanho_segmento - (novo_tamanho - tamanho) == 0) {
                    remover_no(heap, atual);
                } else {
                    atual->inicio_segmento = endereco + novo_tamanho;
                    atual->tamanho_segmento = atual->tamanho_segmento - (novo_tamanho - tamanho);
                }
            }
        }
    } else {
        // printf("Desalocar: %d, %d \n", endereco, tamanho);
        desalocar_memoria(heap, endereco, tamanho);
        // printf("Alocar: %d \n", novo_tamanho);
        alocar_memoria(heap, novo_tamanho);
        // imprimir_heap(heap);
    }
}
