#include <stdio.h>
#include <stdlib.h>

int eh_parede(char** labirinto, int i, int j) {
    if (labirinto[i][j] == '#') {
        return 1;
    }

    return 0;
}

int eh_minotauro(char** labirinto, int i, int j) {
    if (labirinto[i][j] == 'M') {
        return 1;
    }

    return 0;
}

int eh_espada(char** labirinto, int i, int j) {
    if (labirinto[i][j] == 'S') {
        return 1;
    }

    return 0;
}

void zerar_caminho(char** caminho, int i, int j) {
    if (caminho[i][j] == '*') {
        caminho[i][j] = ' ';
    }
}

int buscar_espada(char** labirinto, char** espada, int i, int j, int m, int n) {    
    printf("%d %d %c \n", i, j, labirinto[i][j]);

    if (eh_espada(labirinto, i, j) == 1)
    {
        return 1;
    }


    if(i >= 0 && j >= 0 && i < m && j < n && eh_parede(labirinto, i, j) == 0 && eh_minotauro(labirinto, i, j) == 0)
    {
        espada[i][j] = '*';

        if (buscar_espada(labirinto, espada, i, j + 1, m, n) == 1) {
            return 1;
        }    
        
        if (buscar_espada(labirinto, espada, i + 1, j, m, n) == 1) {
            return 1;
        }
        
        if (buscar_espada(labirinto, espada, i, j - 1, m, n) == 1) {
            return 1;
        }    
        
        if (buscar_espada(labirinto, espada, i - 1, j, m, n) == 1) {
            return 1;
        }    
        
        espada[i][j] = ' ';
    }

    return 0;
}

void caminho_espada(char** labirinto, char** espada, int i_entrada, int j_entrada, int m, int n) {
    if (buscar_espada(labirinto, espada, i_entrada, j_entrada, m, n) == 1) {
        printf("Chegou na espada\n");
    }
    else {
        printf("Não chegou na espada\n");
    }
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

    scanf("%d %d ", &m, &n);
    printf("%d %d \n", m, n);

    char** labirinto = (char**) malloc(m * sizeof(char*));
    for (int i = 0; i < n; i++) {
        labirinto[i] = (char*) malloc(n * sizeof(char));
    }

    char** espada = (char**) malloc(m * sizeof(char*));
    for (int i = 0; i < n; i++) {
        espada[i] = (char*) malloc(n * sizeof(char));
    }

    char** minotauro = (char**) malloc(m * sizeof(char*));
    for (int i = 0; i < n; i++) {
        minotauro[i] = (char*) malloc(n * sizeof(char));
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%c", &labirinto[i][j]);
        }
        getchar();
    }

    printar_labirinto(labirinto, m, n);

    int entrada;

    for (int j = 0; j < n; j++) {
            if (labirinto[0][j] == 'E') {
                entrada = j;
            }
    }

    caminho_espada(labirinto, espada, 1, entrada, m , n);

    free(labirinto);
    free(espada);
    free(minotauro);

    return EXIT_SUCCESS;
}
