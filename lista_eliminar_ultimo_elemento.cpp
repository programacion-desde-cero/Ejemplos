//Ejemplo correspondiente al video https://youtu.be/4bpSqQwqOQ4
#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo* siguiente;
};

Nodo* insertar(Nodo* inicio, int numero){
    Nodo* nuevo=new Nodo;
    nuevo->dato=numero;
    nuevo->siguiente=inicio;
    return nuevo;
}

Nodo* cargarNumeros(Nodo* inicio){
    inicio=insertar(inicio, 7);
    inicio=insertar(inicio, 5);
    inicio=insertar(inicio, 9);
    inicio=insertar(inicio, 3);
    inicio=insertar(inicio, 6);
    return inicio;
}

void imprimir(Nodo* inicio){
    for (Nodo* p=inicio; p!=nullptr; p=p->siguiente){
        cout << p->dato << "  ";
    }
    cout << endl;
}

Nodo* funcion(Nodo* inicio){
   Nodo* puntero1=inicio;
   Nodo* puntero2=inicio;
   if (inicio!=nullptr){
       while (puntero1->siguiente != nullptr){
           puntero2=puntero1;
           puntero1=puntero1->siguiente;
       }
       if (puntero1 != puntero2){
           puntero2->siguiente=nullptr;
           delete puntero1;
       }
       else{
           delete inicio;
           inicio=nullptr;
       }
   }
   return inicio;
}

int main()
{
    Nodo* numeros=nullptr;
    numeros=cargarNumeros(numeros);
    imprimir(numeros);
    numeros=funcion(numeros);
    imprimir(numeros);
    return 0;
}