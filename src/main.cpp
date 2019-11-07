#include <cstdio> // em C substituir por #include <stdio.h>

#include "include/planeta.h"
#include "include/mergesort.h"
#include "include/radixsort.h"

int main() {
  int t, p, c;
  while(scanf("%d %d %d", &t, &p, &c) != EOF) {
    //Variáveis
    Planeta vetor[p+1];
    //Leitura de planetas
    le_planetas(vetor, p);
    //Sentinela na posição final
    vetor[p].tempo= 0;
    //Ordenar por tempo de maneira estável
    mergesort(vetor, 0, p-1);
    //Separa os subvetores e passa eles para o radix
    radix_mes(vetor, p, t, c);
    //Printa mês, nome e tempo de todos os planetas visitados
    printa_planetas(vetor, p);
  }
  return 0;
}
