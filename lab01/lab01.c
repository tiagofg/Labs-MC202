#include <stdio.h>
#include <stdlib.h>

void printarMatriz(int m, int n, float matriz[m][n]) { //matriz inicializada com m linhas e n colunas
    int i, j;

    for(i = 0; i < m; i ++) {
        for(j = 0; j < n; j++) {
            printf("%.1f", matriz[i][j]); //printa float formatado
            if (j != n-1) {
                printf(" "); //só printa espaço vazio depois do elemento se ele não for o último
            }
        }
        printf("\n"); //printando \n ao final de cada linha
    }
}

void gerarMatrizCaracol(float vetor[10000], int m, int n){
    float matriz[m][n];
    int i = m-1, j = n-1, direita = n-2, esquerda = 0, topo = 0, base = m-1, indiceVetor = 0;
    while (indiceVetor < m * n) { //verificando se todas as posições do vetor foram percorridas
        for (; i >= topo; i--) //preenchendo matriz para cima
        {
            if (indiceVetor < m * n) {
                matriz[i][j] = vetor[indiceVetor];
                indiceVetor++;
            }
        }
        i++;
        j--;
        topo++;
        for (; j >= esquerda; j--) //preenchendo matriz para esquerda
        {
            if (indiceVetor < m * n) {
                matriz[i][j] = vetor[indiceVetor];
                indiceVetor++;
            }
        }
        j++;
        i++;
        esquerda++;
        for (; i <= base; i++) //preenchendo matriz para baixo
        {
            if (indiceVetor < m * n) {
                matriz[i][j] = vetor[indiceVetor];
                indiceVetor++;
            }
        }
        i--;
        j++;
        base--;
        for (; j <= direita; j++) //preenchendo matriz para direita
        {
            if (indiceVetor < m * n) {
                matriz[i][j] = vetor[indiceVetor];
                indiceVetor++;
            }
        }
        j--;
        i--;
        direita--;       
    }

    printarMatriz(m , n, matriz);
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    float vetor[10000]; //inicialização do vetor com o valor máximo
    int i;

    for (i = 0; i < m * n; i++) { //leitura dos valores do vetor
        scanf("%f", &vetor[i]);
    }

    gerarMatrizCaracol(vetor, m, n); //método usado para gerar e printar matriz caracol

    return EXIT_SUCCESS;
}
