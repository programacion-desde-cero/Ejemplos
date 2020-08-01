/* Implementación de operaciones básicas con listas simplemente enlazadas, utilizando "raw pointers" y sin orientación a objetos.
* Cada función incluye su especificación en forma de comentario.
*/


#include <iostream>
using namespace std;


struct Nodo {
   int dato;
   Nodo *siguiente;
};


/* Dado el puntero inicial a una lista y el puntero a un nuevo nodo que aún no está en la lista, inserta este nuevo nodo al principio. Retorna el puntero inicial. */
Nodo* insertar_principio(Nodo* inicio, Nodo* nuevo) {
   nuevo->siguiente = inicio;
   return nuevo;
}


/* Dado el puntero inicial a una lista y el puntero a un nuevo nodo que aún no está en la lista, inserta este nuevo nodo al final. Retorna el puntero inicial. */
Nodo* insertar_final(Nodo*  inicio, Nodo* nuevo) {
    if (inicio == nullptr)
        inicio = nuevo;
    else {
        Nodo* aux = inicio;
        while (aux->siguiente != nullptr)
            aux = aux->siguiente;
        aux->siguiente = nuevo;
    }
    return inicio;
}


/* Dado el puntero inicial a una lista y el puntero a un nuevo nodo que aún no está en la lista, inserta este nuevo nodo en orden ascendente. Retorna el puntero inicial. */
Nodo* insertar_ordenado(Nodo* inicio, Nodo* nuevo) {
    if (inicio == nullptr || nuevo->dato < inicio->dato) {
        nuevo->siguiente = inicio;
        inicio = nuevo;
    }
    else {
        Nodo* aux = inicio;
        while (aux->siguiente != nullptr && aux->siguiente->dato < nuevo->dato) {
            aux = aux->siguiente;
        }
        nuevo->siguiente = aux->siguiente;
        aux->siguiente = nuevo;
    }
    return inicio;
}


/* Genera un nuevo nodo con el dato pasado por parámetro y el puntero al siguiente en nullptr.
Retorna un puntero al nodo creado. */
Nodo* generar_nodo(int dato) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = dato;
    nuevo->siguiente = nullptr;
    return nuevo;
}


/* Imprime en pantalla todos los elementos de la lista. */
void imprimir_lista(Nodo* inicio) {
    for (Nodo* aux = inicio; aux != nullptr; aux = aux->siguiente) {
       cout << aux->dato << " ";
    }
    cout << endl;
}


/* Busca un dato en la lista, retornando un puntero al nodo si lo encuentra, o nullptr si no lo encuentra. */
Nodo* buscar(Nodo* inicio, int datoBuscado) {
    Nodo* aux = inicio;
    while (aux != nullptr && aux->dato != datoBuscado) {
        aux = aux->siguiente;
    }
    return aux;
}


/* Elimina de la lista la primera ocurrencia del dato pasado por parámetro.
Retorna un puntero al nodo inicial de la lista (que puede haberse modificado si se eliminó el primer nodo. */
Nodo* eliminar(Nodo* inicio, int datoABorrar) {
    if (inicio != nullptr) {   //Sólo proceder si la lista tiene nodos
        Nodo* aux = inicio;
        if (inicio->dato == datoABorrar) {   //El nodo a borrar es el primero
            inicio = inicio->siguiente;
            delete aux;
        }
        else {     //Si no se eliminó el primer nodo, buscamos el dato a partir del segundo
            while (aux->siguiente != nullptr && aux->siguiente->dato != datoABorrar) {
                aux = aux->siguiente;
            }
            if (aux->siguiente->dato == datoABorrar) { 
                Nodo* aEliminar = aux->siguiente;
                aux->siguiente = aEliminar->siguiente;
                delete aEliminar;
            }
        }
    }
    return inicio;
}


/* Elimina de la lista todas las ocurrencias del dato pasado por parámetro. 
Retorna un puntero al nodo inicial de la lista (que puede haberse modificado si se eliminó el primer nodo. */
Nodo* eliminar_ocurrencias(Nodo* inicio, int datoABorrar) {
   Nodo* a_eliminar;
   Nodo* aux = inicio;
   while (aux != nullptr) {   //Iteramos hasta el final porque podría eliminarse más de una vez el primer nodo de la lista
       if (inicio->dato == datoABorrar) {   //Este es el caso en que el elemento a eliminar está al inicio de la lista
           a_eliminar = inicio;
           inicio = inicio->siguiente;
           aux = inicio;
           delete a_eliminar;
       }
       else {
           if (aux->siguiente != nullptr && aux->siguiente->dato == datoABorrar) {   //Este es el caso en que el siguiente nodo se debe eliminar
               a_eliminar = aux->siguiente;
               aux->siguiente = a_eliminar->siguiente;
               delete a_eliminar;
           }
           else {    //El siguiente nodo no se debe eliminar o no hay siguiente, entonces avanzamos
               aux = aux->siguiente;
           }
       }
   }
   return inicio;
}


/* Retorna la cantidad de nodos en la lista. */
int cantidad_nodos(Nodo* inicio){
    int c = 0;
    Nodo* aux = inicio;
    for (; aux != nullptr; aux = aux->siguiente){
        c++;
    }
    return c;
}


/* Busca el nodo en la posición dada por k, y retorna ese nodo. Si no se encuentra (por ejemplo, si la lista tiene menos de "k" nodos) retorna nullptr. */
Nodo* k_esimo(Nodo* inicio, int k){
    int c = 0;
    Nodo* aux = inicio;
    for (; aux != nullptr; aux = aux->siguiente){
        c++;
        if (c == k){
            break;
        }
    }
    return aux;
}


