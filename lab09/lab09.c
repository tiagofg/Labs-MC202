#include <stdlib.h>
#include <stdio.h>

#include "heap.h"

int main()
{
    int n, m;
    Item* item;
    char* identificador = malloc(5 * sizeof(char));
    FilaPrioridade* heap_max;
    FilaPrioridade* heap_min;
    int inserir_max;
    int inserir_min;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &m);
        heap_max = criar_fila_prio(m);
        heap_min = criar_fila_prio(m);

        inserir_max = 1;
        inserir_min = 0;

        for (int j = 0; j < m; j++) {
            scanf("%s\n", identificador);
            item = criar_item(identificador);

            //extrair minimo do heap max e maximo do heap minimo

            if (inserir_max == 1) {
                inserir(heap_max, item, MAX);
                inserir_max = 0;
                inserir_min = 1;
            } else if (inserir_min == 1) {
                inserir(heap_max, item, MAX);
                inserir_max = 1;
                inserir_min = 0;
            }

            if (j % 5 == 0 || j == m - 1) {
                if (heap_max->n % 2 != 0) {
                    printf("%d %s\n", i + 1, heap_max->vetor[0].identificador);
                }

                if (heap_min->n % 2 != 0) {
                    printf("%d %s\n", i + 1, heap_min->vetor[0].identificador);
                }
            }
        }

        free(heap_max);
        free(heap_min);
   }

   return EXIT_SUCCESS;

}
