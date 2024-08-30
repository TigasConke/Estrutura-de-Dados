#include<stdio.h>
#include<stdlib.h>

struct ponto{

	float x;
	float y;
	struct ponto *prox;

};

typedef struct ponto Ponto;

Ponto *listaPontos;

void addInicio(float x, float y){ //adiciona um elemento ao início da lista

    Ponto *p = (Ponto*) malloc(sizeof(Ponto)); //aloca dinamicamente o espaço da lista(que será do tamanho da struct)
	p->x = x;
	p->y = y;
	p->prox = listaPontos;
	listaPontos = p;


}

void addFim(float x, float y){ //adiciona um elemento ao fim da lista

    Ponto *p = (Ponto*) malloc(sizeof(Ponto));
	p->x = x;
	p->y = y;
	p->prox = NULL;//por ser o último elemento da lista, o próximo elemento deve ser NULL

	if(listaPontos == NULL){ //verifica se tem elementos na lista. Se não tiver, apenas adiciona o elemento em primeiro mesmo(que acaba sendo o último tbm)

        listaPontos = p;

	}
	else{

        Ponto *aux = listaPontos;

        while(aux->prox != NULL){ //enquanto o próximo elemento da lista não for nulo, ele vai passando para o próximo elemento

            aux = aux->prox;

        }

        aux->prox = p;

	}

}

void imprime(){

	Ponto *auxLista = listaPontos;

	while(auxLista!=NULL){ //verifica se tem algo na lista

		printf("\nPonto(%.1f, %.1f)", auxLista->x, auxLista->y);
		auxLista = auxLista->prox;

	}

}

int main(){

	addInicio(1,5);
	addInicio(2,7);
	addInicio(5,3);
	addInicio(9,1);
	addFim(6,9);
	addFim(89, 10);

	imprime();

	return 0;

}
