#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "heap.h"

void imprimir_mediana(int i, FilaPrioridade* max_heap, FilaPrioridade* min_heap) {
   if (obter_tamanho_atual(max_heap) == obter_tamanho_atual(min_heap)) { //imprimir duas caixas do meio
      printf("%d %s %s\n", i + 1, obter_identificador(obter_raiz(max_heap)), obter_identificador(obter_raiz(min_heap)));
   } else if (obter_tamanho_atual(max_heap) > obter_tamanho_atual(min_heap)) { //imprimir caixa do meio
      printf("%d %s\n", i + 1, obter_identificador(obter_raiz(max_heap)));
   } else if (obter_tamanho_atual(min_heap) > obter_tamanho_atual(max_heap)) { //imprimir duas caixas do meio
      printf("%d %s\n", i + 1, obter_identificador(obter_raiz(min_heap)));
   }
}   

int main()
{
   int n, m;
   Item *item;
   FilaPrioridade *max_heap;
   FilaPrioridade *min_heap;

   char *identificador = calloc(5, sizeof(char));

   if (identificador == NULL) {
      printf("Não foi possível alocar identificador \n");
      exit(1);
   }

   scanf("%d", &n);

   for (int i = 0; i < n; ++i) {
      scanf("%d", &m);
      //criar heaps mínimos e máximos
      max_heap = criar_fila_prio(m);
      min_heap = criar_fila_prio(m);

      for (int j = 0; j < m; j++) {
         scanf("%s\n", identificador);
         item = criar_item(identificador);

         if (obter_tamanho_atual(max_heap) == 0) {
            //adicionar no início do max-heap
            inserir(max_heap, *item, MAX);
         } else if (obter_tamanho_atual(min_heap) == 0) {
            if (strcmp(obter_identificador(*item), obter_identificador(obter_raiz(max_heap))) > 0) {
               //adicionar no início do min-heap
               inserir(min_heap, *item, MIN);
            } else {
               //remover do max-heap e adicionar no início do min-heap
               inserir(min_heap, extrai_raiz(max_heap, MAX), MIN);
               inserir(max_heap, *item, MAX);  
            }
         } else if (obter_tamanho_atual(max_heap) <= obter_tamanho_atual(min_heap) &&
               strcmp(obter_identificador(obter_raiz(min_heap)), obter_identificador(*item)) > 0) {
            inserir(max_heap, *item, MAX);
         } else if (obter_tamanho_atual(max_heap) >= obter_tamanho_atual(min_heap) &&
               strcmp(obter_identificador(obter_raiz(max_heap)), obter_identificador(*item)) < 0) {
            inserir(min_heap, *item, MIN);
         } else if (obter_tamanho_atual(max_heap) > obter_tamanho_atual(min_heap) &&
               strcmp(obter_identificador(obter_raiz(max_heap)), obter_identificador(*item)) > 0) {
            //remover raiz do max-heap e adicionar o item      
            inserir(min_heap, extrai_raiz(max_heap, MAX), MIN);
            inserir(max_heap, *item, MAX);
         } else if (obter_tamanho_atual(max_heap) < obter_tamanho_atual(min_heap) &&
               strcmp(obter_identificador(obter_raiz(min_heap)), obter_identificador(*item)) < 0) {
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
