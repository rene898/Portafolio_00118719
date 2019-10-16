#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

enum generos{masculino,femenino};

struct TPersonas{
    int dui;//isbn
    string nombre;//titulo
    string apellido;
    int edad;//autor
    int telefono;
    string correo;
    generos genero;
};
typedef struct TPersonas Persona;

Persona solicitarPersona(){
     Persona p;

    //---Solicitar dui, nombre y Edad---
    cout << "DUI: "; cin >> p.dui;
    cin.ignore();//Limpiando el buffer
    cout << "Nombre: "; getline(cin, p.nombre);
    cout << "Apellido: "; getline(cin, p.apellido);
    cout << "Edad: "; cin >> p.edad;
    cout << "Telefono: "; cin >> p.telefono;
    cout << "Correo: "; getline(cin, p.correo);

    //---Solicitar genero de la Persona---
    bool continuar = true;
    do{
        char opcion = 0;
        cout << "Genero (m-masculino|f-femenino): ";
        cin >> opcion;
        switch(opcion){
            case 'm': p.genero = masculino;   continuar = false;
            break;
            case 'f': p.genero = femenino;   continuar = false;
            break;
        }
    }while(continuar);
    //---Devolver persona ya poblado---
    return p;
}

void mostrarPersona(Persona p){
    cout << "DUI: " << p.dui << endl;
    cout << "Nombre: " << p.nombre << endl;
    cout << "Apellido: " << p.apellido << endl;
    cout << "Edad: " << p.edad << endl;
    cout << "Telefono: " << p.telefono << endl;
    cout << "Correo: " << p.correo << endl;

    cout << "Genero: ";
    switch(p.genero){
        case masculino: cout << "Masculino" << endl;
        break;
        case femenino: cout << "Femenino" << endl;
        break;
    }

}

struct TNodo{
    Persona dato;
    struct TNodo *sig;
};
typedef struct TNodo Nodo;
Nodo *pInicio;

void insertarInicio(Persona p) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = pInicio;

    pInicio = nuevo;
}

void insertarFinal(Persona p) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = NULL;

    if (pInicio == NULL) {
        pInicio = nuevo;
    } else {
        Nodo *p = pInicio;
        Nodo *q = NULL;
        while (p != NULL) {
            q = p;
            p = p->sig;
        }
        q->sig = nuevo;
    }
}

void insertarDespuesDe(Persona p) {
    int undui = 0;
    cout << "dui de la persona: ";
    cin >> undui;

    Nodo *s = pInicio;

    while(s != NULL && (s->dato).dui != undui)
        s = s->sig;
    if(s == NULL){
        cout << "La persona no existe" << endl;
        return;
    }

    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = s->sig;

    s->sig = nuevo;
    cout << "Persona agregada con exito" << endl;
}

void insertarAntesDe(Persona p) {
    int undui = 0;
    cout << "dui de la persona: ";
    cin >> undui;

    Nodo *s = pInicio, *q = NULL;

    while(s != NULL && (s->dato).dui != undui){
        q = s;
        s = s->sig;
    }
    if(s == NULL){
        cout << "Persona no existe" << endl;
        return;
    }

    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = s;

    if(q == NULL)
        pInicio = nuevo;
    else
        q->sig = nuevo;
    cout << "Persona agregada con exito" << endl;
}

void agregarPersona(){
    Persona p = solicitarPersona();
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\t1) Al principio\n\t2) Al final"
            << "\n\t3) Despues de\n\t4) Antes de"
            << "\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: insertarInicio(p);  continuar = false;
            break;
            case 2: insertarFinal(p);   continuar = false;
            break;
            case 3: insertarDespuesDe(p);   continuar = false;
            break;
            case 4: insertarAntesDe(p);   continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);
}

void mostrarLista() {
    Nodo *s = pInicio;

    while (s != NULL) {
        mostrarPersona(s->dato);
        s = s->sig;
    }
}

void eliminarPersona(){
    int undui = 0;
    cout << "dui de la persona a eliminar: ";
    cin >> undui;

    Nodo *p = pInicio, *q = NULL;

    while(p != NULL && (p->dato).dui != undui){
        q = p;
        p = p->sig;
    }
    if(p == NULL){
        cout << "Persona a eliminar no existe" << endl;
        return;
    }
    if(q == NULL)
        pInicio = p->sig;
    else
        q->sig = p->sig;
    delete(p);
    cout << "Persona eliminada con exito!" << endl;
}

bool buscarPersona() {
    int undui = 0;
    cout << "dui de la persona a buscar: ";
    cin >> undui;

    Nodo *s = pInicio;

    while(s != NULL && (s->dato).dui != undui)
        s = s->sig;

    //Si s!=NULL entonces la persona SI se encuentra
    //Si s==NULL entonces la persona NO se encuentra
    return (s != NULL);
}

int main(){
    cout << "Inicializando..." << endl;
    pInicio = NULL;

    bool continuar = true;
    do{
        int opcion = 0;
        cout << "Menu: \n\t1) Agregar Persona\n\t2) Ver Personas"
            << "\n\t3) Eliminar Persona\n\t4) Buscar Persona"
            << "\n\t5) Actualizar Datos\n\t6) Salir\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: cout << "Agregando..." << endl;
                agregarPersona();
            break;
            case 2: cout << "Listando..." << endl;
                mostrarLista();
            break;
            case 3: cout << "Eliminando..." << endl;
                eliminarPersona();
            break;
            case 4: cout << "Buscando..." << endl;
                if(buscarPersona())
                    cout << "La persona SI se encuentra registrada" << endl;
                else
                    cout << "La persona NO se encuentra registrada" << endl;
                //cout << "La persona" << (buscarPersona() ? "SI" : "NO") << " se encuentra" << endl;
            break;
            case 6: continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);

    system("pause");
	return 0;
}
	


