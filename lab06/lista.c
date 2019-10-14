#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "lista.h"

Lista* criar_lista() {
    Lista* lista = malloc(sizeof(Lista)); //alocando memória da lista

    //setando ínicio da lista
    lista->inicio = NULL;

    return lista;
}

void inserir_no(Lista* lista, char dado){
    No_lista* anterior = lista->inicio;
    No_lista* no = malloc(sizeof(No_lista));
  
    while (anterior != NULL && anterior->proximo != NULL){
        anterior = anterior->proximo;
    }

    no->proximo = NULL;
    no->dado = dado;
    no->no_removido = 0;

    if (anterior != NULL) {
        anterior->proximo = no;
    } else {
        lista->inicio = no;
    }
}

void remover_no(Lista* lista, No_lista* no) {
    No_lista* anterior = lista->inicio;

    if (lista->inicio == no){
        lista->inicio = no->proximo;
    } else {
        while (anterior->proximo != no) {
            anterior = anterior->proximo;
        }
        
        if (anterior->proximo != NULL && anterior->proximo->proximo != NULL) {
            anterior->proximo = anterior->proximo->proximo;
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
