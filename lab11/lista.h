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

void destruir_lista(No* inicio);

Lista* inserir(Lista* lista, int numero, int peso, int variacao, char elevador);

No* obter_iterador(Lista* lista);

No* avancar_posicao(No* iterador);

void imprimir_lista(Lista* lista);

// int eh_vazia(Lista* lista);
