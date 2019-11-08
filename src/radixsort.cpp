#include "include/radixsort.h"

#define LETRAS 26 //Número de letras no alfabeto
#define INICIO_ASCII 97 //Valor da letra a na tabela ASCII

void countingsort(Planeta *a, int tam, int k){
    Planeta *b= new Planeta[tam];
    int *c= new int[LETRAS];

    for(int i=0; i<LETRAS; i++){
        c[i]= 0;
    }

    for(int j=0; j<tam; j++){
        c[(int)(a[j].nome[k]- INICIO_ASCII)]++;
    }

    for(int f=1; f<LETRAS; f++){
        c[f]+= c[f-1];
    }

    for(int r=tam-1; r>=0; r--){
        b[c[(int)(a[r].nome[k]- INICIO_ASCII)]- 1]= a[r];
        c[(int)(a[r].nome[k]- INICIO_ASCII)]--;
    }

    for(int l=0; l<tam; l++){
        a[l]= b[l];
    }

    delete[] b;
    delete[] c;
}

void radixsort(Planeta *a, int p, int c){
    for(int i= c; i>0; i--)
        countingsort(a, p, i-1);
}

void radix_mes(Planeta *vetor, int p, int t, int c){
    int cursor, e, i, cont;
    i= e= cursor= cont= 0;
    //Faz o cálculo total dos meses de visitação
    int meses= separa_meses(vetor, p, t);
    //O valor da variável começa com a visitação de menor tempo
    int visitas_mes= vetor[0].tempo;
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
          radixsort(aux, i-e, c); //Ordena alfabeticamente
          //Copia os valores ordenados no vetor principal
          for(int j=0; j<i-e; j++){
            vetor[j+e]= aux[j];
            vetor[j+e].mes= cont+1;       
          }
          delete[] aux;
          cont++;
          e= cursor;
        }
      }
    }else
      radixsort(vetor, p, c); //joga o vetor inteiro no RADIX
}