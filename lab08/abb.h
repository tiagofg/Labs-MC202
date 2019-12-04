#ifndef ABB_H
#define ABB_H

#define TAM_DADO 9
#define FIM_MSG 0

#endif

typedef struct No {
    int identificador;
    char* dado;

    struct No* esquerdo;
    struct No* direito;
} No;

typedef struct ArvoreBusca {
    No* raiz;
} ArvoreBusca;

ArvoreBusca* criar_arvore();

void destruir_arvore(ArvoreBusca* arvore);

No* inserir(ArvoreBusca* arvore, No* raiz, int identificador, char* dado);

void remover_todos_os_nos(ArvoreBusca* arvore, No* raiz);

void inordem(No* raiz);

void imprimir_mensagem(ArvoreBusca* arvore);
