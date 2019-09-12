#include <cstdlib>
#include <iostream>

using namespace std;
int recursion2 (int a, int b){
	if (b == a){
		//cout << b << endl;
	}
	else {
		cout << b<< endl;
		recursion2(a, b+1);
	}
}
int recursion (int a){
	if (a <= 1){
		cout << a << endl;
	}
	else {
		cout << a << endl;
		recursion(a-1);
	}
}

int main()
{
	cout << "Ejercicio 8 " << endl;
	int a;
	int b = 1;
	
	cout << "Digite un entero: ";
	cin >> a;
	
	recursion2(a,b);
	recursion(a);
	
	system("pause");
	return 0;
}
