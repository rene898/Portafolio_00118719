#include <cstdlib>
#include <iostream>
#include<stdio.h>

using namespace std;

int main()
{

	int i,j, aux, a[6];
  for(i = 0; i < 6; i++){
    printf("Ingresa un numero: ");
    scanf("%d", &a[i]);
  } //fin for

  for(i = 0; i < 6; i++){
    for(j = 0; j < 6; j++){
        if(a[j] > a[j + 1]){
            aux = a[j];
            a[j] = a[j + 1];
            a[j + 1] = aux;
        }//fin if
    }//fin for
  }//fin for
  printf("La mediana es: %d\n", a[2]);

	system("pause");
	return 0;
}
