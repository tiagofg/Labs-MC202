#include <stdio.h>
#include <stdlib.h>

#include "grafo.h"

// if (notas == NULL) {
//     printf("Nao ha memoria suficente!\n");
//     exit(1);
// } exemplo erro de alocação de memória    

int main()
{
    int m, n, x, y, w, z;

    scanf("%d\n", &m);

    for (int i = 0; i < m; i++) {
        scanf("%d\n", &n);

        for (int j = 0; j < n; j++) {
            scanf("%d %d %d %d\n", &x, &y, &w, &z);
        }
    }

   return EXIT_SUCCESS;
}
