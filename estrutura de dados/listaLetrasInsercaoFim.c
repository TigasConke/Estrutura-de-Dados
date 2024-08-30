#include<stdio.h>
#include<stdlib.h>

struct letra{

    char let;
    struct letra *prox;

};

typedef struct letra Letra;

Letra *listaLetra;

void addInicio(char let){

    Letra *l = (Letra*) malloc(sizeof(Letra));
    l->let = let;
    l->prox = listaLetra;
    listaLetra = l;

}

void addFim(char let){

    Letra *l = (Letra*) malloc(sizeof(Letra));
    l->let = let;
    l->prox = NULL;

    if(listaLetra == NULL){

        listaLetra = l;

    }

    else{

        Letra *aux = listaLetra;

        while(aux->prox != NULL){

            aux = aux->prox;

        }

        aux->prox = l;

    }

}

void imprime(){

    Letra *auxLista = listaLetra;

    while(auxLista!=NULL){

        printf("%c\n", auxLista->let);
        auxLista = auxLista->prox;

    }

}

int main(){

    addInicio('c');
    addInicio('b');
    addInicio('a');
    addFim('d');
    addFim('e');

    imprime();

    return 0;

}

