#include <cstdlib>
#include <iostream>
#include <stdlib.h>

using namespace std;

/*---------  Estructura del arbol  -------*/
typedef struct nodo{
     int nro;
     struct nodo *izq, *der;
}*AB;

int numNodos = 0; // nummero de nodos del arbol ABB
int numK = 0, k;     //  nodos menores que un numero k ingresado


/* ---------- Estructura de la cola ---------*/
struct nodoCola{
    AB ptr;
    struct nodoCola *sgte;
};
struct cola{
    struct nodoCola *delante;
    struct nodoCola *atras;
};

void inicializaCola(struct cola &q)
{
    q.delante = NULL;
    q.atras = NULL;
}

void encola(struct cola &q, AB n)
{
     struct nodoCola *p;
     p = new(struct nodoCola);
     p->ptr = n;
     p->sgte = NULL;
     if(q.delante==NULL)
         q.delante = p;
     else
         (q.atras)->sgte = p;
     q.atras = p;
}

AB desencola(struct cola &q)
{
    struct nodoCola *p;
    p = q.delante;
    AB n = p->ptr;
    q.delante = (q.delante)->sgte;
    delete(p);
    return n;
}

AB crearNodo(int x)
{
     AB nuevoNodo = new(struct nodo);
     nuevoNodo->nro = x;
     nuevoNodo->izq = NULL;
     nuevoNodo->der = NULL;

     return nuevoNodo;
}
void insertar(AB &arbol, int x)
{
     if(arbol==NULL)
     {
           arbol = crearNodo(x);
           cout<<"\n\t  Insertado..!"<<endl<<endl;
     }
     else if(x < arbol->nro)
          insertar(arbol->izq, x);
     else if(x > arbol->nro)
          insertar(arbol->der, x);
}
void verArbol(AB arbol, int n)
{
     if(arbol==NULL)
          return;
     verArbol(arbol->der, n+1);

     for(int i=0; i<=n; i++)
         cout<<"   ";

     numNodos;
     cout<< arbol->nro <<endl;

     verArbol(arbol->izq, n+1);
}


AB unirAB(AB izq, AB der)
{
    if(izq==NULL) return der;
    if(der==NULL) return izq;

    AB centro = unirAB(izq->der, der->izq);
    izq->der = centro;
    der->izq = izq;
    return der;
}

void elimina(AB &arbol, int x)
{
     if(arbol==NULL) return;

     if(x<arbol->nro)
         elimina(arbol->izq, x);
     else if(x>arbol->nro)
         elimina(arbol->der, x);

     else
     {
         AB p = arbol;
         arbol = unirAB(arbol->izq, arbol->der);
         delete p;
     }
}

int alturaAB(AB arbol)
{
    int AltIzq, AltDer;

    if(arbol==NULL)
        return -1;
    else
    {
        AltIzq = alturaAB(arbol->izq);
        AltDer = alturaAB(arbol->der);

        if(AltIzq=AltDer)
            return AltIzq+1;
        else
            return AltDer+1;
    }
}
int cantidadAB(AB arbol)
{
    int CantIzq, CantDer;

    if(arbol==NULL)
        return -1;
    else
    {
        CantIzq = cantidadAB(arbol->izq);
        CantDer = cantidadAB(arbol->der);

        if(CantIzq=CantDer)
            return CantIzq+1;
        else
            return CantDer+1;
    }
}






void menu()
{
     //system("cls");
     cout << "\n\t\t  ..[ ARBOL BINARIO ]..  \n\n";
     cout << "\t [1]  Insertar elemento                  \n";
     cout << "\t [2]  Mostrar arbol                  \n";
     cout << "\t [3]  Eliminar elemento                  \n";
     cout << "\t [4]  Altura del arbol                   \n";
     cout << "\t [5]  Cantidad de nodos                   \n";
     cout << "\t [6]  Suma de nodos                       \n";
     cout << "\t [7]  Salir                              \n";

     cout << "\n\t Ingrese opcion : ";
}



int main()
{
    AB arbol = NULL;
    int x;
    int op;


    //system("color f9");   // poner color a la consola
    do
    {
          menu();  cin>> op;
          cout << endl;

          switch(op)
          {
               case 1:
                    cout << " Ingrese valor : ";  cin>> x;
                    insertar( arbol, x);
                    break;

			   case 2:
                    verArbol(arbol, 0);
                    break;
               
               case 3:
                    cout<<" Valor a eliminar: "; cin>> x;
                    elimina(arbol, x);
                    cout << "\n\tEliminado..!";
                    break;

              

               case 4:
                    int h;
                    h = alturaAB(arbol);
                    cout << " La cantidad de altura es : "<< h << endl;
                    break;


               case 5:
                    verArbol(arbol, 0);
                    cout << "\n El numero de nodos es : ";
                    cout << numNodos;
                    break;

			   case 6:
                    int c;
                    c = cantidadAB(arbol);
                    cout << " La cantidad de nodos es : "<< c << endl;
                    break;

               case 7:
                    exit(0);
          }

          cout<<"\n\n\n";
          //system("pause");  // hacer pausa y presionar una tecla para continuar
    }while(op!=5);


system("pause");
	return 0;
}
