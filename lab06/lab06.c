#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilha.h"

#define MAX_SEQUENCIA 50

int main()
{
    int m, n;

    scanf("%d\n", &m);

    char caractere_sequencia;
    int num_sequencia;

    Pilha *pilha = criar_pilha();

    for (int i = 0; i < m; i++)
    {
        caractere_sequencia = 0;

        while (caractere_sequencia != ' ') {
            scanf("%c", &caractere_sequencia);
            num_sequencia = (int) caractere_sequencia - 48;
            if (num_sequencia >= 0) {
                empilhar(pilha, num_sequencia);
            }
        }

        pilha = inverter_pilha(pilha);

        scanf("%d", &n);

        find_maior_valor(pilha, n);   

        imprimir_pilha(pilha);

        limpar_pilha(pilha);
    }

    limpar_pilha(pilha);

    free(pilha);

    return EXIT_SUCCESS;
}
