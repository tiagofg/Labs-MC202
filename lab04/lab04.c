#include <stdio.h>
#include <stdlib.h>

#include "labirinto_utils.h"

int buscar_espada(char** labirinto, char** espada, int i, int j, int m, int n, char direcao) {
    if (posicao_valida(labirinto, i, j, m , n) == 0 || eh_minotauro(labirinto, i, j) == 1) {
        return 0;
    }

    if (eh_espada(labirinto, i, j) == 1)
    {
        return 1;
    }

    espada[i][j] = '*';

    if (direcao != 'E') {
        if (buscar_espada(labirinto, espada, i, j + 1, m, n, 'D') == 1)
        {
            return 1;
        }
    }

    if (direcao != 'C') {
        if (buscar_espada(labirinto, espada, i + 1, j, m, n, 'B') == 1)
        {
            return 1;
        }
    }

    if (direcao != 'D') {
        if (buscar_espada(labirinto, espada, i, j - 1, m, n, 'E') == 1)
        {
            return 1;
        }
    }

    if (direcao!= 'B') {
        if (buscar_espada(labirinto, espada, i - 1, j, m, n, 'C') == 1)
        {
            return 1;
        }
    }

    espada[i][j] = ' ';

    return 0;
}

int buscar_minotauro(char** labirinto, char** minotauro, int i, int j, int m, int n, char direcao) {
    if (posicao_valida(labirinto, i, j, m , n) == 0) {
        return 0;
    }

    if (eh_minotauro(labirinto, i, j) == 1)
    {
        return 1;
    }

    if (labirinto[i][j] != 'S') {
        minotauro[i][j] = '*';
    }

    if (direcao != 'E') {
        if (buscar_minotauro(labirinto, minotauro, i, j + 1, m, n, 'D') == 1)
        {
            return 1;
        }
    }

    if (direcao != 'C') {
        if (buscar_minotauro(labirinto, minotauro, i + 1, j, m, n, 'B') == 1)
        {
            return 1;
        }
    }

    if (direcao != 'D') {
        if (buscar_minotauro(labirinto, minotauro, i, j - 1, m, n, 'E') == 1)
        {
            return 1;
        }
    }

    if (direcao != 'B') {
        if (buscar_minotauro(labirinto, minotauro, i - 1, j, m, n, 'C') == 1)
        {
            return 1;
        }
    }

    minotauro[i][j] = ' ';

    return 0;
}

void printar_labirinto(char** labirinto, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", labirinto[i][j]);
        }

        printf("\n");
    }
}

int main()
{
    int m, n;

    scanf("%d %d", &m, &n);
    getchar();

    char** labirinto = (char**) calloc(m, sizeof(char*));
    for (int i = 0; i < m; i++) {
        labirinto[i] = (char*) calloc(n, sizeof(char));
    }

    char** espada = (char**) calloc(m, sizeof(char*));
    for (int i = 0; i < m; i++) {
        espada[i] = (char*) calloc(n, sizeof(char));
    }

    char** minotauro = (char**) calloc(m, sizeof(char*));
    for (int i = 0; i < m; i++) {
        minotauro[i] = (char*) calloc(n, sizeof(char));
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%c", &labirinto[i][j]);
            espada[i][j] = ' ';
            minotauro[i][j] = ' ';
        }
        getchar();
    }


    int y_entrada, x_espada, y_espada;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (labirinto[i][j] == 'E') {
                y_entrada = j;
            }

            if (labirinto[i][j] == 'S') {
                x_espada = i;
                y_espada = j;
            }
        }
    }

    buscar_espada(labirinto, espada, 1, y_entrada, m , n, ' ');
    buscar_minotauro(labirinto, minotauro, x_espada, y_espada, m, n, ' ');

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((espada[i][j] == '*' || minotauro[i][j] == '*') && labirinto[i][j] != 'S') {
                labirinto[i][j] = '*';
            }
        }
    }

    printar_labirinto(labirinto, m, n);

    free(labirinto);
    free(espada);
    free(minotauro);

    return EXIT_SUCCESS;
}
