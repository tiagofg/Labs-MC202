#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "pilha.h"

Pilha* criar_pilha() {
    Pilha* pilha = malloc(sizeof(Pilha));
    pilha->topo = NULL;

    return pilha;
}

void empilhar(Pilha* pilha, int num) {
    No* novo = malloc(sizeof(No));
    novo->dado = num;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
}

int desempilhar(Pilha* pilha) {
    No* topo = pilha->topo;
    int dado_topo = topo->dado;

    pilha->topo = pilha->topo->proximo;
    free(topo);

    return dado_topo;
}

void remover_menor_dado(Pilha* pilha) {
    Pilha* pilha_aux = malloc(sizeof(Pilha));
    No* aux = pilha->topo;
    int menor_dado = INT_MAX;
    int dado_desempilhado;

    while (aux != NULL) {
        dado_desempilhado = desempilhar(pilha);

        if (dado_desempilhado < menor_dado) {
            menor_dado = dado_desempilhado;
        }

        empilhar(pilha_aux, dado_desempilhado);
        aux = pilha->topo;
    }

    aux = pilha_aux->topo;

    while (aux != NULL) {
        dado_desempilhado = desempilhar(pilha_aux);

        if (dado_desempilhado != menor_dado) {
            empilhar(pilha, dado_desempilhado);
        }

        aux = pilha_aux->topo;
    }

    // printf("Pilha: \n");
    // imprimir_pilha(pilha);
    //
    // printf("Pilha_aux: \n");
    // imprimir_pilha(pilha_aux);

    // free(pilha_aux);
}

void imprimir_pilha(Pilha* pilha) {
    No* aux = pilha->topo;

    while (aux != NULL) {
        printf("%d", aux->dado);
        aux = aux->proximo;
    }

    printf("\n");
}

void limpar_pilha(Pilha* pilha) {
    No* aux = pilha->topo;

    while (aux != NULL) {
        desempilhar(pilha);
        aux = pilha->topo;
    }

}
