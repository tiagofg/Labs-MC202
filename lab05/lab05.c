#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

void ler_operacoes(int m, No* heap) {
    char operacao;
    int endereco_segmento, tamanho_segmento, novo_tamanho_segmento;

    for (int i = 0; i < m; i++) {
        scanf("%c ", &operacao);

        if (operacao == 'A') {
            scanf("%d\n", &tamanho_segmento);
            alocar_memoria(heap, tamanho_segmento);
        } else if (operacao == 'D') {
            scanf("%d %d\n", &endereco_segmento, &tamanho_segmento);
            desalocar_memoria(heap, endereco_segmento, tamanho_segmento);
        } else if (operacao == 'R') {
            scanf("%d %d %d\n", &endereco_segmento, &tamanho_segmento, &novo_tamanho_segmento);
        } else if (operacao == 'P') {
            imprimir_heap(heap);
        }
    }
}

int main()
{
    int m, n;

    scanf("%d %d", &m, &n);

    No* heap = criar_lista(n);

    ler_operacoes(m, heap);

    return EXIT_SUCCESS;
}
