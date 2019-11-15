#include <iostream>
#include <math.h>

	using namespace std;
	
	struct nodo{
	int info;
	struct nodo *izq;
	struct nodo *der;
	};
	typedef struct nodo Nodo;
	typedef struct nodo *Arbol;
	
	
	
	Arbol crearArbol(int x){
	Arbol p = new Nodo;
	p->info = x;
	p->izq = NULL;
	p->der = NULL;
	return p;
	}
	
	void asignarIzq(Arbol a, int unDato){
	if(a == NULL)
	cout << "Error: arbol vacio" << endl;
	else if(a->izq != NULL)
	cout << "Error: subarbol IZQ ya existe" << endl;
	else
	a->izq = crearArbol(unDato);
	}
	
	void asignarDer(Arbol a, int unDato){
	if(a == NULL)
	cout << "Error: arbol vacio" << endl;
	else if(a->der != NULL)
	cout << "Error: subarbol DER ya existe" << endl;
	else
	a->der = crearArbol(unDato);
	}
	
	void agregarNodo(Arbol a){
	
	int numero = 0;
	cout << "Numero a agregar: ";
	cin >> numero;
	
	Arbol p = a;
	
	while(true){
	if(numero == p->info){
	cout << "Error: " << numero << " ya existe" << endl;
	return;
	}
	else if(numero < p->info){
	if(p->izq == NULL)
	break;
	else
	p = p->izq;
	}
	else{
	if(p->der == NULL)
	break;
	else
	p = p->der;
	}
	}
	
	
	if(numero < p->info)
	asignarIzq(p, numero);
	else
	asignarDer(p, numero);
	}
	
	
	void preorden(Arbol a){
	if(a != NULL){
	cout << " " << a->info;
	preorden(a->izq);
	preorden(a->der);
	}
	}
	void inorden(Arbol a){
	if(a != NULL){
	inorden(a->izq);
	cout << " " << a->info;
	inorden(a->der);
	}
	
	}
	void postorden(Arbol a){
	if(a != NULL){
	postorden(a->izq);
	postorden(a->der);
	cout << " " << a->info;
	}
	}
	
	void recorrerArbol(Arbol a){
	cout << "Recorrido PRE orden:"; preorden(a); cout << endl;
	cout << "Recorrido IN orden:"; inorden(a); cout << endl;
	cout << "Recorrido POST orden:"; postorden(a); cout << endl;
	}
	
	struct TNodo{
	int dato;
	struct TNodo *sig;
	};
	typedef struct TNodo nodolista;
	nodolista *pInicio;
	
	int Buscar(Arbol a, int dat) {
	Arbol actual = a;
	
	while(actual!=NULL) {
	if(dat == actual->info) return actual->info;
	else if(dat < actual->info) actual = actual->izq;
	else if(dat > actual->info) actual = actual->der;
	}
	return false;
	}
	
	
	void insertarInicio(int num) {
	nodolista *nuevo = new nodolista;
	nuevo->dato = num;
	nuevo->sig = pInicio;
	
	pInicio = nuevo;
	}
	
	
	
	
	void mostrarLista() {
	nodolista *s = pInicio;
	
	while (s != NULL) {
	cout << (s->dato) << endl;
	s = s->sig;
	}
	}
	
	int main(){
	int variable = 5;
	
	Arbol arbol = crearArbol(variable);
	
	bool continuar = true;
	do{
	int opcion = 0;
	cout << "\n-----> Menu <------: \n\t1) Agregar datos al arbol, su raiz es 5\n\t2) Recorrer"
	<< "\n\t3) Definir Arbol\n\tOpcion elegida: ";
	cin >> opcion;
	switch(opcion){
	case 1: agregarNodo(arbol);
	cout<<"Al terminar de agregar datos seleccione la opcion 3."<<endl;
	break;
	case 2: recorrerArbol(arbol);
	break;
	case 3: continuar = false;
	break;
	default: cout << "Opcion erronea!" << endl;
	break;
	}
	}while(continuar);
	
	int n,k;
	cout<<"Puedes empezar a agregar numeros para comparar con el arbol"<<endl;
	cout<<"Para detenerte presiona 0"<<endl;
	bool seguir=true;
	do{
	cin>>n;
	k= Buscar(arbol,n);
	if (n==0){
	seguir=false;
	}
	else if(n==k){
	
	insertarInicio(n); }
	
	
	}while(seguir);
	
	cout<<"Los numeros encontrados que coinciden con el arbol fueron"<<endl;
	
	mostrarLista();
	
	return 0;
	) 

}