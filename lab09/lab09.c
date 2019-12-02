#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "heap.h"

void imprimir_mediana(int i, FilaPrioridade* max_heap, FilaPrioridade* min_heap) {
   if (max_heap->n == min_heap->n) { //imprimir duas caixas do meio
      printf("%d %s %s\n", i + 1, max_heap->vetor[0].identificador, min_heap->vetor[0].identificador);
   } else if (max_heap->n > min_heap->n) { //imprimir caixa do meio
      printf("%d %s\n", i + 1, max_heap->vetor[0].identificador);
   } else if (min_heap->n > max_heap->n) { //imprimir duas caixas do meio
      printf("%d %s\n", i + 1, min_heap->vetor[0].identificador);
   }
}   

int main()
{
   int n, m;
   Item *item;
   char *identificador = calloc(5, sizeof(char));
   FilaPrioridade *max_heap;
   FilaPrioridade *min_heap;

   scanf("%d", &n);

   for (int i = 0; i < n; ++i) {
      scanf("%d", &m);
      //criar heaps mínimos e máximos
      max_heap = criar_fila_prio(m);
      min_heap = criar_fila_prio(m);

      for (int j = 0; j < m; j++) {
         scanf("%s\n", identificador);
         item = criar_item(identificador);

         if (max_heap->n == 0) {
            //adicionar no início do max-heap
            inserir(max_heap, *item, MAX);
         } else if (min_heap->n == 0) {
            if (strcmp(item->identificador, max_heap->vetor[0].identificador) > 0) {
               //adicionar no início do min-heap
               inserir(min_heap, *item, MIN);
            } else {
               //remover do max-heap e adicionar no início do min-heap
               inserir(min_heap, extrai_raiz(max_heap, MAX), MIN);
               inserir(max_heap, *item, MAX);  
            }
         } else if (max_heap->n <= min_heap->n &&
               strcmp(min_heap->vetor[0].identificador, item->identificador) > 0) {
            inserir(max_heap, *item, MAX);
         } else if (max_heap->n >= min_heap->n &&
               strcmp(max_heap->vetor[0].identificador, item->identificador) < 0) {
            inserir(min_heap, *item, MIN);
         } else if (max_heap->n > min_heap->n &&
               strcmp(max_heap->vetor[0].identificador, item->identificador) > 0) {
            //remover raiz do max-heap e adicionar o item      
            inserir(min_heap, extrai_raiz(max_heap, MAX), MIN);
            inserir(max_heap, *item, MAX);
         } else if (max_heap->n < min_heap->n &&
               strcmp(min_heap->vetor[0].identificador, item->identificador) < 0) {
            //remover raiz do min-heap e adicionar o item 
            inserir(max_heap, extrai_raiz(min_heap, MIN), MAX);
            inserir(min_heap, *item, MIN);
         }  else {
            inserir(max_heap, *item, MAX);
         }

         if (((j + 1) % 5 == 0 || (j + 1) == m)) {
            imprimir_mediana(i, max_heap, min_heap);
         }

         free(item);
      }

      destruir_fila_prio(max_heap);
      destruir_fila_prio(min_heap);
   }

   free(identificador);

   return EXIT_SUCCESS;
}
