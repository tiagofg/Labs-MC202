#include <stdio.h>
#include <stdlib.h>

#include "abb.h"

void ler_e_inserir_dado(int identificador, ArvoreBusca* arvore, char* dado) {
    if (identificador != FIM_MSG) {
        getchar(); //lendo espaço vazio
        scanf("%[^\n]s", dado);

        inserir(arvore, arvore->raiz, identificador, dado); //inserindo na árvore
    }
}

int main()
{
    int identificador = -1; //inicializando identificador
    char* dado = malloc(TAM_DADO * sizeof(dado)); //8 bits e um \0

    if (dado == NULL) {
        printf("Falha ao alocar dado para leitura \n");
        exit(1);
    }

    ArvoreBusca* arvore = criar_arvore();

    while (identificador != FIM_MSG) {
        scanf("%d", &identificador);

        //lê o dado e insere na árvore
        ler_e_inserir_dado(identificador, arvore, dado);
    }

    imprimir_mensagem(arvore); //imprimir mensagem decodificada
    
    destruir_arvore(arvore); //destruir a árvore e seus nós

    free(dado); //liberar memória do pedaço da mensagem

   return EXIT_SUCCESS;
}
