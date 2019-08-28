#include <stdio.h>

#include "aluno.h"
#include "professor.h"

#define MAX_M 100 // nº máximo de professores
#define MAX_N 200 // nº máximo de alunos

void processar_aumento(Professor professores[], Aluno alunos[], int m, int n);

int main()
{
    /** ***********************************************************************
    *          ATENÇÃO: A função principal não deve ser modificada!           *
    *********************************************************************** **/

   Professor professores[MAX_M];  // vetor para o conjunto de professores
   Aluno alunos[MAX_N];           // vetor para o conjunto de alunos

   char nome[MAXCHAR_PNOME], disciplina[MAXCHAR_CODIGO];
   float salario, desempenho;
   int registro_academico, num_disciplinas;

   int m, n;

   scanf("%d", &m); // lê o nº de professores

   for (int i = 0; i < m; ++i) { // segue com a leitura dos professores
      scanf(" %s %f %s", nome, &salario, disciplina);
      professores[i] = criar_professor(nome, salario, disciplina);
   }

	scanf("%d", &n);  // lê o nº de alunos

   for (int i = 0; i < n; ++i) { // segue com a leitura dos alunos

      scanf("%d %f %d", &registro_academico, &desempenho, &num_disciplinas);
      alunos[i] = criar_aluno(registro_academico, desempenho);

      while (num_disciplinas > 0) {
         scanf(" %s", disciplina);
         alunos[i] = adicionar_disciplina(alunos[i], disciplina);
         num_disciplinas -= 1;
      }
   }

	processar_aumento(professores, alunos, m, n); // processa a bonificação

   for (int i = 0; i < m; ++i) { // segue com a impressão da saída
      obter_nome(professores[i], nome);
      printf("%s %.2f\n", nome, obter_salario(professores[i]));
   }

	return 0;
}

 int validar_desempenho(Aluno matriculados[], int n, float desempenho){ //função para verificar o desempenho de todos os alunos matriculados em uma disciplina
     for (int i = 0; i < n; i++) {
         if (obter_desempenho(matriculados[i]) < desempenho) {
             return 0; //retorna 0 se a média de algum dos alunos for menor que a esperada
         }
     }

     return 1; //retorna 1 se todos os alunos estiverem acima da média esperada
 }

 float bonificacao(Aluno alunos[], int n, char disciplina[]) {
     Aluno alunosMatriculados[n];
     int j = 0;
     for (int i = 0; i < n; i++) {
         if (validar_matricula(alunos[i], disciplina) == 1) {
             alunosMatriculados[j++] = alunos[i]; //vetor com todos os alunos matriculados em uma disciplina
         }
     }

     if (validar_desempenho(alunosMatriculados, j, 10.0) == 1) { //verificação de média 10
         return 0.15;
     }
     else if (validar_desempenho(alunosMatriculados, j, 9.0) == 1) { //verificação de média 9 ou superior
         return 0.1;
     }
     else if (validar_desempenho(alunosMatriculados, j, 8.5) == 1) { //verificação de média 8.5 ou superior
         return 0.05;
     }

     return 0; //retorna 0 se não houver nenhuma bonificação
 }


void processar_aumento(Professor professores[], Aluno alunos[], int m, int n)
{
    char disciplina[MAXCHAR_CODIGO]; //variável que armazena a disciplina de cada professor;
    Professor professor; //variável para armazenar o professor que vai ser sobrescrito
    for (int i = 0; i < m; i++) {
        obter_disciplina(professores[i], disciplina);
        professor = aplicar_aumento(professores[i], bonificacao(alunos, n, disciplina));
        professores[i] = professor; //sobrescrevendo professor
    }
}
