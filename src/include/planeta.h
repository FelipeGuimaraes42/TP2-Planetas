#ifndef PLANETA_TP2
#define PLANETA_TP2

#include <string>

struct Planeta{
    int tempo;
    int mes= 1;
    std::string nome;
};

int separa_meses(Planeta *, int, int);
void le_planetas(Planeta *, int);
void printa_planetas(Planeta *, int);

#endif