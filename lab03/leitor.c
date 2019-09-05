#include <stdlib.h>
#include <string.h>

#include "leitor.h"

Leitor criar_leitor(const char* nome, int e)
{
    Leitor leitor;

    strcpy(leitor.nome, nome);
    leitor.restituicoes = malloc(e * sizeof(int));
    leitor.devolucoes = malloc(e * sizeof(int));
    leitor.num_restituicoes = 0;
    leitor.num_devolucoes = 0;

    return leitor;
}

void desalocar_memoria(Leitor* leitor)
{
    free(leitor);
}

const char* obter_nome(const Leitor* leitor)
{
    return leitor->nome;
}

void registrar_restituicao(Leitor* leitor, int i)
{
    leitor->restituicoes[leitor->num_restituicoes++] = i;
}

void registrar_devolucao(Leitor* leitor, int i)
{
    leitor->devolucoes[leitor->num_devolucoes++] = i;
}

const int* obter_restituicoes(const Leitor* leitor)
{
    return leitor->restituicoes;
}

const int* obter_devolucoes(const Leitor* leitor)
{
    return leitor->devolucoes;
}

int obter_num_restituicoes(const Leitor* leitor)
{
    return leitor->num_restituicoes;
}

int obter_num_devolucoes(const Leitor* leitor)
{
    return leitor->num_devolucoes;
}
