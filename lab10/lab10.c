#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

int get_qtde_ocorrencias(char* padrao, char* texto) {
    int qtde_ocorrencias = 0;
    const char *sub_str = texto;

    //pegando a quantidade de ocorrencias de uma chave em um texto
    while((sub_str = strstr(sub_str, padrao))) //percorrendo texto até o final
    {
       qtde_ocorrencias++;
       sub_str++; //percorrendo string a partir do último padrão encontrado
    }

    return qtde_ocorrencias;
}

int main()
{
    int n;

    scanf("%d", &n);

    Hash* hash = criar_hash(n);

    //strings para ler cada padrão e o texto completo
    char* padrao = malloc(100 * sizeof(char));
    char* texto = malloc(40000 * sizeof(char));

    //vetor de strings para manter a ordem de inserção dos padrões
    char** padroes = (char**) malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        padroes[i] = (char*) malloc(100 * sizeof(char));
    }

    //adicionando padrão no vetor de strings e no hash
    for (int i = 0; i < n; i++) {
        scanf("%s\n", padrao);
        strcpy(padroes[i], padrao);
        inserir(hash, padrao, 0);
    }

    scanf("%s\n", texto);

    for (int i = 0; i < n; i++) {
        No no = find_padrao(hash, padroes[i]);
        no.num_ocorrencias = get_qtde_ocorrencias(no.chave, texto);
        //imprimindo número de ocorrências para cada padrão
        printf("%d\n", no.num_ocorrencias);
    }

    //liberando memória
    free(hash);
    free(padrao);
    free(texto);

    for (int i = 0; i < n; i++) {
        free(padroes[i]);
    }

    free(padroes);

   return EXIT_SUCCESS;

}
