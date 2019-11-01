#include "planeta.h"

void particao(int esq, int dir, int *i, int *j, Planeta *A){
  Planeta a, b;
  *i= esq;
  *j= dir;
  b= a= A[(*i+*j)/2]; //Obtém o pivô
  do{
    while(a.tempo> A[*i].tempo)
      (*i)++;
    while(b.tempo< A[*j].tempo)
      (*j)--;
    if(*i<= *j){
      b= A[*i];
      A[*i]= A[*j];
      A[*j]= b;
      (*i)++;
      (*j)--;
    }
  }while(*i<= *j);
}

void ordena(int esq, int dir, Planeta *A){
  int i, j;
  particao(esq, dir, &i, &j, A);
  if(esq< j)
    ordena(esq, j, A);
  if(i<dir)
    ordena(i, dir, A);
}

void quicksort(Planeta *A, int n){
  ordena(0, n-1, A);
}