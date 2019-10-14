#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilha.h"

Pilha* criar_pilha() {
    Pilha* pilha = malloc(sizeof(Pilha));
    pilha->topo = NULL;

    return pilha;
}

void empilhar(Pilha* pilha, char num) {
    No_pilha* novo = malloc(sizeof(No_pilha));
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
            printf("Inserir %c na pilha \n", aux_lista->dado);
            empilhar(pilha, aux_lista->dado);
        }

        aux_lista = aux_lista->proximo;
    }
    
}

void find_maior_valor(Pilha* pilha, Lista* lista, int n) {  
    // No_lista* no_maior_valor = NULL;
    // No_lista* no_aux = lista->inicio;
    // int maior_valor = 0;
    int valor_sequencia = 0;
    // Pilha* pilha_maior_sequencia = criar_pilha();

    // while (no_aux != NULL)
    // {
    //     no_aux->no_removido = 1;
    //     printf("%c \n", no_aux->dado);

        inserir_lista_na_pilha(pilha, lista);
        inverter_pilha(pilha);
        // imprimir_pilha(pilha);

        valor_sequencia = get_valor_sequencia(pilha);
        printf("Valor sequência: %d \n", valor_sequencia);

        // if (valor_sequencia > maior_valor) {
        //     maior_valor = valor_sequencia;
        //     *pilha_maior_sequencia = *pilha;
        //     no_maior_valor = no_aux;
        // }

    //     no_aux->no_removido = 0;
    //     no_aux = no_aux->proximo;
    // }

    // remover_no(lista, no_maior_valor);
}

int get_valor_sequencia(Pilha* pilha) {
    Pilha* pilha_aux = criar_pilha();
    *pilha_aux = *pilha;
    char* sequencia = malloc(pilha->tamanho * sizeof(char));
    No_pilha* aux = pilha->topo;
    int tamanho_sequencia = 0;

    while (aux != NULL)
    {
        tamanho_sequencia = strlen(sequencia);
        printf("%d \n", tamanho_sequencia);
        sequencia[tamanho_sequencia] = desempilhar(pilha);
        sequencia[tamanho_sequencia + 1] = '\0';
        aux = pilha->topo;
    }    

    return atoi(sequencia);
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
