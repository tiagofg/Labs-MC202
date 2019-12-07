#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

void get_qtde_ocorrencias(Hash* hash, int* tamanhos, char* texto, int* qtde_ocorrencias, int tamanhos_diferentes) {
    for(int i = 0; i < tamanhos_diferentes; i++) {
        int tamanho = tamanhos[i];

        char* substr = calloc(tamanho + 1, sizeof(char));
        if (substr == NULL) {
            printf("Falha ao alocar string para armazenar os possíveis padrões \n");
            exit(1);
        }

        for (int i = 0; i < strlen(texto) - tamanho + 1; i++) {
            memcpy(substr, &texto[i], tamanho);

            //verificar se os padrões de um mesmo tamanho estão armazenados no hash
            esta_no_hash(hash, substr, qtde_ocorrencias);
        }    

        free(substr);
    }
}

int esta_inserido(int* tamanhos, int tamanho, int tamanhos_diferentes) {
    for (int i = 0; i < tamanhos_diferentes; i++) {
        if (tamanhos[i] == tamanho) {
            return 1;
        }
    }

    return 0;
}

int main()
{
    int n;

    scanf("%d", &n);

    Hash* hash = criar_hash(n);

    //strings para ler cada padrão e o texto completo
    char* padrao = calloc(50, sizeof(char));
    if (padrao == NULL) {
        printf("Falha ao alocar string para armazenar os padrões \n");
        exit(1);
    }

    char* texto = calloc(40000, sizeof(char));
    if (texto == NULL) {
        printf("Falha ao alocar string para armazenar o texto \n");
        exit(1);
    }

    //vetor de inteiros para manter a posicao de inserção dos padrões
    int* qtde_ocorrencias = calloc(n, sizeof(int));
    if (qtde_ocorrencias == NULL) {
        printf("Falha ao alocar vetor para armazenar a quantidade de ocorrências \n");
        exit(1);
    }

    int* tamanhos = calloc(n, sizeof(int));
    if (tamanhos == NULL) {
        printf("Falha ao alocar vetor para armazenar o tamanho dos padrões \n");
        exit(1);
    }

    int tamanhos_diferentes = 0;

    //adicionando padrão no vetor de strings e no hash
    for (int i = 0; i < n; i++) {
        scanf("%s\n", padrao);
        qtde_ocorrencias[i] = 0;

        //verificar se o tamanho já está inserido no vetor de tamanhos
        if (esta_inserido(tamanhos, strlen(padrao), tamanhos_diferentes) == 0) {
            tamanhos[tamanhos_diferentes++] = strlen(padrao);
        }

        inserir(hash, padrao, i);
    }

    scanf("%s\n", texto);

    get_qtde_ocorrencias(hash, tamanhos, texto, qtde_ocorrencias, tamanhos_diferentes);

    for (int i = 0; i < n; i++) {
        //imprimindo número de ocorrências para cada padrão
        printf("%d\n", qtde_ocorrencias[i]);
    }

    //liberando memória
    destruir_hash(hash);
    free(padrao);
    free(texto);
    free(qtde_ocorrencias);
    free(tamanhos);

   return EXIT_SUCCESS;

}
