#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

int get_qtde_ocorrencias(char* padrao, char* texto) {
    int qtde_ocorrencias = 0;
    const char *sub_str = texto;

    while((sub_str = strstr(sub_str, padrao)))
    {
       qtde_ocorrencias++;
       sub_str++;
    }

    return qtde_ocorrencias;
}

No find_padrao(Hash* hash, char* chave, int n) {
    No no;

    for (int i = 0; i < n; i++) {
        if (strcmp(hash->vetor[i].chave, chave) == 0) {
            no = hash->vetor[i];
        }
    }

    return no;
}

int main()
{
    int n;

    scanf("%d", &n);

    Hash* hash = criar_hash(n);

    char* padrao = malloc(100 * sizeof(char));
    char* texto = malloc(40000 * sizeof(char));

    char** padroes = (char**) malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        padroes[i] = (char*) malloc(100 * sizeof(char));
    }

    for (int i = 0; i < n; i++) {
        scanf("%s\n", padrao);
        strcpy(padroes[i], padrao);
        inserir(hash, padrao, 0, n);
    }

    scanf("%s\n", texto);

    for (int i = 0; i < n; i++) {
        No no = find_padrao(hash, padroes[i], n);
        no.num_ocorrencias = get_qtde_ocorrencias(no.chave, texto);

        printf("%d\n", no.num_ocorrencias);
    }

    free(hash);
    free(padrao);
    free(texto);

    for (int i = 0; i < n; i++) {
        free(padroes[i]);
    }

    free(padroes);

   return EXIT_SUCCESS;

}
