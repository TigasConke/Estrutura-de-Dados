#include <stdio.h>
#include <stdlib.h>

struct pessoa {

    int senha;
    struct pessoa *prox;

};

typedef struct pessoa Pessoa;

Pessoa *fila;

void add(int senha){

    Pessoa *p = (Pessoa*) malloc(sizeof(Pessoa));
    p->senha = senha;
    p->prox = NULL;

    if(fila == NULL){

        fila = p;

    }

    else{

        Pessoa *filaAux = fila;

        while(filaAux->prox != NULL){

            filaAux = filaAux->prox;

        }

        filaAux->prox = p;

    }

}

void imprime(Pessoa *f){

    if(f != NULL){

        printf("\nSenha: %d\n", f->senha);
        imprime(f->prox);

    }

}

void remover(){

    if(fila == NULL){

        printf("Fila vazia!");

    }

    else{

        fila = fila->prox;
        printf("----------------------------------------------");

    }

}

int main(void){

    add(1);
    add(2);
    add(3);
    add(4);
    add(74);
    add(78);

    Pessoa *filaAux = fila;
    imprime(filaAux);

    remover();

    filaAux = fila;
    imprime(filaAux);

    remover();

    filaAux = fila;
    imprime(filaAux);

    remover();

    filaAux = fila;
    imprime(filaAux);

    remover();

    filaAux = fila;
    imprime(filaAux);

    remover();

    filaAux = fila;
    imprime(filaAux);

    return 0;

}
