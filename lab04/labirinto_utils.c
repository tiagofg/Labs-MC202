
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

int posicao_valida(char** labirinto, int i, int j, int m, int n) {
    if (i >= 0 && j >= 0 && i < m && j < n && eh_parede(labirinto, i ,j) == 0){
        return 1;
    }

    return 0;
}