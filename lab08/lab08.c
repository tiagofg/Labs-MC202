#include <stdio.h>
#include <stdlib.h>

#include "abb.h"

int main()
{
    int identificador, ultimo_identificador = 0;
    char* dado = malloc(8 * sizeof(dado));
    ArvoreBusca* arvore = criar_arvore();
    // No* buscado;

    for (;;) {
        scanf("%d", &identificador);

        if (identificador == 0) {
            break;
        } else if (identificador > ultimo_identificador) {
            ultimo_identificador = identificador;
        }

        getchar();
        scanf("%[^\n]s", dado);

        inserir(arvore, arvore->raiz, identificador, dado);
    }

    imprimir_mensagem(arvore, ultimo_identificador);
    free(dado);
    free(arvore);

   return EXIT_SUCCESS;
}
