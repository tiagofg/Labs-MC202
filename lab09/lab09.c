#include <stdlib.h>
#include <stdio.h>

#include "heap.h"

int main()
{
   int n, m;
   Item *item;
   char *identificador = malloc(5 * sizeof(char));
   FilaPrioridade *heap_max;
   FilaPrioridade *heap_min;

   scanf("%d", &n);

   for (int i = 0; i < n; ++i) {
      scanf("%d", &m);
      heap_max = criar_fila_prio(m);
      heap_min = criar_fila_prio(m);

      for (int j = 0; j < m; j++) {
         scanf("%s\n", identificador);
         item = criar_item(identificador);

         //extrair minimo do heap max e maximo do heap minimo

         if (heap_max->n == 0) {
            printf("Inserir no heap_max 0 \n");      
            inserir(heap_max, *item, MAX);
         } else if (heap_min->n == 0) {
            printf("Inserir no heap_min 0 \n"); 
            inserir(heap_min, *item, MIN);
         } else if (heap_max->n == heap_min->n &&
               heap_min->vetor[0].chave > item->chave) {
            printf("Inserir no heap_max 1 \n");      
            inserir(heap_max, *item, MAX);
         } else if (heap_max->n == heap_min->n &&
               heap_max->vetor[0].chave > item->chave) {
            printf("Inserir no heap_min 1 \n");       
            inserir(heap_min, *item, MIN);
         } else if (heap_max->n > heap_min->n &&
               heap_min->vetor[0].chave > item->chave) {
            printf("Inserir no heap_min 2 \n"); 
            inserir(heap_min, *item, MIN);
         } else if (heap_max->n < heap_min->n &&
               heap_max->vetor[0].chave > item->chave) {
            printf("Inserir no heap_max 2 \n");       
            inserir(heap_max, *item, MAX);
         }  else if (heap_max->n > heap_min->n &&
               heap_min->vetor[0].chave < item->chave) {
            printf("Inserir no heap_min 3 \n"); 
            inserir(heap_min, *item, MIN);
         } else if (heap_max->n < heap_min->n &&
               heap_max->vetor[0].chave < item->chave) {
            printf("Inserir no heap_max 3 \n");       
            inserir(heap_max, *item, MAX);
         } else {
            printf("Não inseriu \n");
         }

         // if (j % 5 == 0 || j == m - 1) {
         //    if (heap_max->n == heap_min->n){
         //       printf("%d %s %s\n", i + 1, heap_max->vetor[0].identificador, heap_min->vetor[0].identificador);
         //    } else if (heap_max->n % 2 != 0) {
         //       printf("%d %s\n", i + 1, heap_max->vetor[0].identificador);
         //    } else if (heap_min->n % 2 != 0) {
         //       printf("%d %s\n", i + 1, heap_min->vetor[0].identificador);
         //    }
         // }
      }

      printf("%s %s\n", heap_max->vetor[0].identificador, heap_min->vetor[0].identificador);

      free(heap_max);
      free(heap_min);
   }

   return EXIT_SUCCESS;
}
