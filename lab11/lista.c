#include "lista.h"

Lista* criar_lista() {
    Lista* lista = malloc(sizeof(Lista)); //alocando memória da lista

    No* no = malloc(sizeof(No)); //alocando memória do nó

    //inicializando nó
    no->x = 0;
    no->y = 0;
    no->w = 0;
    no->z = 0;
    no->proximo = NULL;

    //setando ínicio da lista
    lista->inicio = no;
    lista->tamanho = 0;

    return lista;
}

void destruir_lista(No* no) {
    while (no != NULL) {
        destruir_lista(no->proximo);
        free(no);
    }
}

No* inserir(Lista* lista, int valor) {
    No* novo = malloc(sizeof(No));
    novo->v = v;
    novo->prox = lista;
    return novo;
}

No* obter_iterador(Lista* lista) {
    return lista->inicio;
}

No* avancar_posicao(No* iterador) {
    return iterador->proximo;
}

int eh_vazia(Lista* lista) {
    if (lista->tamanho == 0) {
        return 1;
    }

    return 0;
}
