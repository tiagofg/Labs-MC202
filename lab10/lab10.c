#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

int get_qtde_ocorrencias(Hash* hash, int tamanho, int posicao, char* texto) {
    int qtde_ocorrencias = 0;
    char* substr = calloc(tamanho + 1, sizeof(char));

    for (int i = 0; i < strlen(texto) - tamanho + 1; i++) {
        memcpy(substr, &texto[i], tamanho);

        if (esta_no_hash(hash, substr, posicao)) {
            qtde_ocorrencias++;
        }
    }    

    free(substr);

    return qtde_ocorrencias;
}

int main()
{
    int n;

    scanf("%d", &n);

    Hash* hash = criar_hash(n);

    //strings para ler cada padrão e o texto completo
    char padrao[50];
    char texto[40000];

    //vetor de inteiros para manter a posicao de inserção dos padrões
    int* qtde_padroes = malloc(n * sizeof(int));
    int* tamanhos = malloc(n * sizeof(int));

    //adicionando padrão no vetor de strings e no hash
    for (int i = 0; i < n; i++) {
        scanf("%s\n", padrao);
        qtde_padroes[i] = 0;
        tamanhos[i] = strlen(padrao);
        inserir(hash, padrao, i);
    }

    scanf("%s\n", texto);

    for (int i = 0; i < n; i++) {
        qtde_padroes[i] = get_qtde_ocorrencias(hash, tamanhos[i], i, texto);
        //imprimindo número de ocorrências para cada padrão
        printf("%d\n", qtde_padroes[i]);
    }

    //liberando memória
    destruir_hash(hash);
    free(qtde_padroes);
    free(tamanhos);

   return EXIT_SUCCESS;

}
