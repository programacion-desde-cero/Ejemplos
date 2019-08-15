//Ejemplo correspondiente al video https://youtu.be/PQyHVUzR7bU
#include <iostream>

struct Nodo {
    int dato;
    Nodo* siguiente;
};



//(implementación de esta función: luego de main)
void imprimirLista(Nodo *inicio);


//Inserta tipo cola
Nodo* agregarAlfinal(Nodo* inicio, int elemento){
    Nodo *nuevo = new Nodo;
    nuevo->dato=elemento;
    nuevo->siguiente=nullptr;

    if (inicio == nullptr){
        inicio=nuevo;
    
    else{
        Nodo *aux = inicio;
        while (aux->siguiente != nullptr)
            aux = aux->siguiente;
        aux->siguiente=nuevo;
    
    return inicio;
}




int main()
{
    Nodo *inicio = nullptr;
    int num;
    
    cout << "Ingresar numeros a guardar (finalizar con 0): ";
    cin >> num;
    while (num != 0){
        inicio=agregarAlFinal(inicio, num);
        cin >> num;
    
    cout << "La lista queda asi: \n";
    imprimirLista(inicio);
    
    return 0;
}



//Muestra los elementos de la lista
void imprimirLista(Nodo *inicio){
    for(Nodo *p = inicio; p != nullptr; p = p->siguiente)
        cout << p->dato << endl;
    return;
}