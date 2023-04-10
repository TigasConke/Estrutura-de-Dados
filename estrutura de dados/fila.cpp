#include<iostream>

using namespace std;

const int TAM = 4;
int Fila[TAM];
int inicio = 0;
int fim = 0;
int contador = 0;

void enqueue(int valor){ //enfilera
	if(contador == TAM){ //verifica se tem espaço na fila
		cout << "Fila cheia" << endl;
		return;
	}
	contador++;
	Fila[fim] = valor;
	if(fim == TAM - 1){
		fim = 0;
	}
	else fim++;
}

void dequeue(){ //remove da fila
	if(contador == 0 ){	//verifica se a fila esta vazia
		cout << "Fila vazia" << endl;
		return;
	}
	contador--;
	if(inicio == TAM - 1){
		inicio = 0;
	}
	else inicio++;
}

void iniciofila(){ // imprime(o prof nao exige na prova) 
	if(contador == 0 ){	//verifica se a fila esta vazia
		cout << "Fila vazia" << endl;
		return;
	}
	cout << "Inicio da fila eh: " << Fila[inicio] << endl;
}
void imprime(){ // imprime(o prof nao exige na prova) 
	if(contador == 0 ){	//verifica se a fila esta vazia
		cout << "Fila vazia" << endl;
		return;
	}
	
	int i = 0;
	int j = inicio;
	
	while(i < contador){
		cout << Fila[j] << " ";
		if(j == TAM - 1){
			j = 0;
		}
		else j++;
		i++;
	}
}




int main(){
	enqueue(10);
	enqueue(20);
	enqueue(30);
	dequeue();
	imprime();
}
