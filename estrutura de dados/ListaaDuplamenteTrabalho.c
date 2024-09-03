#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da lista duplamente encadeada
typedef struct no {

    int valor;
    struct no* anterior;
    struct no* proximo;

} no;

// Estrutura da lista duplamente encadeada
typedef struct {

    no* inicio;
    no* fim;

} ListaDuplamenteEncadeada;

// Função para inicializar a lista
void inicializaLista(ListaDuplamenteEncadeada* lista) {

    lista->inicio = NULL;
    lista->fim = NULL;

}

// Função para criar um novo nó
no* criadorNo(int valor) {

    no* novoNo = (no*)malloc(sizeof(no));

    if (!novoNo) {

        printf("Erro de alocacao de memoria.\n");
        exit(1);

    }

    novoNo->valor = valor;
    novoNo->anterior = NULL;
    novoNo->proximo = NULL;
    return novoNo;

}

// Função para inserir um valor na lista
void insereLista(ListaDuplamenteEncadeada* lista, int valor, int posicao) {

    no* novoNo = criadorNo(valor);

    if (posicao == 0) { // Inserir no início

        if (lista->inicio == NULL) { // Lista vazia

            lista->inicio = novoNo;
            lista->fim = novoNo;

        } else {

            novoNo->proximo = lista->inicio;
            lista->inicio->anterior = novoNo;
            lista->inicio = novoNo;

        }
    } else if (posicao == 1) { // Inserir no final

        if (lista->fim == NULL) { // Lista vazia

            lista->inicio = novoNo;
            lista->fim = novoNo;

        } else {

            novoNo->anterior = lista->fim;
            lista->fim->proximo = novoNo;
            lista->fim = novoNo;

        }

    } else {

        printf("Posicao invalida. Use 0 para o inicio ou 1 para o final.\n");
        free(novoNo);

    }
}

// Função para remover um valor específico da lista
void removeValor(ListaDuplamenteEncadeada* lista, int valor) {

    if (lista->inicio == NULL) { // Lista vazia

        printf("Lista vazia\n");
        return;

    }

    no* atual = lista->inicio;
    while (atual != NULL && atual->valor != valor) {

        atual = atual->proximo;

    }

    if (atual == NULL) { // Valor não encontrado

        printf("Valor %d nao encontrado na lista.\n", valor);
        return;

    }

    if (atual->anterior != NULL) {

        atual->anterior->proximo = atual->proximo;

    } else {

        lista->inicio = atual->proximo;

    }

    if (atual->proximo != NULL) {

        atual->proximo->anterior = atual->anterior;

    } else {

        lista->fim = atual->anterior;

    }

    free(atual);
    atual = NULL;
    printf("Valor %d removido da lista.\n", valor);

}

// Função para imprimir o conteúdo da lista
void imprime(ListaDuplamenteEncadeada* lista) {

    if (lista->inicio == NULL) {
        printf("Lista vazia\n");
        return;

    }

    no* atual = lista->inicio;
    printf("Conteudo da lista: ");

    while (atual != NULL) {

        printf("%d ", atual->valor);
        atual = atual->proximo;

    }
    printf("\n");
}

// Função principal para testar as operações
int main() {

    ListaDuplamenteEncadeada lista;
    inicializaLista(&lista);

    insereLista(&lista, 10, 0); // Inserir 10 no início
    insereLista(&lista, 20, 1); // Inserir 20 no final
    insereLista(&lista, 30, 1); // Inserir 30 no final
    imprime(&lista);

    removeValor(&lista, 20); // Remover o valor 20
    imprime(&lista);

    removeValor(&lista, 40); // Tentar remover um valor inexistente
    imprime(&lista);

    return 0;

}
