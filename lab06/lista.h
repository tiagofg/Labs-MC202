#ifndef LISTA_H

#define LISTA_H

#endif

typedef struct No_lista {
    char dado;
    int no_removido;

    struct No_lista* proximo;
} No_lista;

typedef struct {
    No_lista* inicio;
} Lista;

Lista* criar_lista();

void inserir_no_inicio(Lista* lista, char dado);

void remover_no(Lista* heap, No_lista* no);

void limpar_lista(Lista* lista);   