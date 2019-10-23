#ifndef ABB_H
#define ABB_H

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

void destruir_arvore(ArvoreBusca* arvore, int qtde_dados);

No* inserir(ArvoreBusca* arvore, No* raiz, int identificador, char* dado);

No* buscar(No* raiz, int identificador);

void imprimir_mensagem(ArvoreBusca* arvore, int qtde_dados);
