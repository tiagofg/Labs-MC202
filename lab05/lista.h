#ifndef LISTA_H

#define LISTA_H

#endif

typedef struct No {
    int inicio_segmento;
    int tamanho_segmento;
    // int tamanho_lista;

    struct No* anterior;
    struct No* proximo;
} No;

// No* inicio;

No* criar_lista();

void inserir_no(No** lista, No* no);

void remover_no(No* no);

void imprimir_heap(No* lista);

No* get_melhor_heap(No* heap, int tamanho);

void alocar_memoria(No* heap, int tamanho);

void desalocar_memoria(No* heap, int endereco, int tamanho);

void realocar_memoria(No* heap, int endereco, int tamanho, int novo_tamanho);
