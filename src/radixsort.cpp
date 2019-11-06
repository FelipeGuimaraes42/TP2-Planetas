#include "radixsort.h"

#define LETRAS 26
#define INICIO_ASCII 97

void countingsort(Planeta *a, int tam, int k){
    Planeta *b= NULL;
    int *c= NULL;
    b = new Planeta[tam];
    c= new int[LETRAS];

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

/*
#include "radixsort.h"

void countingsort(Planeta *a, int tam, int comp, int k){
    Planeta *b= NULL;
    int *c= NULL;
    b = new Planeta[tam];
    c= new int[257];

    for(int i=0; i<257; i++){
        c[i]= 0;
    }

    for(int j=0; j<tam; j++){
        c[k< comp ? (int)(unsigned char)a[j].nome[k]+1 : 0]++;
    }

    for(int f=1; f<257; f++){
        c[f]+= c[f-1];
    }

    for(int r=tam-1; r>=0; r--){
        b[c[k< comp ? (int)(unsigned char)a[r].nome[k]+1: 0]- 1]= a[r];
        c[k < comp ? (int)(unsigned char)a[r].nome[k]+1: 0]--;
    }

    for(int l=0; l<tam; l++){
        a[l]= b[l];
    }

    delete[] b;
    delete[] c;
}

void radixsort(Planeta *a, int p, int c){
    for(int i= c; i>0; i--)
        countingsort(a, p, c, i-1);
}
*/