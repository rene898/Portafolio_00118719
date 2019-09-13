

#include <iostream>

using namespace std;
int recu(int x,  int b){
    if(x==b){
        return x;
}
    else if(x<b){
    return recu(x,b-x);
    
}
else {
       return recu(x-b,b);
} 
}

int main(){
    cout <<"Ejercicio 1 Labo2 \n";
   int x,b;
    
    cout << "Ingrese un numero:";
    cin>>x;
    
    cout << "Ingrese un numero:";
    cin>>b;
    
    cout << "El mcd es:"<<recu(x,b) << endl;
    

    return 0;
}

