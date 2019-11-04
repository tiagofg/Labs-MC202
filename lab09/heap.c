#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "heap.h"

void troca(Item *a, Item *b) { //trocar itens
    Item t = *a;
    *a = *b;
    *b = t;
}

int gerar_chave(char* identificador) { //gerar chave pegando o código ascii de cada caractere
    int chave = 0;
    int tamanho = strlen(identificador);
    char* string_identificador = calloc(2 * tamanho + 1, sizeof(char));
    char* string_chave = calloc(2 * tamanho + 1, sizeof(char));

    for (int i = 0; i < tamanho; i++) {
        sprintf(&string_identificador[i], "%d", (int) identificador[i]);
        strcat(string_chave, &string_identificador[i]);
    }

    chave = atoi(string_chave);

    free(string_chave);
    free(string_identificador);

    return chave;
}

Item* criar_item(char* identificador) { //criar novo item
    Item* item = calloc(1, sizeof(Item));

    item->identificador = calloc(5, sizeof(char));
    strcpy(item->identificador, identificador);
    item->chave = gerar_chave(item->identificador);

    return item;
}

FilaPrioridade* criar_fila_prio(int tam) { //criar fila de prioridade
    FilaPrioridade* fila_prio = calloc(1, sizeof(FilaPrioridade));

    fila_prio->vetor = calloc(tam, sizeof(Item));
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

void desce_no_max_heap(FilaPrioridade* fila_prio, int k) {
    //colocar item no final do max-heap para remover
    int maior_filho;

    if (F_ESQ(k) < fila_prio->n) {
        maior_filho = F_ESQ(k);

        if (F_DIR(k) < fila_prio->n && fila_prio->vetor[F_ESQ(k)].chave < fila_prio->vetor[F_DIR(k)].chave) {
            maior_filho = F_DIR(k);
        }

        if (fila_prio->vetor[k].chave < fila_prio->vetor[maior_filho].chave) {
            troca(&fila_prio->vetor[k], &fila_prio->vetor[maior_filho]);
            desce_no_max_heap(fila_prio, maior_filho);
        }
    }
}

void desce_no_min_heap(FilaPrioridade* fila_prio, int k) {
    //colocar item no final do min-heap para remover
    int menor_filho;

    if (F_ESQ(k) < fila_prio->n) {
        menor_filho = F_ESQ(k);

        if (F_DIR(k) < fila_prio->n && fila_prio->vetor[F_ESQ(k)].chave > fila_prio->vetor[F_DIR(k)].chave) {
            menor_filho = F_DIR(k);
        }

        if (fila_prio->vetor[k].chave > fila_prio->vetor[menor_filho].chave) {
            troca(&fila_prio->vetor[k], &fila_prio->vetor[menor_filho]);
            desce_no_min_heap(fila_prio, menor_filho);
        }
    }
}

Item extrai_raiz(FilaPrioridade* fila_prio, int tipo) {
    //retornar raiz do max-heap ou do min-heap
    Item item = fila_prio->vetor[0];

    troca(&fila_prio->vetor[0], &fila_prio->vetor[fila_prio->n - 1]);
    fila_prio->n--;
    
    if (tipo == MAX) {
        desce_no_max_heap(fila_prio, 0);
    } else if (tipo == MIN) {
        desce_no_min_heap(fila_prio, 0);
    } 

    return item;
}
