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

    Pilha* pilha = criar_pilha();
    Lista* lista = criar_lista();

    for (int i = 0; i < m; i++)
    {
        caractere_sequencia = 0;

        while (caractere_sequencia != ' ') {
            scanf("%c", &caractere_sequencia);
            if (caractere_sequencia != ' ') {
                inserir_no(lista, caractere_sequencia);
            }
        }

        scanf("%d", &n);

        getchar();

        find_maior_valor(pilha, lista, n);   

        // imprimir_pilha(pilha);

        limpar_pilha(pilha);
        limpar_lista(lista);
    }

    // limpar_pilha(pilha);

    free(pilha);
    free(lista);

    return EXIT_SUCCESS;
}
