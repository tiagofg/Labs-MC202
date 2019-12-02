#ifndef FILA_H
#define FILA_H
#endif 

typedef struct Item {
    int vertice;

    struct Item* proximo;
} Item;

typedef struct {
    Item* inicio;
    Item* fim;
} Fila;

Fila* criar_fila();

void destroi_fila(Fila* f);

void enfileira(Fila* fila, int v);

int desenfileira(Fila* fila);

int fila_vazia(Fila* fila);