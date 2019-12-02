#ifndef LISTA_H
#define LISTA_H
#endif // LISTA_H

typedef struct No {
    int numero;
    int peso;
    int variacao;
    char elevador;

    struct No* proximo;
} No;

typedef struct {
    No* inicio;
} Lista;

Lista* criar_lista();

void destruir_lista(Lista* lista);

Lista* inserir(Lista* lista, int numero, int peso, int variacao, char elevador);

No* obter_iterador(Lista* lista);

No* avancar_posicao(No* iterador);

void imprimir_lista(Lista* lista);

int esta_na_lista(Lista* lista, int vertice);

int get_variacao(Lista* lista, int vertice);
