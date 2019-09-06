#include <stdio.h>
#include <stdlib.h>
#include "livro.h"
#include "leitor.h"

void obter_livros(Livro* livros, int m, char* titulo) {
    int dia, mes, ano;
    Data data;
    Livro livro;

    for (int i = 0; i < m; i++){
        //leitura da data de devolução e do título
        scanf("%d-%d-%d\n", &dia, &mes, &ano);
        scanf(" %[^\n]", titulo);

        //criação de data e livro
	    data = criar_data(dia, mes, ano);
        livro = criar_livro(titulo, data);

        //atribuição no vetor de livros
        livros[i] = livro;
    }
}

void obter_leitores(Leitor* leitores, int n, char* nome) {
    int e, num_livro;
    Leitor leitor;

    for (int i = 0; i < n; i++){
        //leitura do nome e da quantidade de registros
        scanf("%s ", nome);
        scanf("%d ", &e);

        //criação do leitor
        leitor = criar_leitor(nome, e);

        for (int j = 0; j < e; j ++)
        {
            //leitura do número do livro
            scanf("%d ", &num_livro);

            //condição para saber se o livro está sendo restituído ou devolvido
            if (num_livro > 0) {
                registrar_restituicao(&leitor, num_livro);
            }
            else if (num_livro < 0){
                registrar_devolucao(&leitor, num_livro);
            }
        }

        //atribuição no vetor de leitores
        leitores[i] = leitor;
    }
}

void obter_saida(Livro* livros, Leitor* leitores, int m, int n, Data dataConsulta) {
    for (int i = 0; i < n; i++) {
        //obtenção dos vetores de restituições e devoluções
        const int* restituicoes = obter_restituicoes(&leitores[i]);
        const int* devolucoes = obter_devolucoes(&leitores[i]);

        printf("%s\n", obter_nome(&leitores[i])); //print do nome do leitor

        for (int j = 0; j < obter_num_restituicoes(&leitores[i]); j++) {
            //obtenção de número do livro e data de empréstimo
            int num_livro = restituicoes[j];
            Data data_emprestimo = obter_data_emprestimo(&livros[num_livro - 1]);

            //regra para escrever a restituição ou não
    	    if (eh_menor_que(data_emprestimo, dataConsulta) == 1 && eh_nula(data_emprestimo) == 0) {
    	        printf("Restituição: %s\n", obter_titulo(&livros[num_livro - 1]));
    	    }

        }

        for (int k = 0; k < obter_num_devolucoes(&leitores[i]); k++) {
            //obtenção de número do livro e data de empréstimo
    	    int num_livro = devolucoes[k] * -1;
            Data data_emprestimo = obter_data_emprestimo(&livros[num_livro - 1]);

            //regra para escrever a devolução ou não
    	    if (eh_menor_que(data_emprestimo, dataConsulta) == 1 && eh_nula(data_emprestimo) == 0) {
    	        printf("Devolução: %s\n", obter_titulo(&livros[num_livro - 1]));
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

    int m, n;
    scanf("%d %d\n", &m, &n);

    livros = malloc(m * sizeof(Livro)); //alocação de memória para vetor de livros
    leitores = malloc(n * sizeof(Leitor)); //alocação de memória para vetor de leitores

    obter_livros(livros, m, titulo); //método para ler informações de livros
    obter_leitores(leitores, n, nome); //método para ler informações de leitores

    //leitura da data de consulta
    int dia, mes, ano;
    Data data_consulta;
    scanf("%d-%d-%d\n", &dia, &mes, &ano);
    data_consulta = criar_data(dia, mes, ano);

    obter_saida(livros, leitores, m, n, data_consulta); //método que obtem o resultado da saída

    free(livros);
    free(leitores);

    return 0;
}
