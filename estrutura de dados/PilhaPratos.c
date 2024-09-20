#include <stdio.h>
#include <stdlib.h>

struct prato {

    char cor;
    struct prato *prox;

};

typedef struct prato Prato;

Prato *topo;

void push(char cor){

    Prato *p = (Prato*) malloc(sizeof(Prato));
    p->cor = cor;
    p->prox = topo;
    topo = p;

}

void pop(){

    if(topo == NULL){

        printf("\nPilha vazia\n");

    }

    else{

        topo = topo->prox;

    }

}

void imprime(Prato *p){

    if(p != NULL){

        printf("\nCor do prato: %c \n", p->cor);
        imprime(p->prox);

    }

    else{

        printf("-------------------------------------");

    }

}

int main(void){

    push('b');
    push('y');
    push('r');
    push('g');

    Prato *pilhaAux = topo;
    imprime(pilhaAux);

    pop();
    pilhaAux = topo;
    imprime(pilhaAux);

    pop();
    pilhaAux = topo;
    imprime(pilhaAux);

    pop();
    pilhaAux = topo;
    imprime(pilhaAux);

    pop();
    pilhaAux = topo;
    imprime(pilhaAux);

    pop();
    pilhaAux = topo;
    imprime(pilhaAux);

    return 0;

}
