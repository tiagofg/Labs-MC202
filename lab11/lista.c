#include "lista.h"

Lista* criar_lista() {
    Lista* lista = malloc(sizeof(Lista)); //alocando memória da lista

    No* no = malloc(sizeof(No)); //alocando memória do nó

    //inicializando nó
    no->x = 0;
    no->y = 0;
    no->w = 0;
    no->z = 0;
    no->proximo = NULL;

    //setando ínicio da lista
    lista->inicio = no;

    return lista;
}
