#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "grafo.h"
#include "fila.h"

int* busca_em_largura(Grafo* grafo, int s) {
    int v;
    int *pai = malloc(grafo->num_vertices * sizeof(int));
    int *visitado = malloc(grafo->num_vertices * sizeof(int));
    int andares = (grafo->num_vertices - 2) / 4;
    Fila* f = criar_fila();

    for (v = 0; v < grafo->num_vertices; v++) {
        pai[v] = -1;
        visitado[v] = 0;
    }

    enfileira(f, s);
    pai[s] = andares;
    visitado[s] = 1;


    while(fila_vazia(f) == 0) {
        v = desenfileira(f);
        for (int w = 0; w < grafo->num_vertices; w++) {
            if (esta_na_lista(obter_adjacencia(grafo, v), w) == 1 && visitado[w] == 0) {
                visitado[w] = 1;
                pai[w] = pai[v] + get_variacao(obter_adjacencia(grafo, v), w);
                enfileira(f, w);
            }
        }    
    }

    // destroi_fila(f);
    free(visitado);

    return pai;
}

void inserir_arestas(Grafo* grafo, int origens[4], int destino, int variacao, char elevador, char* elevadores) {
    for (int i = 0; i < 4; i++) {
        if (origens[i] != -1) {
            insere_aresta(grafo, origens[i], destino, variacao, elevador, elevadores);
        }
    }    
}

void inserir_vertice(Grafo* grafo, int numero, int variacao, char elevador, int pais[4], int aux[4], int num_aux, char* elevadores) {
    inserir_arestas(grafo, pais, numero, variacao, elevador, elevadores);
    elevadores[numero] = elevador;
    aux[num_aux] = numero;
}

int main()
{
    int m, n, x, y, w, z;

    scanf("%d\n", &m);

    for (int i = 0; i < m; i++) {
        scanf("%d\n", &n);

        int qtde_vertices = 4 * n + 2;

        Grafo* grafo = criar_grafo(qtde_vertices);

        int num_vertice = 1;

        int pais[4];
        pais[0] = 0;
        for (int j = 1; j < 4; j++) {
            pais[j] = -1;
        }

        int aux[4];

        char* elevadores = calloc(qtde_vertices, sizeof(char));
        char* botoes = calloc(qtde_vertices, sizeof(char));

        for (int j = 0; j < n; j++) {
            scanf("%d %d %d %d\n", &x, &y, &w, &z);
            
            inserir_vertice(grafo, num_vertice, x * -1, 'A', pais, aux, 0, elevadores);
            botoes[num_vertice] = 'X';
            num_vertice++;

            inserir_vertice(grafo, num_vertice, y, 'A', pais, aux, 1, elevadores);
            botoes[num_vertice] = 'Y';
            num_vertice++;

            inserir_vertice(grafo, num_vertice, w * -1, 'B', pais, aux, 2, elevadores);
            botoes[num_vertice] = 'W';
            num_vertice++;

            inserir_vertice(grafo, num_vertice, z, 'B', pais, aux, 3, elevadores);
            botoes[num_vertice] = 'Z';
            num_vertice++;

            for (int j = 0; j < 4; j++) {
                pais[j] = aux[j];                
            }
        }

        inserir(obter_adjacencia(grafo, num_vertice), num_vertice, 0, 0, ' ');
        inserir_arestas(grafo, pais, num_vertice, 0, ' ', elevadores);

        // for (int i = 0; i < qtde_vertices; i++) {
        //     printf("%d ", i);
        //     imprimir_lista(obter_adjacencia(grafo, i));
        // }

        int* menor_caminho = busca_em_largura(grafo, 1);

        for (int i = 0; i < qtde_vertices; i++) {
            printf("menor_caminho[%d]: %d \n", i, menor_caminho[i]);
        }

        destroi_grafo(grafo);        
    }

   return EXIT_SUCCESS;
}
