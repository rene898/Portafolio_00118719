
#include <iostream>

using namespace std;
long digitos(long num, long cont){
    if (num>0){
    return digitos(num/10, cont+1);
} 
    return cont;
}

int main() {

    long n;
    cout << "Ingrese un numero: ";
    cin >>n;
    cout << "El numero tiene: " <<digitos(n, 0)<<"digitos"<<endl;
    return 0;
}

