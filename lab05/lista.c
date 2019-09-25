#include <stdlib.h>

#include "lista.h"

No *inicio = NULL;

No *final = NULL;

No *atual = NULL;

int getInicioSegmento(No* no){
    return no->inicioSegmento;
}

int getTamanhoSegmento(No* no){
    return no->inicioSegmento;
}

No* getAnterior(No* no){
    return no->anterior;
}

No* getProximo(No* no){
    return no->proximo;
}
