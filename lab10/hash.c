#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

Hash* criar_hash(int n) { //criando hash e inicializando as chaves
    Hash* hash = malloc(sizeof(Hash));

    hash->vetor = malloc(n * sizeof(No));

    for (int i = 0; i < n; i++) {
        strcpy(hash->vetor[i].chave, "");
    }

    return hash;
}

int gerar_hash(char *chave, int num) {
    int i, n = 0;

    //gerando hash para cada chave
    for (i = 0; i < strlen(chave); i++){
        n = (256 * n + chave[i]) % num;
    }

    return n;
}

void inserir(Hash* hash, char *chave, int n, int ordem) {
    //inicializando nó
    No no;
    strcpy(no.chave, chave);
    no.ordem = ordem;

    int posicao_para_inserir = gerar_hash(chave, n); //pegando posição para inserir
    int inseriu = 0; //int para verificar se padrão já foi inserido

    if (strcmp(hash->vetor[posicao_para_inserir].chave, "") == 0) {
        //inserir na posição que o hash retornou
        hash->vetor[posicao_para_inserir] = no;
    } else {
        for (int i = posicao_para_inserir; i < n; i++) {
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

No find_padrao(Hash* hash, int ordem, int n) {
    No no;

    //achando no que contém o padrão dentro do hash
    for (int i = 0; i < n; i++) {
        if (hash->vetor[i].ordem == ordem) {
            no = hash->vetor[i];
        }
    }

    return no;
}
