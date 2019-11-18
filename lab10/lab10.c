#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

int get_qtde_ocorrencias(char* padrao, char* texto) {
    int tamanho_texto = strlen(texto);
    int tamanho_padrao = strlen(padrao);
    int i, j, qtde_ocorrencias = 0;

    for (i = 0; i <= tamanho_texto - tamanho_padrao; i++) {
        //se os caracteres do texto e do padrão forem iguais, continua o loop
        for (j = 0; j < tamanho_padrao && texto[i + j] == padrao[j]; j++) {
            continue;
        }

        //se a quantidade de caracteres for igual o tamanho do padrão, então a quantidade de ocorrências aumenta
        if (j == tamanho_padrao) {
            qtde_ocorrencias++;
        }
    }

    return qtde_ocorrencias;
}

int main()
{
    int n;

    scanf("%d", &n);

    Hash* hash = criar_hash(n);

    //strings para ler cada padrão e o texto completo
    char* padrao = malloc(50 * sizeof(char));
    char* texto = malloc(40000 * sizeof(char));

    //vetor de inteiros para manter a ordem de inserção dos padrões
    int* qtde_padroes = malloc(n * sizeof(int));

    //adicionando padrão no vetor de strings e no hash
    for (int i = 0; i < n; i++) {
        scanf("%s\n", padrao);
        qtde_padroes[i] = 0;
        inserir(hash, padrao, n, i);
    }

    scanf("%s\n", texto);

    for (int i = 0; i < n; i++) {
        No no = find_padrao(hash, i, n);
        qtde_padroes[i] = get_qtde_ocorrencias(no.chave, texto);
        //imprimindo número de ocorrências para cada padrão
        printf("%d\n", qtde_padroes[i]);
    }

    //liberando memória
    free(hash->vetor);
    free(hash);
    free(padrao);
    free(texto);
    free(qtde_padroes);

   return EXIT_SUCCESS;

}
