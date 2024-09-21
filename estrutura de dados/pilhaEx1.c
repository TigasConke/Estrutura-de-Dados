#include<stdio.h>
#include<stdlib.h>

struct element{

    int valor;
    struct pilha *prox;

};

typedef struct element Element;

Element *topo;

void push(valor){

    Element *e = (Element*) malloc(sizeof(Element));
    e->valor = valor;
    e->prox = topo;
    topo = e;

}

int vazia(){

    if(topo == NULL){

        return 1;

    }

    else{

        return 0;

    }

}

void pop(){

    if(topo == NULL){

        printf("\nA pilha esta vazia.\n");

    }

    else{

        Element *temp = topo;
        topo = topo->prox;
        free(temp);

    }

}

void topoPilha(){

    int top = topo->valor;

    if(top == NULL){

        printf("\nA pilha esta vazia.\n");

    }

    else{

    printf("\nO elemento que esta no topo da pilha e: %d.\n", top);


    }

}

void imprime(Element *e){

    if(e != NULL){

        printf("\n%d\n", e->valor);
        imprime(e->prox);

    }

    else{

        printf("-------------------------------------");

    }

}

int main(){

    push(4);
    push(6);
    push(37);
    push(43);

    if (vazia()) {

        printf("\n1\n");

    }

    else {

        printf("\n0\n");

    }

    topoPilha();

    Element *pilhaAux = topo;
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
