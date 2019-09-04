#include <stdio.h>
#include <stdlib.h>
#include "livro.h"
#include "leitor.h"

int main()
{
   char titulo[MAXCHAR_TITULO]; // string para a leitura do título
   char nome[MAXCHAR_LNOME];    // string para a leitura do nome

   Livro* livros = NULL;        // ponteiro para o vetor de livros
   Leitor* leitores = NULL;     // ponteiro para o vetor de leitores

   /** ************************************************************************
    *               ATENÇÃO: É preciso implementar esta função!               *
    *********************************************************************** **/

    // Esta função não devem acessar diretamente os campos de um TAD, i.e.,
    // os campos das estruturas Livro, Leitor e Data.

    // Para a implementação desta função você deverá fazer a chamada de funções
    // que operação sobre os TADs (conforme os protótipos definidos nos arquivos
    // de cabeçalho).


   free(livros);
   free(leitores);

   return 0;
}
