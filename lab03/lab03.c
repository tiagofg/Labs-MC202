#include <stdio.h>
#include <stdlib.h>
#include "livro.h"
#include "leitor.h"

void obter_livros(Livro* livros, int m, char* titulo) {
    int dia, mes, ano;
    Data data;
    Livro livro;

    for (int i = 0; i < m; i++){
        scanf("%d-%d-%d\n", &dia, &mes, &ano);
        scanf(" %[^\n]", titulo);

        data = criar_data(dia, mes, ano);
        livro = criar_livro(titulo, data);

        livros[i] = livro;
    }
}

void obter_leitores(Leitor* leitores, int n, char* nome) {
    int e, num_livro;
    Leitor leitor;

    for (int i = 0; i < n; i++){
        scanf("%[^\n] ", nome);
        scanf("%d", &e);

        leitor = criar_leitor(nome, e);

        for (int j = 0; j < e; j ++)
        {
            scanf("%d", &num_livro);

            if (num_livro > 0) {
                registrar_restituicao(&leitor, num_livro);
            }
            else if (num_livro < 0){
                registrar_devolucao(&leitor, num_livro);
            }
        }

        leitores[i] = leitor;
    }
}

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
    int m, n;
    scanf("%d %d\n", &m, &n);

    livros = malloc(m * sizeof(Livro));
    leitores = malloc(n * sizeof(Leitor));

    obter_livros(livros, m, titulo);

    obter_leitores(leitores, n, nome);

    free(livros);
    free(leitores);

    return 0;
}
