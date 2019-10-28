#ifndef HEAP_H
#define HEAP_H
#define PAI(i) ((i-1)/2)

#endif

typedef struct {
    char* identificador;
    int chave;
} Item;

typedef struct {
    Item* vetor;
    int n, tamanho;
} FilaPrioridade;

void troca(Item *a, Item *b);

FilaPrioridade* criar_fila_prio(int tam);

void insere(FilaPrioridade* fila_prio, Item item);

void sobe_no_heap(FilaPrioridade* fila_prio, int k);
