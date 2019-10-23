#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "abb.h"

ArvoreBusca* criar_arvore() { //inicializando árvore
    ArvoreBusca* arvore = malloc(sizeof(ArvoreBusca));
    arvore->raiz = NULL;

    return arvore;
}

void destruir_arvore(ArvoreBusca* arvore, int qtde_dados) { //destruindo árvore
    remover_todos_os_nos(arvore, arvore->raiz);
    free(arvore);
}


No* inserir(ArvoreBusca* arvore, No* raiz, int identificador, char* dado) {
    No* novo;

    if (raiz == NULL) { //inserir no caso do nó atual ser nulo
        novo = malloc(sizeof(No));
        novo->esquerdo = novo->direito = NULL;
        novo->identificador = identificador;
        novo->dado = malloc(9 * sizeof(char));
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

No* buscar(No* raiz, int identificador) {
    if (raiz == NULL || identificador == raiz->identificador) {
        return raiz;
    }

    //verificando onde o nó deve ser buscado
    if (identificador < raiz->identificador) {
        return buscar(raiz->esquerdo, identificador);
    } else {
        return buscar(raiz->direito, identificador);
    }
}

void imprimir_mensagem(ArvoreBusca* arvore, int qtde_dados) {
    No* buscado;
    char* mensagem = calloc(8 * qtde_dados + 1, sizeof(char)); //alocando memória para os bits e o /0

    for (int i = 1; i <= qtde_dados; i++) {
        buscado = buscar(arvore->raiz, i); //buscando nó pelo identificador
        strcat(mensagem, buscado->dado); //concatenando string de mensagem
    }

    printf("%s\n", mensagem); //imprimindo mensagem decodificada
    free(mensagem);
}
