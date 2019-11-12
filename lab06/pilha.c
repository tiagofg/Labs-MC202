#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilha.h"

Pilha* criar_pilha() {
    Pilha* pilha = calloc(1, sizeof(Pilha));
    pilha->topo = NULL;

    return pilha;
}

void empilhar(Pilha* pilha, char num) {
    No_pilha* novo = calloc(1, sizeof(No_pilha));
    novo->dado = num;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
    pilha->tamanho++;
}

int desempilhar(Pilha* pilha) {
    No_pilha* topo = pilha->topo;
    int dado_topo = topo->dado;

    pilha->topo = pilha->topo->proximo;
    pilha->tamanho--;
    free(topo);

    return dado_topo;
}

void inverter_pilha(Pilha* pilha) {
    Pilha* pilha_invertida = criar_pilha();
    No_pilha* aux = pilha->topo;

    while (aux != NULL) {
        empilhar(pilha_invertida, desempilhar(pilha));
        aux = pilha->topo;
    }

    *pilha = *pilha_invertida;
}

void inserir_lista_na_pilha(Pilha* pilha, Lista* lista) {
    No_lista* aux_lista = lista->inicio;

    while (aux_lista != NULL)
    {
        if (aux_lista->no_removido != 1) {
            empilhar(pilha, aux_lista->dado);
        }

        aux_lista = aux_lista->proximo;
    }

}

void find_maior_valor(Pilha* pilha, Lista* lista, int n) {
    No_lista* no_remocao = malloc(sizeof(No_lista));
    No_lista* no_aux;
    long long int maior_valor;
    long long int valor_sequencia;
    // Pilha* pilha_maior_sequencia = criar_pilha();
    char* sequencia;

    for (int i = 0; i < n; i++) {
        no_remocao = malloc(sizeof(No_lista));
        no_aux = lista->inicio;
        maior_valor = 0;
        valor_sequencia = 0;

        while (no_aux != NULL)
        {
            no_aux->no_removido = 1;

            inserir_lista_na_pilha(pilha, lista);
            sequencia = calloc(pilha->tamanho, sizeof(char));

            valor_sequencia = get_valor_sequencia(pilha, sequencia);

            if (valor_sequencia > maior_valor) {
                maior_valor = valor_sequencia;
                no_remocao = no_aux;
            }

            no_aux->no_removido = 0;
            no_aux = no_aux->proximo;
        }

        remover_no(lista, no_remocao);
    }

    printf("%lli\n", maior_valor);
    // free(sequencia);
}

long long int get_valor_sequencia(Pilha* pilha, char* sequencia) {
    Pilha* pilha_aux = criar_pilha();
    *pilha_aux = *pilha;
    No_pilha* aux = pilha->topo;
    long int tamanho_sequencia = 0;
    // long int valor_sequencia = 0;

    while (aux != NULL)
    {
        tamanho_sequencia = strlen(sequencia);
        sequencia[tamanho_sequencia] = desempilhar(pilha);
        // sequencia[tamanho_sequencia + 1] = '\0';
        aux = pilha->topo;
    }

    return atoll(sequencia);
}


void imprimir_pilha(Pilha* pilha) {
    No_pilha* aux = pilha->topo;

    while (aux != NULL) {
        printf("%c", aux->dado);
        aux = aux->proximo;
    }

    printf("\n");
}

void limpar_pilha(Pilha* pilha) {
    No_pilha* aux = pilha->topo;

    while (aux != NULL) {
        desempilhar(pilha);
        aux = pilha->topo;
    }

}
