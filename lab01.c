#include <stdio.h>
#include <stdlib.h>

void gerarMatrizCaracol(float vetor[100], int m, int n){
    float matriz[m][n];
    int i = m-1, j = n-1, direita = n-1, esquerda = 0, topo = 0, base = m-1, indiceVetor = 0;
    while (indiceVetor < m * n) {
        while (i >= topo && indiceVetor < m * n) {
            matriz[i][j] = vetor[indiceVetor];
            i--;
            indiceVetor++;
        }     
        i++;
        topo++;
        direita--;
        j--;
        while (j >= esquerda && indiceVetor < m * n) {
            matriz[i][j] = vetor[indiceVetor];
	    matriz[i][j] = vetor[indiceVetor];
            j--;
            indiceVetor++;
        }
	j++;
        esquerda++;
        i++;
        while (i <= base && indiceVetor < m * n) {
            matriz[i][j] = vetor[indiceVetor];
	    matriz[i][j] = vetor[indiceVetor];
            i++;
            indiceVetor++;
        }	
        i--;
        base--;
        j++;
        while (j <= direita && indiceVetor < m * n) {
            matriz[i][j] = vetor[indiceVetor];
	    matriz[i][j] = vetor[indiceVetor];
            j++;
            indiceVetor++;
        }	
        j--;
        direita--;
        i--;
    }

    for(i = 0; i < m; i ++) {
        for(j = 0; j < n; j++) {
            printf("%.1f", matriz[i][j]);
            if (j != n-1) {
                printf(" ");
            }
        }
        printf("\n");
    }

}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    float vetor[100];
    int i;

    for (i = 0; i < 100; i++) {
        vetor[i] = 0;
    }

    for (i = 0; i < m * n; i++) {
        scanf("%f", &vetor[i]);
    }

    gerarMatrizCaracol(vetor, m, n);

    return EXIT_SUCCESS;
}
