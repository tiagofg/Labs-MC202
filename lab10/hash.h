#ifndef HASH_TABLE_H
#define HASH_TABLE_H



#endif

#define MAX 100

typedef struct {
    char chave[100];
    int num_ocorrencias;
} No;

typedef struct {
    No vetor[MAX];
} Hash;

Hash* criar_hash();

int gerar_hash(char *chave);

void inserir(Hash* hash, char *chave, int num_ocorrencias);
