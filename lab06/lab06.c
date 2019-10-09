#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilha.h"

#define MAX_SEQUENCIA 50

int main()
{
   int m, n;

   scanf("%d", &m);

   char* sequencia = malloc(MAX_SEQUENCIA * sizeof(char));
   int num_sequencia;

   Pilha* pilha = criar_pilha();

   for (int i = 0; i < m; i++) {
       scanf("%s", sequencia);

       for (int j = 0; j < strlen(sequencia); j++) {
           num_sequencia = (int) sequencia[j] - '0';
           empilhar(pilha, num_sequencia);
       }

       scanf("%d\n", &n);

       // for (int k = 0; k < n; k++) {
           remover_menor_dado(pilha);
       // }

       imprimir_pilha(pilha);

       limpar_pilha(pilha);
   }

   //desalocar memória

   return EXIT_SUCCESS;
}
