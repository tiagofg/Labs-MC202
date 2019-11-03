#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "heap.h"

void troca(Item *a, Item *b) {
    Item t = *a;
    *a = *b;
    *b = t;
}

int gerar_chave(char* identificador) {
    int chave = 0;
    int tamanho = strlen(identificador);
    char* string_identificador = malloc(tamanho * sizeof(char));
    char* string_chave = malloc(tamanho * sizeof(char));

    for (int i = 0; i < tamanho; i++) {
        sprintf(&string_identificador[i], "%d", (int) identificador[i]);
        strcat(string_chave, &string_identificador[i]);
    }

    chave = atoi(string_chave);

    free(string_chave);
    free(string_identificador);

    return chave;
}

Item* criar_item(char* identificador) {
    Item* item = malloc(sizeof(Item));

    item->identificador = malloc(5 * sizeof(char));
    strcpy(item->identificador, identificador);
    item->chave = gerar_chave(item->identificador);

    return item;
}

FilaPrioridade* criar_fila_prio(int tam) {
    FilaPrioridade* fila_prio = malloc(sizeof(FilaPrioridade));

    fila_prio->vetor = malloc(tam * sizeof(Item));
    fila_prio->n = 0;
    fila_prio->tamanho = tam;

    return fila_prio;
}

void inserir(FilaPrioridade* fila_prio, Item item, int tipo) {
    fila_prio->vetor[fila_prio->n] = item;
    fila_prio->n++;

    if (tipo == MAX) {
        sobe_no_heap(fila_prio, fila_prio->n - 1, tipo);
    } else if (tipo == MIN) {
        sobe_no_heap(fila_prio, fila_prio->n - 1, tipo);
    }
}

void sobe_no_heap(FilaPrioridade* fila_prio, int k, int tipo) {
    if (tipo == MAX) {
        if (k > 0 && fila_prio->vetor[PAI(k)].chave < fila_prio->vetor[k].chave) {
            troca(&fila_prio->vetor[k], &fila_prio->vetor[PAI(k)]);
            sobe_no_heap(fila_prio, PAI(k), tipo);
        }
    } else if (tipo == MIN) {
        if (k > 0 && fila_prio->vetor[PAI(k)].chave > fila_prio->vetor[k].chave) {
            troca(&fila_prio->vetor[k], &fila_prio->vetor[PAI(k)]);
            sobe_no_heap(fila_prio, PAI(k), tipo);
        }
    }
}

void desce_no_heap(FilaPrioridade* fila_prio, int k) {
    int maior_filho;

    if (F_ESQ(k) < fila_prio->n) {
        maior_filho = F_ESQ(k);

        if (F_DIR(k) < fila_prio->n && fila_prio->vetor[F_ESQ(k)].chave < fila_prio->vetor[F_DIR(k)].chave) {
            maior_filho = F_DIR(k);
        }

        if (fila_prio->vetor[k].chave < fila_prio->vetor[maior_filho].chave) {
            troca(&fila_prio->vetor[k], &fila_prio->vetor[maior_filho]);
            desce_no_heap(fila_prio, maior_filho);
        }
    }
}

Item extrai_maximo(FilaPrioridade* fila_prio) {
    int j, max = 0;

    for (j = 1; j < fila_prio->n; j++) {
        if (fila_prio->vetor[max].chave < fila_prio->vetor[j].chave) {
            max = j;
        }    
    }
    troca(&(fila_prio->vetor[max]), &(fila_prio->vetor[fila_prio->n-1]));
    
    fila_prio->n--;

    return fila_prio->vetor[fila_prio->n];
}

Item extrai_minimo(FilaPrioridade* fila_prio) {
    int j, min = 0;

    for (j = 1; j < fila_prio->n; j++) {
        if (fila_prio->vetor[min].chave > fila_prio->vetor[j].chave) {
            min = j;
        }    
    }
    troca(&(fila_prio->vetor[min]), &(fila_prio->vetor[fila_prio->n-1]));
    
    fila_prio->n--;

    return fila_prio->vetor[fila_prio->n];
}
