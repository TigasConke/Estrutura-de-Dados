#include<stdio.h>
#include<stdlib.h>

struct ponto{

	float x;
	float y;
	struct ponto *prox;

};

typedef struct ponto Ponto;

Ponto *listaPontos;



void imprime(){

	Ponto *auxLista = listaPontos;

	while(auxLista!=NULL){ //verifica se tem algo na lista

		printf("\nPonto(%.1f, %.1f)", auxLista->x, auxLista->y);
		auxLista = auxLista->prox;

	}

}

int length = 0; //controla o tamanho da lista

void addIndex(float x, float y, int index){ //adiciona elemento no lugar desejado da lista

    Ponto *p = (Ponto*) malloc(sizeof(Ponto));
    p->x = x;
    p->y = y;

    if(index > length){ //verifica se a posição que deseja-se inserir existe

        printf("Posicao invalida!");

    }
    else{

        if(index == 0){ //caso a posição desejada seja a primeira, o antigo primeiro elemento será o próximo(segundo elemento)

            p->prox = listaPontos;
            listaPontos = p;

        }

        else{

            Ponto *aux = listaPontos;
            int i=0;

            while(i != index - 1){ // aux vai recebendo o seu prox até que i seja diferente de index - 1

                aux = aux->prox;
                i++;

            }

            p->prox = aux->prox;
            aux->prox = p;

        }

        length++; //tamanho da lista aumenta com a inserção

    }

}

void removeIndex(int index){ //remove um elemento desejado

    if(index > length || length == 0){

        printf("Posicao invalida ou lista vazia!");

    }

    else{

        if(index == 0){ //caso a posição desejada seja a primeira, o antigo primeiro elemento será o próximo(segundo elemento)

            listaPontos = listaPontos->prox;

        }

        else{

            Ponto *aux = listaPontos;
            int i = 0;

            while(i != index-1){ // aux vai recebendo o seu prox até que i seja diferente de index - 1

                aux = aux->prox;
                i++;

            }

            aux->prox = aux->prox->prox; // prox de aux recebe o prox do prox de aux

        }

        length--; //tamanho da lista diminui com a remoção
    }

}

int main(){

    addIndex(1,3,0);
    addIndex(4,6,1);
    addIndex(32,6,2);
    addIndex(4,7,3);
    addIndex(3,79,0);
    addIndex(9,4,2);
    removeIndex(2);

	imprime();

	return 0;

}

