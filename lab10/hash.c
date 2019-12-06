#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

Hash* criar_hash(int tamanho) { //criando hash e inicializando o vetor e as chaves
    Hash* hash = calloc(1, sizeof(Hash));

    hash->vetor = calloc(tamanho, sizeof(No));
    hash->tamanho = tamanho;

    return hash;
}

void destruir_hash(Hash* hash) {
    for (int i = 0; i < hash->tamanho; i++) {
        free(hash->vetor[i].chave);
    }

    free(hash->vetor);
    free(hash);
}

int gerar_hash(char *chave, int num) {
    int n = 0;

    //gerando hash para cada chave
    for (int i = 0; i < strlen(chave); i++){
        n = (1 * n + chave[i]) % num;
    }

    return n;
}

void inserir(Hash* hash, char *chave, int posicao) {
    //inicializando nó
    No no;

    no.chave = calloc(strlen(chave) + 1, sizeof(char));
    strcpy(no.chave, chave);

    no.posicao = posicao;

    int posicao_para_inserir = gerar_hash(chave, hash->tamanho); //pegando posição para inserir
    int inseriu = 0; //int para verificar se padrão já foi inserido

    if (hash->vetor[posicao_para_inserir].chave == NULL) {
        //inserir na posição que o hash retornou
        hash->vetor[posicao_para_inserir] = no;
    } else {
        for (int i = posicao_para_inserir; i < hash->tamanho; i++) {
            //inserir depois da posição que o hash retornou
            if (hash->vetor[i].chave == NULL) {
                hash->vetor[i] = no;
                inseriu = 1;
                break;
            }
        }

        if (inseriu == 0) {
            //inserir antes da posição que o hash retornou
            for (int i = 0; i < posicao_para_inserir; i++) {
                if (hash->vetor[i].chave == NULL) {
                    hash->vetor[i] = no;
                    inseriu = 1;
                    break;
                }
            }
        }

        printf("Inseriu fora da posição esperada \n");
    }
}

int esta_no_hash(Hash* hash, char* chave, int posicao) {
    int posicao_busca = gerar_hash(chave, hash->tamanho);

    No no;
    no = hash->vetor[posicao_busca];

    if (no.posicao == posicao && strcmp(no.chave, chave) == 0) {
        return 1;
    } else {
        for (int i = posicao_busca; i < hash->tamanho; i++) {
            no = hash->vetor[i];

            if (no.posicao == posicao && strcmp(no.chave, chave) == 0) {
                return 1;
            }
        }

        for (int i = 0; i < posicao_busca; i++) {
            no = hash->vetor[i];

            if (no.posicao == posicao && strcmp(no.chave, chave) == 0) {
                return 1;
            }
        }
    }

    return 0;
}