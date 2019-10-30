#ifndef HEAP_H
#define HEAP_H
#define PAI(i) ((i-1)/2)
#define F_ESQ(i) (2*i+1)
#define F_DIR(i) (2*i+2)
#define MAX 1
#define MIN 2

#endif

typedef struct {
    char* identificador;
    int chave;
} Item;

typedef struct {
    Item* vetor;
    int n, tamanho;
} FilaPrioridade;

void troca(Item *a, Item *b);

int gerar_chave(char* identificador);

Item* criar_item(char* identificador);

FilaPrioridade* criar_fila_prio(int tam);

void inserir(FilaPrioridade* fila_prio, Item* item, int tipo);

void sobe_no_heap(FilaPrioridade* fila_prio, int k);

void desce_no_heap(FilaPrioridade* fila_prio, int k);
