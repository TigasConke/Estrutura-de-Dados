#include<stdio.h>
#include<stdlib.h>

struct ponto{

	float x;
	float y;
	struct ponto *prox;

};

typedef struct ponto Ponto;

Ponto *listaPontos;

void addInicio(float x, float y){ //adiciona um elemento ao in�cio da lista

    Ponto *p = (Ponto*) malloc(sizeof(Ponto)); //aloca dinamicamente o espa�o da lista(que ser� do tamanho da struct)
	p->x = x;
	p->y = y;
	p->prox = listaPontos;
	listaPontos = p;


}

void addFim(float x, float y){ //adiciona um elemento ao fim da lista

    Ponto *p = (Ponto*) malloc(sizeof(Ponto));
	p->x = x;
	p->y = y;
	p->prox = NULL;//por ser o �ltimo elemento da lista, o pr�ximo elemento deve ser NULL

	if(listaPontos == NULL){ //verifica se tem elementos na lista. Se n�o tiver, apenas adiciona o elemento em primeiro mesmo(que acaba sendo o �ltimo tbm)

        listaPontos = p;

	}
	else{

        Ponto *aux = listaPontos;

        while(aux->prox != NULL){ //enquanto o pr�ximo elemento da lista n�o for nulo, ele vai passando para o pr�ximo elemento

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
