#ifndef LISTA_H
#define LISTA_H
#endif // LISTA_H

typedef struct No {
    int valor;
    int peso;

    struct No* proximo;
} No;

typedef struct {
    No* inicio;
    int tamanho;
} Lista;

Lista* criar_lista();

void destruir_lista(No* no);

Lista* inserir(Lista* lista, int valor);

No* obter_iterador(Lista* lista);

No* avancar_posicao(No* iterador);

int eh_vazia(Lista* lista);
