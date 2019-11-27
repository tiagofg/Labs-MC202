#include "grafo.h"

Grafo* criar_grafo(int num_vertices) {
    Grafo* grafo = malloc(sizeof(Grafo));

    grafo->num_vertices = num_vertices;
    grafo->adjacencia_vertices = malloc(num_vertices * sizeof(Lista));

    for (int i = 0; i < num_vertices; i++) {
        grafo->adjacencia_vertices[i] = criar_lista();
    }

    return grafo;
}

void destroi_grafo(Grafo* grafo) {
    for (int i = 0; i < num_vertices; i++) {
        destruir_lista(obter_iterador(grafo->adjacencia_vertices[i]));
    }

    free(grafo);
}

void insere_aresta(Grafo* grafo, int u, int v);

Lista* obter_adjacencia(int num_vertice) {
    return grafo->adjacencia_vertices[num_vertice];
}
