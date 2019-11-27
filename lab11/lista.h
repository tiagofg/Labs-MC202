#ifndef LISTA_H
#define LISTA_H
#endif // LISTA_H

typedef struct No {
    int x, y, w, z;

    struct No* proximo;
} No;

typedef struct {
    No* inicio;
} Lista;

Lista* criar_lista();

void inserir(Lista* lista, No* no);

int obter_iterador(Lista* lista);

void avancar_posicao(int iterador);

int eh_vazia(Lista* lista);
