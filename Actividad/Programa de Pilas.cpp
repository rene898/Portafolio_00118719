#include <iostream>
#include <stack>
using namespace std;
struct Nodo{
	int nota;
	Nodo *siguiente;
};

float agregarPila(Nodo *&, int);
float sacarPila(Nodo *&,int&);
int main() {
	Nodo *pila = NULL;
	int nota;
	cout <<"Actividad 9 \n";
	
	
	cout << "Digite un numero: ";
	cin >> nota;
	agregarPila(pila,nota);
	
	cout << "Digite un numero: ";
	cin >> nota;
	agregarPila(pila,nota);
	
	cout << "Sacando los elementos de la pila ";
	
	while(pila != NULL){
		sacarPila(pila, nota);
		if(pila != NULL){
			cout << nota << ",";
		}
		else{
			cout << nota << ".";
		}
	}
	
	return 0;
}
float agregarPila(Nodo *&pila, int a){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo -> nota = a;
	nuevo_nodo -> siguiente = pila;
	pila = nuevo_nodo;
	
	cout << "Elemento: " << a << "\nha sido agregado a la Pila correctamente" << endl; 
	
}
float sacarPila(Nodo *&pila,int &a){
	Nodo *aux = pila;
	a = aux-> nota;
	pila = aux->siguiente;
	delete aux;
}
