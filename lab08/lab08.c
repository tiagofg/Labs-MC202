#include <stdio.h>
#include <stdlib.h>

#include "abb.h"

int main()
{
    int identificador, qtde_dados = 0;
    char* dado = malloc(8 * sizeof(dado));
    ArvoreBusca* arvore = criar_arvore();
    No* buscado;

    for (;;) {
        scanf("%d ", &identificador);

        if (identificador == 0) {
            break;
        }

        scanf("%[^\n]s", dado);

        inserir(arvore, arvore->raiz, identificador, dado);
        qtde_dados++;
    }

    for (int i = 1; i <= 3; i++) {
        buscado = buscar(arvore->raiz, i);

        printf("%s", buscado->dado);
    }

    // imprimir_mensagem(arvore, qtde_dados);
    free(dado);
    free(arvore);

   return EXIT_SUCCESS;
}
