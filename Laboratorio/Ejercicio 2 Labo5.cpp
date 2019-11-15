#include <cstdlib>
#include <iostream>
#include <conio.h>

using namespace std;

	int y,r,n,e,h;
	int num,positivo,negativo,cero,cant, i;
    int numero, pares, impares;


int main(){
    cout << "\n\t\t  ..[ Cantidad de pares e impares ]..  \n\n";

	cout << "Ingrese la cantidad: ";
	cin >> h;
	cout << "\nIngresos los numeros: \n";
	for(y=0;y<h;y++){

		cin >> e;
		if(e%2==0){
			    n=n+1;

			}else{
				r=r+1;
			}
  }


	cout << "Son pares: \n" << n << endl;
	cout << "Son impares: \n" << r << endl;
	
	cout << "\n  ..[ Cantidad de positivos, negativos o ceros ]..  \n\n";
	
    positivo=0;
    negativo=0;
    cero=0;
    cout<<"\n\nIntroduzca la cantidad: ";
    cin>>cant;
    for(i=1; i<=cant;i++)
    {
        cout<<"Ingrese un numero entero: ";
        cin>>num;
        if (num>0)
        {
            positivo+=+1;
        }
        else
        if(num<0)
        {
            negativo+=+1;
        }
        else
        cero+=+1;
    }

    cout<<"\nLa Cantidad de Positivos Son:"<<positivo<<endl;
    cout<<"\nLa Cantidad de Negativos Son:"<<negativo<<endl;
    cout<<"\nLa Cantidad de Ceros Son:"<<cero<<endl;
    
    cout << "\n  ..[ Suma de pares e impares ]..  \n\n";

	cout <<"\n\n   Introduzca un numero entero [0=Fin]: ";
    cin >> numero;

    pares = 0;
    impares = 0;

    while ( numero != 0 )
    {
        if ( numero % 2 == 0 )
            pares += numero;
        else
            impares += numero;

        cout << "\n   Introduzca un numero entero [0=Fin]: ";
        cin >> numero;
    }

    cout << "\n   La suma de los pares es: " << pares << endl;
    cout << "\n   La suma de los impares es: " << impares << endl;
    
system("pause");
	return 0;
}

