#ifndef HASH_TABLE_H
#define HASH_TABLE_H



#endif

typedef struct {
    char chave[100];
    int num_ocorrencias;
} No;

typedef struct {
    No* vetor;
} Hash;

Hash* criar_hash(int n);

int gerar_hash(char *chave, int num);

void inserir(Hash* hash, char *chave, int num_ocorrencias, int n);