/* Divide una lista en dos nuevas listas: una con los números pares y otra con los impares, dejando a la lista original vacía. */
void dividir_lista(Nodo* & inicio, Nodo* & pares, Nodo* & impares) {
    Nodo* anterior;
    while (inicio != nullptr) {
        anterior = inicio;
        inicio = inicio->siguiente;
        anterior->siguiente = nullptr;   //Corta el enlace con el siguiente, para que sea reubicado en la lista correspondiente
        if (anterior->dato % 2 == 0) {
            pares = insertar_final(pares, anterior);
        }
        else {
            impares = insertar_final(impares, anterior);
        }
    }
}


/* Dado el puntero inicial de una lista y un puntero a una lista nueva, inserta el primer nodo de la lista original al final de la nueva. La lista original se modifica, quedando el que antes era el segundo nodo como el nodo inicial. */
void reinsertar_nodo(Nodo* & lista_original, Nodo* & lista_nueva) {
    Nodo* anterior = lista_original;
    lista_original = lista_original->siguiente;
    anterior->siguiente = nullptr;
    lista_nueva = insertar_final(lista_nueva, anterior);
}


/* Unifica dos listas ordenadas en una, manteniendo el mismo criterio de ordenamiento. 
Las listas originales quedan vacías. Retorna un puntero a la nueva lista. */
Nodo* merge(Nodo* & A, Nodo* & B) {
    Nodo* C = nullptr;
    while (A != nullptr && B != nullptr) {
        if (A->dato <= B->dato) {
            reinsertar_nodo(A, C);
        }
        else {
            reinsertar_nodo(B, C);
        }
    }
    while (A != nullptr) {
        reinsertar_nodo(A, C);
    }
    while (B != nullptr) {
        reinsertar_nodo(A, C);
    }
    return C;
}


/* Dado el puntero inicial de una lista, invierte sus elementos.
Retorna un puntero al inicio de la lista. */
Nodo* invertir(Nodo* inicio) {
    if (inicio != nullptr) {
        Nodo* tmp;
        Nodo* anterior = inicio;
        Nodo* actual = anterior->siguiente;
        while (actual != nullptr) {
            tmp = actual->siguiente;
            actual->siguiente = anterior;
            if (anterior == inicio)
                anterior->siguiente = nullptr;
            anterior = actual;
            actual = tmp;
        }
        inicio = anterior;
    }
    return inicio;
}


/* Dado el puntero inicial de una lista, elimina todos sus nodos.
La lista original queda vacía (puntero inicial en nullptr) */
void eliminar(Nodo* & inicio) {
    if (inicio != nullptr) {
        Nodo* anterior = inicio;
        Nodo* actual = anterior->siguiente;
        while (actual != nullptr) {
            delete anterior;
            anterior = actual;
            actual = actual->siguiente;
        }
        delete anterior;
    }
    inicio = nullptr;
}


/* Carga números en la lista pasada por parámetro, en forma ordenada ascendente */
Nodo* cargar_lista_ordenada(Nodo* inicio) {
    int numeros[] = {5, 8, 2, 5, 10, 4, 1, 9, 5, 7, 6, 3};
    for (int i = 0; i < 12; i++) {
        inicio = insertar_ordenado(inicio, generar_nodo(numeros[i]));
    }
    return inicio;    
}


/* Función principal del programa. Se crean punteros iniciales a listas y se llama a funciones que ejecutan distintas operaciones. */
int main() {        
    cout << "*** Generar una lista con números en orden ascendente e imprimir para visualizarla:" << endl;
    Nodo* listaA = nullptr;
    listaA = cargar_lista_ordenada(listaA);
    imprimir_lista(listaA);
    
    cout << "*** Eliminar el elemento 9: " << endl;
    listaA = eliminar(listaA, 9);
    imprimir_lista(listaA);
    
    cout << "*** Eliminar ocurrencias del 5: " << endl;
    listaA = eliminar_ocurrencias(listaA, 5);
    imprimir_lista(listaA);
    
    cout << "*** Insertar el 0 al principio y el 10 al final: " << endl;
    listaA = insertar_principio(listaA, generar_nodo(0));
    listaA = insertar_final(listaA, generar_nodo(10));
    imprimir_lista(listaA);

    cout << "*** Cantidad de nodos en la lista: " << cantidad_nodos(listaA) << endl;
    
    cout << "*** Buscar el elemento 12 en la lista: " << endl;
    if (buscar(listaA, 12) == nullptr)
        cout << "  - El elemento no se encuentra en la lista." << endl;
    
    cout << "*** Elemento en cuarto lugar: " << k_esimo(listaA, 4)->dato << endl;  //Se asume que la lista tiene al menos 4 nodos
    
    Nodo* listaB = nullptr;
    Nodo* listaC = nullptr;
    cout << "*** Dividir la lista original en dos." << endl;
    dividir_lista(listaA, listaB, listaC);
    cout << "  - Lista de pares: " << endl;
    imprimir_lista(listaB);
    cout << "  - Lista de impares: " << endl;
    imprimir_lista(listaC);
    
    cout << "*** Unificar las listas de pares e impares para formar una sola: " << endl;
    listaA = merge(listaB, listaC);
    imprimir_lista(listaA);

    cout << "*** Invertir la lista: " << endl;
    listaA = invertir(listaA);
    imprimir_lista(listaA);
    
    cout << "*** Eliminar la lista: " << endl;
    eliminar(listaA);
    imprimir_lista(listaA);

    return 0;
}
