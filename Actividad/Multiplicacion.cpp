#include <cstdlib>
#include <iostream>

using namespace std;

int mult(int a,int b);

int main()
{
    	int a, b, producto;
	cout << "Introduce dos enteros a y b: \n";

	cin >> a >> b;

	producto = mult(a,b);

	cout << "El producto de ambos es: " << producto << endl << endl;

	system("pause");
	return 0;
}

int mult(int a,int b){

if (b==0)
return 0;
else  return (a+mult(a,b-1));
}
