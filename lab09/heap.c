#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "heap.h"

void troca(Item *a, Item *b) { //trocar itens
    Item t = *a;
    *a = *b;
    *b = t;
}


Item* criar_item(char* identificador) { //criar novo item
    Item* item = calloc(1, sizeof(Item));

    if (item == NULL) {
        printf("Não foi possível alocar item \n");
        exit(1);
    }

    item->identificador = calloc(5, sizeof(char));

    if (item->identificador == NULL) {
        printf("Não foi possível alocar identificador \n");
        exit(1);
    }

    strcpy(item->identificador, identificador);

    return item;
}

FilaPrioridade* criar_fila_prio(int tam) { //criar fila de prioridade
    FilaPrioridade* fila_prio = calloc(1, sizeof(FilaPrioridade));

    if (fila_prio == NULL) {
        printf("Não foi possível alocar fila de prioridade \n");
        exit(1);
    }

    fila_prio->vetor = calloc(tam, sizeof(Item));

    if (fila_prio->vetor == NULL) {
        printf("Não foi possível alocar vetor de heap \n");
        exit(1);
    }

    fila_prio->n = 0;
    fila_prio->tamanho = tam;

    return fila_prio;
}

void destruir_fila_prio(FilaPrioridade* fila_prio) { //destruir fila de prioridade    
    for (int i = 0; i < fila_prio->n; i++) {
        free(fila_prio->vetor[i].identificador);
    }

    free(fila_prio->vetor);

    free(fila_prio);
}

void inserir(FilaPrioridade* fila_prio, Item item, int tipo) { //inserir item no final da fila
    fila_prio->vetor[fila_prio->n] = item;
    fila_prio->n++;

    sobe_no_heap(fila_prio, fila_prio->n - 1, tipo);
}

void sobe_no_heap(FilaPrioridade* fila_prio, int k, int tipo) {
    //subir item no heap até ordenar
    if (tipo == MAX) {
        if (k > 0 && strcmp(fila_prio->vetor[PAI(k)].identificador, fila_prio->vetor[k].identificador) < 0) {
            troca(&fila_prio->vetor[k], &fila_prio->vetor[PAI(k)]);
            sobe_no_heap(fila_prio, PAI(k), tipo);
        }
    } else if (tipo == MIN) {
        if (k > 0 && strcmp(fila_prio->vetor[PAI(k)].identificador, fila_prio->vetor[k].identificador) > 0) {
            troca(&fila_prio->vetor[k], &fila_prio->vetor[PAI(k)]);
            sobe_no_heap(fila_prio, PAI(k), tipo);
        }
    }
}

void desce_no_heap(FilaPrioridade* fila_prio, int k, int tipo) {
    //colocar item no final do heap para remover

    if (F_ESQ(k) < fila_prio->n) {
        if (tipo == MAX) {
            int maior_filho = F_ESQ(k);

            if (F_DIR(k) < fila_prio->n && strcmp(fila_prio->vetor[F_ESQ(k)].identificador, fila_prio->vetor[F_DIR(k)].identificador) < 0) {
                maior_filho = F_DIR(k);
            }

            if (strcmp(fila_prio->vetor[k].identificador, fila_prio->vetor[maior_filho].identificador) < 0) {
                troca(&fila_prio->vetor[k], &fila_prio->vetor[maior_filho]);
                desce_no_heap(fila_prio, maior_filho, MAX);
            }
        } else if (tipo == MIN) {
            int menor_filho = F_ESQ(k);

            if (F_DIR(k) < fila_prio->n && strcmp(fila_prio->vetor[F_ESQ(k)].identificador, fila_prio->vetor[F_DIR(k)].identificador) > 0) {
                menor_filho = F_DIR(k);
            }

            if (strcmp(fila_prio->vetor[k].identificador, fila_prio->vetor[menor_filho].identificador) > 0) {
                troca(&fila_prio->vetor[k], &fila_prio->vetor[menor_filho]);
                desce_no_heap(fila_prio, menor_filho, MIN);
            }
        }
    }
}

Item extrai_raiz(FilaPrioridade* fila_prio, int tipo) {
    //retornar raiz do max-heap ou do min-heap
    Item item = fila_prio->vetor[0];

    troca(&fila_prio->vetor[0], &fila_prio->vetor[fila_prio->n - 1]);
    fila_prio->n--;
    
    if (tipo == MAX) {
        desce_no_heap(fila_prio, 0, MAX);
    } else if (tipo == MIN) {
        desce_no_heap(fila_prio, 0, MIN);
    } 

    return item;
}

int obter_tamanho_atual(FilaPrioridade* fila_prio) {
    return fila_prio->n;
}

Item obter_raiz(FilaPrioridade* fila_prio) {
    return fila_prio->vetor[0];
}

char* obter_identificador(Item item) {
    return item.identificador;
}