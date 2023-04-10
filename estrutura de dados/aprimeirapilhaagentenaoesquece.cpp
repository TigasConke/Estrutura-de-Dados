#include<iostream>
using namespace std;
const int TAM = 8;

int pilha[TAM];
int topo = -1; // 0 é o topo, por isso -1

void push(int valor){
	if(TAM- 1 == topo){
		cout << "Pilha cheia\n"; //equivale ao printf e scanf
		return;
	}
	topo++; // quando adiciona um numero na pilha, o topo aumenta em 1
	pilha[topo]=valor;
	cout << "Sucesso!\n";
}

void pop(){
	if(topo == -1){
		cout << "Pilha vazia\n";
		return;
	}
	topo--;
	cout << "Sucesso!\n";
}

void topoPilha(){
	if(topo == -1){
		cout << "Pilha vazia\n";
		return;
	}
	cout << "Topo eh " << pilha[topo] << "\n";
	}
	
	void imprime(){
		if(topo == -1){
			cout << "Pilha vazia\n";
			return;
		}
		for(int i = 0; i <= topo; i++){
			cout << pilha[i] << " "; 
		}
}

int main(){
	push(10);
	push(15);
	push(30);
	topoPilha();
	pop();
	imprime();
	
}
