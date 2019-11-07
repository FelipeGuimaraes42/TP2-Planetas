#include <iostream>

#include "include/planeta.h"

int separa_meses(Planeta *a, int p,int t){
    int soma, meses;
    soma= meses= 0;
    for(int j=0; j<p; j++){
      soma+= a[j].tempo;
      if((soma+ a[j+1].tempo)>t || j+1==p){
        meses++;
        soma= 0;
      }
    }
    return meses;
}

void le_planetas(Planeta *vetor, int p){
    for(int j=0; j<p; j++){
      std::cin >> vetor[j].tempo >> vetor[j].nome;
    }
}

void printa_planetas(Planeta * vetor, int p){
    for(int j=0; j<p; j++){
      std::cout << vetor[j].mes << " " << vetor[j].nome << " " << vetor[j].tempo << std::endl;
    }
}