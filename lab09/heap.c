#include <stdlib.h>
#include <stdio.h>

#include "heap.h"

void troca(Item *a, Item *b) {
    Item t = *a;
    *a = *b;
    *b = t;
}

FilaPrioridade* criar_fila_prio(int tam) {
    FilaPrioridade* fila_prio = malloc(sizeof(FilaPrioridade));

    fila_prio->vetor = malloc(tam * sizeof(Item));
    fila_prio->n = 0;
    fila_prio->tamanho = tam;
    
    return fila_prio;
}

void insere(FilaPrioridade* fila_prio, Item item) {
    fila_prio->vetor[fila_prio->n] = item;
    fila_prio->n++;
    sobe_no_heap(fila_prio, fila_prio->n - 1);
}

void sobe_no_heap(FilaPrioridade* fila_prio, int k) {
    if (k > 0 && fila_prio->vetor[PAI(k)].chave < fila_prio->vetor[k].chave) {
        troca(&fila_prio->vetor[k], &fila_prio->vetor[PAI(k)]);
        sobe_no_heap(fila_prio, PAI(k));
    }
}
