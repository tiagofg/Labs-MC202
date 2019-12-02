#include <stdio.h>
#include <stdlib.h>

#include "grafo.h"

Grafo* criar_grafo(int num_vertices) {
    Grafo* grafo = malloc(sizeof(Grafo));

    grafo->num_vertices = num_vertices;
    grafo->vertices = (Lista**) malloc(num_vertices * sizeof(Lista*));

    for (int i = 0; i < num_vertices; i++) {
        grafo->vertices[i] = criar_lista();
    }

    return grafo;
}

void destroi_grafo(Grafo* grafo) {
    for (int i = 0; i < grafo->num_vertices; i++) {
        destruir_lista(grafo->vertices[i]);
        free(grafo->vertices[i]);
    }

    free(grafo);
}

void insere_aresta(Grafo* grafo, int origem, int destino, int variacao, char elevador_destino, char* elevadores) {
    Lista* adjacencia = grafo->vertices[origem];

    if (elevadores[origem] == elevador_destino) {
        // printf("Inserir %d na lista de adjacencia de %d com peso 1 \n", destino, origem);
        inserir(adjacencia, destino, 1, variacao, elevador_destino);
    } else {
        // printf("Inserir %d na lista de adjacencia de %d com peso 2 \n", destino, origem);
        inserir(adjacencia, destino, 2, variacao, elevador_destino);
    }
}

Lista* obter_adjacencia(Grafo* grafo, int num_vertice) {
    return grafo->vertices[num_vertice];
}
