#ifndef LISTA_H
#define LISTA_H

typedef struct No {
    int inicioSegmento;
    int tamanhoSegmento;

    No* anterior;
    No* proximo;
} No;

#endif

int getInicioSegmento(No* no);

int getTamanhoSegmento(No* no);

No* getAnterior(No* no);

No* getProximo(No* no);
