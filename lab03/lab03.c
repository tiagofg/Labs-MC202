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
	data = criar_data(dia, mes, ano);
	
        scanf(" %[^\n]", titulo);        
        livro = criar_livro(titulo, data);

        livros[i] = livro;
    }
}

void obter_leitores(Leitor* leitores, int n, char* nome) {
    int e, num_livro;
    Leitor leitor;

    for (int i = 0; i < n; i++){	       
        scanf("%s ", nome);
	
        scanf("%d ", &e);

        leitor = criar_leitor(nome, e);

        for (int j = 0; j < e; j ++)
        {
            scanf("%d ", &num_livro);

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

void obter_saida(Livro* livros, Leitor* leitores, int m, int n, Data dataConsulta) {
  for (int i = 0; i < n; i++) {
      const int* restituicoes = obter_restituicoes(&leitores[i]);
      
      for (int j = 0; i < obter_num_restituicoes(&leitores[i]); j++) {
	  int num_livro = restituicoes[j];

	  if (eh_menor_que(obter_data_emprestimo(&livros[num_livro - 1]), dataConsulta) == 1) {
	      printf("Restituição: %s\n", obter_titulo(&livros[num_livro - 1]));
	  }    
          
      }
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
    printf("m: %d", m);
    printf("n: %d\n", n);

    livros = malloc(m * sizeof(Livro));
    leitores = malloc(n * sizeof(Leitor));

    obter_livros(livros, m, titulo);
    obter_leitores(leitores, n, nome);

    int dia, mes, ano;
    Data dataConsulta;
    scanf("%d-%d-%d\n", &dia, &mes, &ano);
    dataConsulta = criar_data(dia, mes, ano);

    obter_saida(livros, leitores, m, n, dataConsulta);

    free(livros);
    free(leitores);

    return 0;
}
