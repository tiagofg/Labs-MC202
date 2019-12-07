#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#endif

typedef struct {
    char* chave;
    int posicao;
} No;

typedef struct {
    No* vetor;
    int tamanho;
} Hash;

Hash* criar_hash(int n);

void destruir_hash(Hash* hash);

int gerar_hash(char *chave, int tamanho);

void inserir(Hash* hash, char *chave, int posicao);

void esta_no_hash(Hash* hash, char* chave, int* qtde_ocorrencias);
