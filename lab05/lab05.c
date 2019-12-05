#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

void ler_operacoes(int m, Lista* heap) {
    char operacao;
    int endereco_segmento, tamanho_segmento, novo_tamanho_segmento;

    for (int i = 0; i <= m; i++) {
        scanf("%c ", &operacao);

        if (operacao == 'A') {
            //Caso a operação seja A, alocar memória
            scanf("%d\n", &tamanho_segmento);
            alocar_memoria(heap, tamanho_segmento);
        } else if (operacao == 'D') {
            //Caso a operação seja D, desalocar memória
            scanf("%d %d\n", &endereco_segmento, &tamanho_segmento);
            desalocar_memoria(heap, endereco_segmento, tamanho_segmento);
        } else if (operacao == 'R') {
            //Caso a operação seja R, realocar memória
            scanf("%d %d %d\n", &endereco_segmento, &tamanho_segmento, &novo_tamanho_segmento);
            realocar_memoria(heap, endereco_segmento, tamanho_segmento, novo_tamanho_segmento);
        } else if (operacao == 'P') {
            //Caso a operação seja P, imprimir heap
            imprimir_heap(heap);
        }
    }
}

int main()
{
    int m, n;

    scanf("%d %d", &m, &n);

    Lista* heap = criar_lista(n);

    ler_operacoes(m, heap);

    destruir_lista(heap);

    return EXIT_SUCCESS;
}
