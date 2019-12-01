#ifndef GRAFO_H
#define GRAFO_H

#include "lista.h"
#endif // GRAFO_H

typedef struct {
    Lista** vertices;
    int num_vertices;
} Grafo;

Grafo* criar_grafo(int num_vertices);

void destroi_grafo(Grafo* grafo);

void insere_aresta(Grafo* grafo, int origem, int destino, int variacao, char elevador);

Lista* obter_adjacencia(Grafo* grafo, int num_vertice);
