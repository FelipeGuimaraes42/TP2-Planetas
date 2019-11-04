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
    //Planeta vetor[p];
    //Sentinela na posição final
    Planeta vetor[p+1];
    int meses, cursor, e, i, visitas_mes, cont, soma, j;
    i= e= cursor= meses= visitas_mes= cont= soma= 0;

    //Leitura de planetas
    for(j=0; j<p; j++){
      std::cin >> vetor[j].tempo >> vetor[j].nome;
    }
    //Sentinela
    vetor[p].tempo= 0;

    //Ordenar por tempo de maneira estável
    mergesort(vetor, 0, p-1);

    //Faz o cálculo total dos meses de visitação
    for(j=0; j<p; j++){
      soma+= vetor[j].tempo;
      if((soma+ vetor[j+1].tempo)>t || j+1==p){
        meses++;
        soma= 0;
      }
    }

    //O valor da variável começa com a visitação de menor tempo
    visitas_mes= vetor[i].tempo;

    //Separa em subvetores de acordo com o valor máximo especificado em t
    if(meses>1){
      while(cont< meses){
        if((i<p) && ((visitas_mes)<= t)){
          i++;
          visitas_mes+= vetor[i].tempo;
        }else{
          visitas_mes= vetor[i].tempo;
          Planeta *aux= new Planeta[i-e];
          for(int j=0; j<i-e; j++){
            aux[j]= vetor[cursor];
            cursor++;
          }
          //RADIX e copiar no vetor principal
          radixsort(aux, i-e, c);
          for(int j=0; j<i-e; j++){
            vetor[j+e]= aux[j];
            vetor[j+e].mes= cont+1;       
          }
          cont++;
          e= cursor;
        }
      }

    }else{
      //joga o vetor inteiro no RADIX
      radixsort(vetor, p, c);
    }
    //Printa mês, nome e tempo de todos os planetas visitados
    for(j=0; j<p; j++){
      std::cout << vetor[j].mes << " " << vetor[j].nome << " " << vetor[j].tempo << std::endl;
    }

  }

  return 0;
}
