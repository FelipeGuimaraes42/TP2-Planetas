#include <cstdio> // em C substituir por #include <stdio.h>
#include <iostream>
#include <cmath>

#include "planeta.h"
#include "mergesort.h"

int main() {
  int t, p, c;
  printf("Inicio!\n");
  while(scanf("%d %d %d", &t, &p, &c) != EOF) {
    Planeta vetor[p];
    int meses, cursor, e, i;
    i= e= cursor= meses= 0;
    int visitas_mes= 0;
    int cont= 0;
    for(int i=0; i<p; i++){
      //scanf("%d %s", &vetor[i].tempo, &vetor[i].nome);
      std::cin >> vetor[i].tempo >> vetor[i].nome;
    }
    for(int i=0; i<p; i++){
      //printf("%d\t", vetor[i].tempo);
      std::cout << vetor[i].nome << " " << vetor[i].tempo << std::endl;
    }
    printf("Fim!\n");
    mergesort(vetor, 0, p-1);
    for(int i=0; i<p; i++){
      //printf("%d\t", vetor[i].tempo);
      meses+= vetor[i].tempo;
      std::cout << vetor[i].nome << " " << vetor[i].tempo << std::endl;
    }
    printf("Fim!\n");

    meses= ceil((float) meses/t);
    std::cout << meses << std::endl;

    if(meses>1){
      /*for(i= 0; i<=p; i++){
        if(((visitas_mes+ vetor[i].tempo)<= t) && (i<p)){
          visitas_mes+= vetor[i].tempo;
        }else{
          visitas_mes= 0;
          Planeta *aux= new Planeta[i];
          for(int j=0; j<i-e; j++){
            aux[j]= vetor[cursor];
            aux[j].mes= cont;
            cursor++;
          }
          e= cursor;
          //RADIX e copiar no vetor principal
          cont++;
          for(int j=0; j<=p-e; j++){
            std::cout << aux[j].mes << " " << aux[j].nome << " " << aux[j].tempo << std::endl;
          }
        }
      }*/
      while(cont< meses){
        if(((visitas_mes+ vetor[i].tempo)<= t) && (i<p)){
          visitas_mes+= vetor[i].tempo;
          i++;
        }else{
          visitas_mes= 0;
          Planeta *aux= new Planeta[i-e];
          for(int j=0; j<i-e; j++){
            aux[j]= vetor[cursor];
            aux[j].mes= cont+1;
            cursor++;
          }
          //RADIX e copiar no vetor principal
          cont++;
          for(int j=0; j<i-e; j++){
            std::cout << aux[j].mes << " " << aux[j].nome << " " << aux[j].tempo << std::endl;
          }
          e= cursor;
        }
      }
    }else{
      //joga o vetor inteiro no RADIX
    }

  }

  return 0;
}
