#ifndef LISTA_H

#define LISTA_H

#endif

typedef struct No {
    int inicio_segmento;
    int tamanho_segmento;

    struct No* anterior;
    struct No* proximo;
} No;

typedef struct {
    No* inicio;
    No* dados;
} Lista;

// No* inicio;

Lista* criar_lista();

void inserir_no(Lista* lista, No* no);

void remover_no(No* no);

void imprimir_heap(Lista* lista);

No* get_melhor_heap(Lista* heap, int tamanho);

void juntar_segmentos_se_possivel(Lista* heap);

void alocar_memoria(Lista* heap, int tamanho);

void desalocar_memoria(Lista* heap, int endereco, int tamanho);

void realocar_memoria(Lista* heap, int endereco, int tamanho, int novo_tamanho);
