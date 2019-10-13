#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

Pilha* inverter_pilha(Pilha* pilha) {
    Pilha* pilha_aux = criar_pilha();
    No* aux = pilha->topo;

    while (aux != NULL) {
        empilhar(pilha_aux, desempilhar(pilha));
        aux = pilha->topo;
    }

    return pilha_aux;
}

void find_maior_valor(Pilha* pilha, int n) {
    // Pilha* pilha_aux = criar_pilha();
    // No* aux = pilha->topo;
    // int menor_dado = INT_MAX;
    // int dado_desempilhado;

    // while (aux != NULL) {
    //     dado_desempilhado = desempilhar(pilha);

    //     if (dado_desempilhado < menor_dado) {
    //         menor_dado = dado_desempilhado;
    //     }

    //     empilhar(pilha_aux, dado_desempilhado);
    //     aux = pilha->topo;
    // }

    // aux = pilha_aux->topo;

    // while (aux != NULL) {
    //     dado_desempilhado = desempilhar(pilha_aux);

    //     if (dado_desempilhado != menor_dado) {
    //         empilhar(pilha, dado_desempilhado);
    //     }

    //     aux = pilha_aux->topo;
    // }

    // free(pilha_aux);

    printf("Valor sequencia: %d \n", get_valor_sequencia(pilha));
}

int get_valor_sequencia(Pilha* pilha) {
    Pilha* pilha_aux = malloc(sizeof(pilha));
    *pilha_aux = *pilha;
    pilha_aux = inverter_pilha(pilha_aux);
    // No* aux = pilha_aux->topo;
    // char* sequencia = malloc(50 * sizeof(char));
    // int tamanho_sequencia;

    imprimir_pilha(pilha_aux);

    // while (aux != NULL)
    // {
    //     // tamanho_sequencia = strlen(sequencia);
    //     // sequencia[tamanho_sequencia] = (char) desempilhar(pilha_aux) + 48;
    //     // sequencia[tamanho_sequencia] = '\0';
    //     desempilhar(pilha_aux);
    //     aux = pilha_aux->topo;
    // }

    // return atoi(sequencia);  
    return 0;
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
