#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "lista.h"

Lista* criar_lista(int tamanho) {
    Lista* lista = calloc(1, sizeof(Lista)); //alocando memória da lista

    if (lista == NULL) {
        printf("Não foi possível alocar lista");
        exit(1);
    }

    No* no = calloc(1, sizeof(No)); //alocando memória do nó

    if (no == NULL) {
        printf("Não foi possível alocar nó");
        exit(1);
    }

    //inicializando nó
    no->inicio_segmento = 0;
    no->tamanho_segmento = tamanho;
    no->anterior = NULL;
    no->proximo = NULL;

    //setando ínicio da lista
    lista->inicio = no;

    return lista;
}

void destruir_lista(Lista* lista) {
    No* no = lista->inicio;

    while (no != NULL) {
        No* aux = no;
        no = no->proximo;
        free(aux);
    }
    
    free(lista);
}

void inserir_no(Lista* lista, No* no){
    No* proximo = lista->inicio;
    No* anterior = NULL;
  
    while (proximo != NULL){
        //posição para inserir o nó em ordem
        if (proximo->inicio_segmento > no->inicio_segmento) {
            break;
        }

        //alterando ponteiros de anterior e próximo
        anterior = proximo;
        proximo = proximo->proximo;
    }

    //definindo anterior e próximo do novo nó
    no->proximo = proximo;
    no->anterior = anterior;

    //alterando próximo do anterior se ele não for nulo
    if (anterior != NULL) {
        anterior->proximo = no;
    } else {
        lista->inicio = no;
    }

    //alterando anterior do próximo se ele não for nulo
    if (proximo != NULL) {
        proximo->anterior = no;
    }
}

void remover_no(Lista* heap, No* no) {
    //alterando início se o nó removido for o primeiro
    if (heap->inicio == no){
        heap->inicio = no->proximo;
    }

    //alterando próximo do anterior se ele não for nulo
    if (no->anterior != NULL) {
        no->anterior->proximo = no->proximo;
    }
    
    //alterando anterior do próximo se ele não for nulo
    if (no->proximo != NULL) {
        no->proximo->anterior = no->anterior;
    }

    //desalocando nó
    free(no);
}

void imprimir_heap(Lista* lista){
    printf("heap:\n");

    No* atual = lista->inicio;
    while (atual != NULL) {
        //printando cada nó da lista
        printf("%d %d\n", atual->inicio_segmento, atual->tamanho_segmento);
        atual = atual->proximo;
    }
}

No* get_melhor_segmento(Lista* heap, int tamanho){
    No* melhor_heap;
    int menor_sobra = INT_MAX; //inicializando com o máximo valor do int

    No* atual;
    for (atual = heap->inicio; atual != NULL; atual = atual->proximo){
        if (atual->tamanho_segmento >= tamanho && atual->tamanho_segmento - tamanho < menor_sobra) {
            //achado melhor segmento para alocar a memória
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
        //setando valor do próximo
        proximo = atual->proximo;

        //verificando se é possível juntar segmentos
        if (atual->inicio_segmento + atual->tamanho_segmento >= proximo->inicio_segmento) {
            atual->tamanho_segmento = atual->tamanho_segmento + proximo->tamanho_segmento;
            remover_no(heap, proximo); 
            continue;
        }
        
        //setando valor do atual
        atual = atual->proximo;
    }
}

int esta_em_algum_segmento(Lista* heap, int endereco) {
    No* atual;
    for (atual = heap->inicio; atual != NULL; atual = atual->proximo) {
        //verificando se endereço está livre em algum segmento
        if (endereco >= atual->inicio_segmento && endereco < atual->inicio_segmento + atual->tamanho_segmento) {
            return 1;
        }
    }

    return 0;
}

int esta_livre(Lista* heap, int endereco, int tamanho) {
    No* atual;
    for (atual = heap->inicio; atual != NULL; atual = atual->proximo) {
        for (int endereco_buscado = endereco; endereco_buscado < tamanho; endereco_buscado++) {
            //verificando se endereços estão em algum segmento
            if (esta_em_algum_segmento(heap, endereco_buscado) == 0) {
                return 0;
            }
        }
    }

    return 1;
}


void alocar_memoria(Lista* heap, int tamanho) {
    No* no_alocacao;
    No* inicio = heap->inicio;

    //verificando se só existe um nó
    if (inicio->anterior == NULL && inicio->proximo == NULL) {
        //verificar se precisa remover ou alterar nó atual
        if (inicio->tamanho_segmento - tamanho == 0) {
            remover_no(heap, inicio);
        } else {   
            inicio->inicio_segmento = inicio->inicio_segmento + tamanho;
            inicio->tamanho_segmento = inicio->tamanho_segmento - tamanho;
        }
    } else {
        //achando nó que precisa ser alterado
        no_alocacao = get_melhor_segmento(heap, tamanho);

        //verificar se precisa remover ou alterar nó atual
        if (no_alocacao->tamanho_segmento - tamanho <= 0){
            remover_no(heap, no_alocacao);
        } else {
            no_alocacao->inicio_segmento = no_alocacao->inicio_segmento + tamanho;
            no_alocacao->tamanho_segmento = no_alocacao->tamanho_segmento - tamanho;
        }
    }
}

void desalocar_memoria(Lista* heap, int endereco, int tamanho) {
    No* novo_heap = calloc(1, sizeof(No));

    if (novo_heap == NULL) {
        printf("Não foi possível alocar novo heap");
        exit(1);
    }

    //inicializando um novo nó
    novo_heap->inicio_segmento = endereco;
    novo_heap->tamanho_segmento = tamanho;
    novo_heap->anterior = NULL;
    novo_heap->proximo = NULL;

    //inserindo o nó na lista
    inserir_no(heap, novo_heap);

    //verificar se é possível juntar os segmentos
    juntar_segmentos_se_possivel(heap);
}

void realocar_memoria(Lista* heap, int endereco, int tamanho, int novo_tamanho) {
    if (novo_tamanho < tamanho) {
        //desalocar memória excedente
        desalocar_memoria(heap, endereco + novo_tamanho, tamanho - novo_tamanho);
    } else if (esta_livre(heap, endereco + tamanho, endereco + novo_tamanho) == 1) {
        No* atual;
        for (atual = heap->inicio; atual != NULL; atual = atual->proximo) {
            //alterações no segmento
            if (endereco + tamanho >= atual->inicio_segmento && endereco + tamanho <= atual->inicio_segmento + atual->tamanho_segmento) {
                if (atual->tamanho_segmento - (novo_tamanho - tamanho) <= 0) {
                    remover_no(heap, atual);
                    break;
                } else {
                    atual->inicio_segmento = endereco + novo_tamanho;
                    atual->tamanho_segmento = atual->tamanho_segmento - (novo_tamanho - tamanho);
                }
            }
        }
    } else {
        //se não tiver espaço livre no endereço atual, desalocar e alocar de novo
        desalocar_memoria(heap, endereco, tamanho);
        alocar_memoria(heap, novo_tamanho);
    }
}
