#include <cstdio> // em C substituir por #include <stdio.h>
#include <iostream>
#include <cmath>

#include "planeta.h"
#include "mergesort.h"
#include "radixsort.h"

int main() {
  int t, p, c;
  while(scanf("%d %d %d", &t, &p, &c) != EOF) {

    //Variáveis
    Planeta vetor[p];
    int meses, cursor, e, i, visitas_mes, cont;
    i= e= cursor= meses= visitas_mes= cont= 0;

    //Leitura de planetas
    for(i=0; i<p; i++){
      //scanf("%d %s", &vetor[i].tempo, &vetor[i].nome);
      std::cin >> vetor[i].tempo >> vetor[i].nome;
    }
    for(int i=0; i<p; i++){
      //printf("%d\t", vetor[i].tempo);
      //std::cout << vetor[i].nome << " " << vetor[i].tempo << std::endl;
    }

    //Teste
    //radixsort(vetor, p, c);

    //Ordenar por tempo de maneira estável
    mergesort(vetor, 0, p-1);

    //Faz a soma total dos tempos de visitação
    for(int i=0; i<p; i++){
      //printf("%d\t", vetor[i].tempo);
      //std::cout << vetor[i].nome << " " << vetor[i].tempo << std::endl;
      meses+= vetor[i].tempo;
    }

    //Calcula a quantidade de meses necessários para todas as visitações
    meses= ceil((float) meses/t);
    i= 0;
    //printf("%d\n", meses);

    if(meses>1){
      while(cont<= meses){
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
          radixsort(aux, i-e, c);
          for(int j=0; j<i-e; j++){
            vetor[j+e].mes= aux[j].mes;
            vetor[j+e].nome= aux[j].nome;
            vetor[j+e].tempo= aux[j].tempo;            
          }
          cont++;
          e= cursor;
        }
      }
    }else{
      //joga o vetor inteiro no RADIX
      radixsort(vetor, p, c);
      /*for(int i=0; i<p; i++){
        //printf("%d\t", vetor[i].tempo);
        std::cout << vetor[i].mes << " " << vetor[i].nome << " " << vetor[i].tempo << std::endl;
      }*/
    }
    for(int i=0; i<p; i++){
      //printf("%d\t", vetor[i].tempo);
      std::cout << vetor[i].mes << " " << vetor[i].nome << " " << vetor[i].tempo << std::endl;
    }

  }

  return 0;
}
