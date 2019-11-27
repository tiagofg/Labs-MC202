#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#endif

typedef struct {
    char chave[100];
    int ordem;
} No;

typedef struct {
    No* vetor;
} Hash;

Hash* criar_hash(int n);

void destruir_hash(Hash* hash);

int gerar_hash(char *chave, int num);

void inserir(Hash* hash, char *chave, int n, int ordem);

No find_padrao(Hash* hash, int ordem, int n);
