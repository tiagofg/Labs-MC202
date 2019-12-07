#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

Hash* criar_hash(int n) { //criando hash e inicializando o vetor e as chaves
    Hash* hash = calloc(1, sizeof(Hash));

    int tamanho = n / 0.7; //tamanho um pouco maior que n para evitar muitas colisões

    hash->vetor = calloc(tamanho, sizeof(No));
    if (hash->vetor == NULL) {
        printf("Falha ao alocar vetor de hash \n");
        exit(1);
    }

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

int gerar_hash(char *chave, int tamanho) {
    int n = 0;

    //gerando hash para cada chave
    for (int i = 0; i < strlen(chave); i++){
        n = (256 * n + chave[i]) % tamanho;
    }

    return n;
}

void inserir(Hash* hash, char *chave, int posicao) {
    //inicializando nó
    No no;

    no.chave = calloc(strlen(chave) + 1, sizeof(char));
    if (no.chave == NULL) {
        printf("Falha ao alocar chave para o nó \n");
        exit(1);
    }

    strcpy(no.chave, chave);

    no.posicao = posicao;

    int posicao_sugerida = gerar_hash(chave, hash->tamanho); //pegando posição para inserir

    if (hash->vetor[posicao_sugerida].chave == NULL) {
        //inserir na posição que o hash retornou
        hash->vetor[posicao_sugerida] = no;
    } else {
        //inserir depois da posição que o hash retornou
        for (int i = posicao_sugerida; i < hash->tamanho; i++) {
            if (hash->vetor[i].chave == NULL) {
                hash->vetor[i] = no;
                return;
            }
        }

        //inserir antes da posição que o hash retornou
        for (int i = 0; i < posicao_sugerida; i++) {
            if (hash->vetor[i].chave == NULL) {
                hash->vetor[i] = no;
                return;
            }
        }
    }
}

void esta_no_hash(Hash* hash, char* chave, int* qtde_padroes) {
    //simular uma inserção para descobrir a posição mais provável
    int posicao_busca = gerar_hash(chave, hash->tamanho);

    No no;
    no = hash->vetor[posicao_busca];

    //se essa posição estiver nula é possível afirmar que a chave não foi inserida
    if (no.chave == NULL) {
        return;
    } else if (strcmp(no.chave, chave) == 0) {
        qtde_padroes[no.posicao] = qtde_padroes[no.posicao] + 1;
        return;
    } else {
        //procurando depois da posição do hash
        for (int i = posicao_busca; i < hash->tamanho; i++) {
            no = hash->vetor[i];

            if (no.chave == NULL) {
                return;
            } else if (strcmp(no.chave, chave) == 0) {
                qtde_padroes[no.posicao] = qtde_padroes[no.posicao] + 1;
                return;
            }
        }

        //procurando antes da posição do hash
        for (int i = 0; i < posicao_busca; i++) {
            no = hash->vetor[i];

            if (no.chave == NULL) {
                return;
            } else if (strcmp(no.chave, chave) == 0) {
                qtde_padroes[no.posicao] = qtde_padroes[no.posicao] + 1;
                return;
            }
        }
    }
}