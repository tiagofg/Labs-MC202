#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "abb.h"

ArvoreBusca* criar_arvore() { //inicializando árvore
    ArvoreBusca* arvore = malloc(sizeof(ArvoreBusca));

    if (arvore == NULL) {
        printf("Falha ao alocar arvore \n");
        exit(1);
    }

    arvore->raiz = NULL;

    return arvore;
}

void destruir_arvore(ArvoreBusca* arvore) { //destruindo árvore
    remover_todos_os_nos(arvore, arvore->raiz);
    free(arvore);
}


No* inserir(ArvoreBusca* arvore, No* raiz, int identificador, char* dado) {
    No* novo;

    if (raiz == NULL) { //inserir no caso do nó atual ser nulo
        novo = malloc(sizeof(No));

        if (novo == NULL) {
            printf("Falha ao alocar novo nó \n");
            exit(1);
        }

        novo->esquerdo = novo->direito = NULL;
        novo->identificador = identificador;

        novo->dado = malloc(TAM_DADO * sizeof(char));

        if (novo == NULL) {
            printf("Falha ao alocar dado do novo nó \n");
            exit(1);
        }

        strcpy(novo->dado, dado);

        if (arvore->raiz == NULL) {
            arvore->raiz = novo;
        }

        return novo;
    }

    //verificar se deve inserir nó na direita ou na esquerda
    if (identificador < raiz->identificador) {
        raiz->esquerdo = inserir(arvore, raiz->esquerdo, identificador, dado);
    } else if (identificador > raiz->identificador) {
        raiz->direito = inserir(arvore, raiz->direito, identificador, dado);
    }

    return raiz;
}

void remover_todos_os_nos(ArvoreBusca* arvore, No* raiz) {
    if (raiz != NULL) {
        //percorrendo a árvore em pós-ordem e removendo os nós
        remover_todos_os_nos(arvore, raiz->esquerdo);
        remover_todos_os_nos(arvore, raiz->direito);

        if (arvore-> raiz == raiz) {
            arvore->raiz = NULL; //verificando se nó removido era a raiz da árvore
        }

        free(raiz->dado); //desalocando memória do pedaço da mensagem
        free(raiz); //desalocando memória do nó
    }
}

void inordem(No* raiz) {
    if (raiz != NULL) {
        //imprimindo dados em inordem
        inordem(raiz->esquerdo);
        printf("%s", raiz->dado);
        inordem(raiz->direito);
    }
}

void imprimir_mensagem(ArvoreBusca* arvore) {
    inordem(arvore->raiz);
    printf("\n"); //linha vazia ao final da mensagem
}
