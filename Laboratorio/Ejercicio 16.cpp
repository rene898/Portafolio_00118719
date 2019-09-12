#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	cout << "Ejercicio 16" <<endl;
    int arreglo[10], suma, prom, n;

	cout << "Ingrese un numero: ";
	cin >> n;
	
	for(int i=0;i<=10;i++){
		cin >> arreglo[i];
		suma += arreglo[i];
		prom = suma/10;
	}

	cout<<"La suma de los elementos del arreglo es: "<<suma<<endl;
    cout<<"El promedio de los elementos es: "<<prom<<endl;
	system("pause");
	return 0;
}
