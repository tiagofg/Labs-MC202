#ifndef GRAFO_H
#define GRAFO_H

#include "lista.h"
#endif // GRAFO_H

typedef struct {
    Lista* adjacencia;
    int num_andares;
} Grafo;

Grafo* criar_grafo(int num_andares);

void destroi_grafo(Grafo* grafo);

void insere_aresta(Grafo* grafo, int u, int v);
