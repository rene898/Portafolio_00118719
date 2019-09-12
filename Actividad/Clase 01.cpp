#include <cstdlib>
#include <iostream>

using namespace std;

void calculos(int num, int *doble, int *triple){
	*doble = 2 * num;
	*triple = 3 * num;

}

int main()
{
	int numero = 4, doble = 0, triple = 0;
	
	calculos(numero, &doble, &triple);
	
	cout<< "Valor:" <<numero<<endl;
	cout<< "Direccion:" <<&numero<<endl;
	
	cout << "El doble de 4 es " << doble << endl;
	cout << "El triple de 4 es " << triple << endl;
	
	int *puntero1 = &numero;
    cout<<"puntero1:"<<puntero1<<endl;
    cout<<"(*puntero1):"<<(*puntero1)<<endl;
	cout<<"&puntero1:"<<&puntero1<<endl;
	int *puntero2 = &doble;
	cout<<"puntero2:"<<puntero2<<endl;
    cout<<"(*puntero2):"<<(*puntero2)<<endl;
	cout<<"&puntero2:"<<&puntero2<<endl;
	int *puntero3 = &triple;
    cout<<"puntero3:"<<puntero3<<endl;
    cout<<"(*puntero3):"<<(*puntero3)<<endl;
	cout<<"&puntero3:"<<&puntero3<<endl;
    


























	/*
	int numero = 5;
	
	cout<< "Valor:" <<numero<<endl;
	cout<< "Direccion:" <<&numero<<endl;

	int *puntero = &numero;

	cout<<"puntero:"<<puntero<<endl;
    cout<<"(*puntero):"<<(*puntero)<<endl;
	cout<<"&puntero:"<<&puntero<<endl;
	
	*puntero = 10;
	
	cout<<"(*puntero):"<<(*puntero)<<endl;
	cout<< "Valor:" <<numero<<endl;
	*/
	
	system("pause");
	return 0;
}
