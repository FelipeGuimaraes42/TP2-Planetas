#include "include/mergesort.h"

void merge(Planeta *a, int e, int m, int d){
    int h, i, j, k;
    Planeta *aux= new Planeta[d-e+1];
    h= e;
    i= 0;
    j= m+1;
    while(h<= m && j<=d){
        if(a[h].tempo<= a[j].tempo){
            aux[i]= a[h];
            h++;
        }else{
            aux[i]= a[j];
            j++;
        }
        i++;
    }
    if(h>m){
        for(k=j; k<=d; k++){
            aux[i]= a[k];
            i++;
        }
    }else{
        for(k=h; k<=m; k++){
            aux[i]= a[k];
            i++;
        }
    }
    for(k= 0; k<= d-e; k++){
        a[k+e]= aux[k];
    }
    delete[] aux;
}

void mergesort(Planeta *a, int e, int d){
    int m;
    if(e<d){
        m= (d+e)/2;
        mergesort(a, e, m);
        mergesort(a, m+1, d);
        merge(a, e, m, d);
    }
}