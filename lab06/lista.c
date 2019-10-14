#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "lista.h"

Lista* criar_lista() {
    Lista* lista = calloc(1, sizeof(Lista)); //alocando memória da lista

    //setando ínicio da lista
    lista->inicio = NULL;

    return lista;
}

void inserir_no_inicio(Lista* lista, char dado){
    No_lista* no = calloc(1, sizeof(No_lista));
    No_lista* inicio = lista->inicio;

    no->proximo = inicio;
    no->dado = dado;
    no->no_removido = 0;
    lista->inicio = no;
}

void remover_no(Lista* lista, No_lista* no) {
    No_lista* anterior = lista->inicio;
    No_lista* proximo = no->proximo;

    if (lista->inicio == no){
        lista->inicio = proximo;
    } else {
        while (anterior->proximo != NULL) {
            if (anterior->proximo == no) {
                anterior->proximo = proximo;
                break;
            }

            anterior = anterior->proximo;
        }
    }

    free(no);
}

void limpar_lista(Lista* lista) {
    No_lista* aux = lista->inicio;

    while (aux != NULL) {
        remover_no(lista, aux);
        aux = aux->proximo;
    }

}
