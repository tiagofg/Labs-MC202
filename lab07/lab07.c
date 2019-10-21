#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arvore.h"

int main()
{
	int m;
	int valor;
	char *buffer = malloc(3 * sizeof(char));
	char operador, variavel;
	No* no;
	No* topo;
	No* atual = malloc(sizeof(No));
	Arvore* arvore = criar_arvore();
	Pilha* pilha = criar_pilha();

	scanf("%d ", &m);

	for (int i = 0; i < m; i++)
	{
		do {
			scanf("%s", buffer);

			if (buffer[0] == '(')
			{
				no = criar_no('#', 0);
				atual = iniciar_operacao(arvore, no, atual);
				empilhar(pilha, no);
			}
			else if (buffer[0] >= '0' && buffer[0] <= '9')
			{
				valor = atoi(buffer);
				no = criar_no(' ', valor);	
				if (atual->esquerdo == NULL) {
					atual->esquerdo = no; 
				} else if (atual->direito == NULL) {
					atual->direito = no;
				}		
			}
			else if (buffer[0] >= '-' && strlen(buffer) > 1)
			{
				valor = atoi(buffer);
				no = criar_no(' ', valor);	
				if (atual->esquerdo == NULL) {
					atual->esquerdo = no; 
				} else if (atual->direito == NULL) {
					atual->direito = no;
				}		
			}
			else if (buffer[0] == ')')
			{
				desempilhar(pilha);
			}
			else if (buffer[0] == '+' || buffer[0] == '-' || buffer[0] == '/' || buffer[0] == '*')
			{
				operador = buffer[0];
				topo = pilha->topo;
				topo->dado = operador;
				atual = topo;
			} else {
				variavel = buffer[0];
				no = criar_no(variavel, 0);
				if (atual->esquerdo == NULL) {
					atual->esquerdo = no; 
				} else if (atual->direito == NULL) {
					atual->direito = no;
				}
			} 
		} while (getchar() != '\n');

		printar_arvore(arvore->raiz);
		printf("\n");
		limpar_arvore(arvore);
	}

	return EXIT_SUCCESS;
}
