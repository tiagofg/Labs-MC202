#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

int get_qtde_ocorrencias(char* padrao, char* texto) {
    int qtde_ocorrencias = 0;
    int tamanho_padrao = strlen(padrao);
    char* sub_str = malloc(tamanho_padrao + 1 * sizeof(char));

    //pegando a quantidade de ocorrencias de uma chave em um texto
    for (int i = 0; i < strlen(texto); i++) {
        strncpy(sub_str, texto + i, tamanho_padrao);

        //verificando se a substring é igual o padrão
        if (strcmp(sub_str, padrao) == 0) {
            qtde_ocorrencias++;
        }
    }

    free(sub_str);

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
