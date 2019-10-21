#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilha.h"

Pilha* criar_pilha() {
    Pilha* pilha = malloc(1 * sizeof(Pilha));
    pilha->topo = NULL;

    return pilha;
}

void empilhar(Pilha* pilha, No* no) {
    no->proximo = pilha->topo;
    pilha->topo = no;
}

No* desempilhar(Pilha* pilha) {
    No* topo = pilha->topo;

    pilha->topo = pilha->topo->proximo;
    return topo;
}
