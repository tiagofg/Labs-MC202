#include <stdio.h>
#include <stdlib.h>

#include "grafo.h"

// if (notas == NULL) {
//     printf("Nao ha memoria suficente!\n");
//     exit(1);
// } exemplo erro de alocação de memória    

void inserir_arestas(Grafo* grafo, int origens[4], int destino, int variacao, char elevador) {
    for (int i = 0; i < 4; i++) {
        if (origens[i] != -1) {
            insere_aresta(grafo, origens[i], destino, variacao, elevador);
        }
    }    
}

void inserir_vertice(Grafo* grafo, int numero, int variacao, char elevador, int pais[4], int aux[4], int num_aux) {
    inserir(obter_adjacencia(grafo, numero), numero, 0, variacao, elevador);
    inserir_arestas(grafo, pais, numero, variacao, elevador);
    aux[num_aux] = numero;
}

int main()
{
    int m, n, x, y, w, z;

    scanf("%d\n", &m);

    for (int i = 0; i < m; i++) {
        scanf("%d\n", &n);

        Grafo* grafo = criar_grafo(4 * n + 1);
        inserir(obter_adjacencia(grafo, 0), 0, 0, 0, ' ');

        int num_vertice = 1;

        int pais[4];
        for (int j = 0; j < 4; j++) {
            pais[j] = -1;
        }

        int aux[4];

        for (int j = 0; j < n; j++) {
            scanf("%d %d %d %d\n", &x, &y, &w, &z);
            
            inserir_vertice(grafo, num_vertice, x * -1, 'A', pais, aux, 0);
            num_vertice++;

            inserir_vertice(grafo, num_vertice, y, 'A', pais, aux, 1);
            num_vertice++;

            inserir_vertice(grafo, num_vertice, w * -1, 'B', pais, aux, 2);
            num_vertice++;

            inserir_vertice(grafo, num_vertice, z, 'B', pais, aux, 3);
            num_vertice++;

            for (int j = 0; j < 4; j++) {
                pais[j] = aux[j];                
            }
        }

        for (int i = 0; i < 4 * n + 1; i++) {
            printf("%d ", i);
            imprimir_lista(obter_adjacencia(grafo, i));
        }

        // destroi_grafo(grafo);        
    }

   return EXIT_SUCCESS;
}
