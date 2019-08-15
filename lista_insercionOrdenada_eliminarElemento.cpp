//Explicación del código en https://youtu.be/ycbqnwFb43Y
#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo* siguiente;
};


Nodo* insertarOrdenado(Nodo* inicio, Nodo* nuevo){
    if (inicio == nullptr || nuevo->dato < inicio->dato){
        nuevo->siguiente=inicio;
        inicio=nuevo;
    }
    else{
        Nodo* aux=inicio;
        while (aux->siguiente!=nullptr && aux->siguiente->dato < nuevo->dato){
            aux=aux->siguiente;
        }
        if (aux->siguiente!=nullptr){
            nuevo->siguiente=aux->siguiente;
        }
        aux->siguiente=nuevo;
    }
    return inicio;
}

Nodo* cargarNumeros(Nodo* inicio){
    Nodo* nuevo;
    int n;
    cout << "Ingrese numero (0 para cortar): " ;
    cin >> n;
    while (n != 0){
        nuevo = new Nodo;
        nuevo->dato=n;
        nuevo->siguiente=nullptr;
        inicio=insertarOrdenado(inicio, nuevo);
        cout << "Ingrese numero (0 para cortar): " ;
        cin >> n;
    }
    return inicio;
}

void imprimir(Nodo* inicio){
    for (Nodo* p = inicio; p!=nullptr; p=p->siguiente){
        cout << p->dato << " ";
    }
    cout << endl;
}

Nodo* eliminarMultiplos(Nodo* inicio, int num){
    Nodo* aEliminar;
    Nodo* aux=inicio;
    while (aux!=nullptr){
        if (inicio->dato % num == 0){
            aEliminar=inicio;
            aux=aux->siguiente;
            inicio=inicio->siguiente;
            delete aEliminar;
        }
        else{
            if (aux->siguiente!=nullptr && aux->siguiente->dato % num == 0){
                aEliminar=aux->siguiente;
                aux->siguiente=aux->siguiente->siguiente;
                delete aEliminar;
            }
            else{
                aux=aux->siguiente;
            }
        }
    }
    return inicio;
}


int main()
{
    Nodo* lista=nullptr;
    lista=cargarNumeros(lista);

    cout << "Lista original:" << endl;
    imprimir(lista);

    lista=eliminarMultiplos(lista, 3);

    cout << endl;
    cout << "Lista sin los multiplos: "<< endl;
    imprimir(lista);

    return 0;
}