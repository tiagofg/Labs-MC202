#include <stdio.h>
#include <stdlib.h>

#include "arvore.h"

Arvore* criar_arvore()
{
    Arvore *arvore = malloc(sizeof(Arvore));
    arvore->raiz = NULL;

    return arvore;
}

void limpar_arvore(Arvore* arvore)
{
    arvore->raiz = NULL;
}

No* criar_no(char dado, int numero)
{
    No *no = malloc(sizeof(No));
    no->dado = dado;
    no->numero = numero;
    no->esquerdo = NULL;
    no->direito = NULL;
    no->pai = NULL;
    no->proximo = NULL;

    return no;
}

No* iniciar_operacao(Arvore* arvore, No* no, No* atual)
{
    if (arvore->raiz == NULL)
    {
        arvore->raiz = no;
        atual = arvore->raiz;
    } else if (atual == NULL) {
        atual = no;
    } 

    return atual;
}

void inserir_variavel(No* no, No** atual)
{
    // No* atual = arvore->atual;
    // // if (arvore->atual->pai->esquerdo == arvore->atual) {
    //     // arvore->atual->pai->esquerdo = no;
    // if (arvore->atual == arvore->raiz->esquerdo) {
    //     printf("Inserir na esquerda da raiz \n");
        *atual = no;
    //     printf("No esquerdo da raiz: %p \n", arvore->raiz->esquerdo);
    // } else if (arvore->atual == arvore->raiz->direito) {
    //     printf("Inserir na direita da raiz \n");
    //     *atual = *no;
    //     printf("No direito da raiz: %p \n", arvore->raiz->esquerdo);
    // }
    // } else if (arvore->atual->pai->direito == arvore->atual) {
    //     arvore->atual->pai->direito = no;
    //     arvore->atual = no;
    // }    
    // printf("Arvore depois de inserir: %c \n", no->dado);
    // printar_arvore(arvore->raiz);
}

No* procurar_no(No* raiz, char dado)
{
    No *esquerdo;
    if (raiz == NULL || raiz->dado == dado)
    {
        return raiz;
    }

    esquerdo = procurar_no(raiz->esquerdo, dado);

    if (esquerdo != NULL)
    {
        return esquerdo;
    }

    return procurar_no(raiz->direito, dado);
}

void printar_arvore(No* raiz)
{
    if (raiz != NULL)
    {
        printar_arvore(raiz->esquerdo);
        if (raiz->dado != ' ') {
            printf("%c ", raiz->dado);
        } else {
            printf("%d ", raiz->numero);
        }
        printar_arvore(raiz->direito);
    }
}