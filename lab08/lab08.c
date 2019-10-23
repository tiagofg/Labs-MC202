#include <stdio.h>
#include <stdlib.h>

#include "abb.h"

int main()
{
    int identificador, ultimo_identificador = 0;
    char* dado = malloc(9 * sizeof(dado)); //8 bits e um \0
    ArvoreBusca* arvore = criar_arvore();

    for (;;) {
        scanf("%d", &identificador);

        if (identificador == 0) {
            break; //parar quando identicador for 0
        } else if (identificador > ultimo_identificador) {
            ultimo_identificador = identificador; //pegar o valor do maior identificador para saber a quantidade de dados
        }

        getchar(); //lendo espaço vazio
        scanf("%[^\n]s", dado);

        inserir(arvore, arvore->raiz, identificador, dado); //inserindo na árvore
    }

    imprimir_mensagem(arvore, ultimo_identificador); //imprimir mensagem decodificada
    
    destruir_arvore(arvore, ultimo_identificador); //destruir a árvore e seus nós

    free(dado); //liberar memória do pedaço da mensagem

   return EXIT_SUCCESS;
}
