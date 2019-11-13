#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

Hash* criar_hash() { //criando hash e inicializando as chaves
    Hash* hash = malloc(sizeof(Hash));

    for (int i = 0; i < MAX; i++) {
        strcpy(hash->vetor[i].chave, "");
    }

    return hash;
}

int gerar_hash(char *chave) {
    int i, n = 0;

    //gerando hash para cada chave
    for (i = 0; i < strlen(chave); i++){
        n = (256 * n + chave[i]) % MAX;
    }

    return n;
}

void inserir(Hash* hash, char *chave, int num_ocorrencias) {
    //inicializando nó
    No no;
    strcpy(no.chave, chave);
    no.num_ocorrencias = num_ocorrencias;

    int posicao_para_inserir = gerar_hash(chave); //pegando posição para inserir
    int inseriu = 0; //int para verificar se padrão já foi inserido

    if (strcmp(hash->vetor[posicao_para_inserir].chave, "") == 0) {
        //inserir na posição que o hash retornou
        hash->vetor[posicao_para_inserir] = no;
    } else {
        for (int i = posicao_para_inserir; i < MAX; i++) {
            //inserir depois da posição que o hash retornou
            if (strcmp(hash->vetor[i].chave, "") == 0) {
                hash->vetor[i] = no;
                inseriu = 1;
                break;
            }
        }

        if (inseriu == 0) {
            //inserir antes da posição que o hash retornou
            for (int i = 0; i < posicao_para_inserir; i++) {
                if (strcmp(hash->vetor[i].chave, "") == 0) {
                    hash->vetor[i] = no;
                    inseriu = 1;
                    break;
                }
            }
        }
    }
}

No find_padrao(Hash* hash, char* chave) {
    No no;

    //achando no que contém o padrão dentro do hash
    for (int i = 0; i < MAX; i++) {
        if (strcmp(hash->vetor[i].chave, chave) == 0) {
            no = hash->vetor[i];
        }
    }

    return no;
}
