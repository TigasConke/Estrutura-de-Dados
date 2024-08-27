#include<stdio.h>
#include<stdlib.h>

struct letra{

    char let;
    struct letra *prox;

};

typedef struct letra Letra;

Letra *listaLetra;

void add(char let){

    Letra *l = (Letra*) malloc(sizeof(Letra));
    l->let = let;
    l->prox = listaLetra;
    listaLetra = l;

}

void imprime(){

    Letra *auxLista = listaLetra;

    while(auxLista!=NULL){

        printf("%c\n", auxLista->let);
        auxLista = auxLista->prox;

    }

}

int main(){

    add('a');
    add('b');
    add('c');
    imprime();

    return 0;

}
