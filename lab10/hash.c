#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

Hash* criar_hash() {
    Hash* hash = malloc(sizeof(Hash));

    for (int i = 0; i < MAX; i++) {
        strcpy(hash->vetor[i].chave, "");
    }

    return hash;
}

int gerar_hash(char *chave) {
    int i, n = 0;

    for (i = 0; i < strlen(chave); i++){
        n = (256 * n + chave[i]) % MAX;
    }

    return n;
}

void inserir(Hash* hash, char *chave, int num_ocorrencias) {
    No no;
    strcpy(no.chave, chave);
    no.num_ocorrencias = num_ocorrencias;

    int posicao_para_inserir = gerar_hash(chave);
    int inseriu = 0;

    // printf("Inserir na posição: %d\n", posicao_para_inserir);

    if (strcmp(hash->vetor[posicao_para_inserir].chave, "") == 0) {
        hash->vetor[posicao_para_inserir] = no;
        // printf("%s\n", hash->vetor[posicao_para_inserir].chave);
    } else {
        for (int i = posicao_para_inserir; i < MAX; i++) {
            if (strcmp(hash->vetor[i].chave, "") == 0) {
                hash->vetor[i] = no;
                inseriu = 1;
                // printf("%s\n", hash->vetor[i].chave);
                break;
            }
        }

        if (inseriu == 0) {
            for (int i = 0; i < posicao_para_inserir; i++) {
                if (strcmp(hash->vetor[i].chave, "") == 0) {
                    hash->vetor[i] = no;
                    inseriu = 1;
                    // printf("%s\n", hash->vetor[i].chave);
                    break;
                }
            }
        }
    }
}
