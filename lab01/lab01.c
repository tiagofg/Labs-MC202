#include <stdio.h>
#include <stdlib.h>

void printarMatriz(float matriz[100][100], int m, int n){
    int i, j;

    for(i = 0; i < m; i ++) {
        for(j = 0; j < n; j++) {
            printf("%.1f ", matriz[i][j]);
        }
        printf("\n");
    }
}

void gerarMatrizCaracol(float vetor[100], int m, int n){
    float matriz[m][n];
    int i = m-1, j = n-1, direita = n-1, esquerda = 0, topo = 0, base = m-1, indiceVetor = 0;
    while (indiceVetor < m * n) {
        while (i >= topo) {
            matriz[i--][j] = vetor[indiceVetor];
            indiceVetor++;
        }
        topo++;
        direita--;
        j--;
        while (j >= esquerda) {
            matriz[i][j--] = vetor[indiceVetor];
            indiceVetor++;
        }
        esquerda++;
        i++;
        while (i <= base) {
            matriz[i++][j] = vetor[indiceVetor];
            indiceVetor++;
        }
        base++;
        j++;
        while (j <= direita) {
            matriz[i][j++] = vetor[indiceVetor];
            indiceVetor++;
        }
        direita++;
        i++;
    }

    printarMatriz(matriz, m, n);

}

int main() {
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);

    float vetor[100];
    int i;

    for (i = 0; i < m * n; i++) {
        scanf("%f", &vetor[i]);
    }

    gerarMatrizCaracol(vetor, m, n);

    return EXIT_SUCCESS;
}
