//Explicación: https://youtu.be/GtzjM2mnjdc
/* Consigna:
Una ONG organiza una cena anual para recaudar fondos para sus actividades. Realizar un programa para:
A.	Cargar la información de las tarjetas vendidas en una lista, insertando al principio. De cada tarjeta se almacena: número, apellido del comprador, número de tarjeta de su acompañante, tipo de menú: normal, celíaco, diabético, dietético, vegetariano, para niños, kosher. 
●	Durante la carga se debe consultar al usuario si el comprador de la tarjeta tiene acompañante y, si es así, solicitarle el número de tarjeta de su acompañante; si no, se almacena el número -1.
●	Al cargar el tipo de menú se debe impedir al usuario ingresar otro que no sean los tipos mencionados, dejándolo en un bucle hasta que ingrese un tipo válido. Utilizar un contenedor para evitar una condición con múltiples proposiciones.
B.	Dado un número de tarjeta, eliminar de la lista esa tarjeta.
C.	Dado un tipo de menú, almacenar en un vector las tarjetas que lo solicitaron, ordenadas por número de tarjeta, para luego imprimir el contenido del vector. Mostrar cuántas tarjetas de ese menú se solicitaron (informar “no hay solicitudes” en caso de que no haya ninguna).
D.	Escribir el código necesario para usar dentro del programa la siguiente función (sin modificarla), imprimiendo (cout) mensajes en pantalla para que el usuario sepa qué está viendo (menu es el campo que representa al tipo de menú dentro del struct que representa a las tarjetas):
map<string, int> funcion (Nodo* lista){
    map<string, int> c;
    for (; lista!=nullptr; lista=lista->siguiente){
        if (c.find(lista->tarjeta.menu) == end(c)) {
          c[lista->tarjeta.menu]=1;
        }
        else {
          c[lista->tarjeta.menu]++;
        }
    }
    return c;
}

*/


#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;


struct Tarjeta{
    int numero;
    string apellido;
    int acompanante;
    string menu;
};

struct Nodo{
    Tarjeta tarjeta;
    Nodo* siguiente;
};


void insertar_principio(Nodo* &inicio, Nodo* nuevo){
    nuevo->siguiente=inicio;
    inicio=nuevo;
}


void cargarTarjetas(Nodo* &inicio){
    set<string> menus={"normal", "celiaco", "diabetico", "dietetico", "vegetariano", "para niños", "kosher"};
    Nodo* nuevo;
    int numero;
    char respuesta;
    cout << "***CARGA DE TARJETA***\n";
    cout << "NUMERO (0 para finalizar la carga): ";
    cin >> numero;
    while(numero!=0){
        nuevo=new Nodo;
        nuevo->tarjeta.numero=numero;
        cout << "APELLIDO: ";
        cin.ignore();
        getline(cin,nuevo->tarjeta.apellido);
        do {
            cout << "MENU (normal, celiaco, diabetico, dietetico, vegetariano, para niños, kosher): ";
            getline(cin,nuevo->tarjeta.menu);
        } while (menus.find(nuevo->tarjeta.menu)==end(menus));
        cout << "TIENE ACOMPAÑANTE? S/N: ";
        cin >> respuesta;
        if (toupper(respuesta)=='S'){
            cout << "NUMERO DE TARJETA ACOMPAÑANTE: ";
            cin >> nuevo->tarjeta.acompanante;
        }
        else{
            nuevo->tarjeta.acompanante = -1;
        }

        insertar_principio(inicio,nuevo);

        cout << "***CARGA DE TARJETA***\n";
        cout << "NUMERO (0 para finalizar la carga): ";
        cin >> numero;
    }
}




map<string, int> funcion (Nodo* lista){
    map<string, int> c;
    for (; lista!=nullptr; lista=lista->siguiente){
        if (c.find(lista->tarjeta.menu) == end(c)) {
            c[lista->tarjeta.menu]=1;
        }
        else {
            c[lista->tarjeta.menu]++;
        }
    }
    return c;
}


void eliminarTarjeta(Nodo* &inicio, int numero){
    if (inicio!=nullptr){
        Nodo* aux=inicio;
        if (inicio->tarjeta.numero == numero){
            inicio = inicio->siguiente;
            delete aux;
        }
        else{
            while (aux->siguiente != nullptr && aux->siguiente->tarjeta.numero != numero){
                aux = aux->siguiente;
            }
        }
        if (aux->siguiente != nullptr){
            if (aux->siguiente->tarjeta.numero==numero){
                Nodo* aEliminar = aux->siguiente;
                aux->siguiente=aux->siguiente->siguiente;
                delete aEliminar;
            }
        }
    }
}


void insertarOrdenadoEnVector(vector<Tarjeta> &vec, Tarjeta tarjeta){
    auto iterador=begin(vec);
    while (iterador!=end(vec) && (*iterador).numero <= tarjeta.numero){
        iterador++;
    }

    if (iterador == end(vec)){
        vec.push_back(tarjeta);
    }
    else{
        vec.insert(iterador,tarjeta);
    }
}



vector<Tarjeta> filtrar(Nodo* inicio, string menu){
    vector<Tarjeta> filtradas;
    for (; inicio!=nullptr; inicio=inicio->siguiente){
        if (inicio->tarjeta.menu==menu){
            insertarOrdenadoEnVector(filtradas, inicio->tarjeta);
        }
    }
    return filtradas;
}




int main(){
    Nodo* tarjetas=nullptr;
    cargarTarjetas(tarjetas);

    int numero;
    cout << "***TARJETA A ELIMINAR: ";
    cin >> numero;
    eliminarTarjeta(tarjetas, numero);

    string menu;
    cout << "\n***LISTAR ASISTENTES CON UN TIPO DE MENU\n";
    cout << "TIPO DE MENU (normal, celiaco, diabetico, dietetico, vegetariano, para niños, kosher): ";
    cin.ignore();
    getline(cin,menu);
    vector<Tarjeta> filtradas=filtrar(tarjetas,menu);
    for (Tarjeta t: filtradas){
        cout << t.numero << " - " << t.apellido << " - ";
        if (t.acompanante==-1){
            cout << "Sin acompañante\n";
        }
        else{
            cout << t.acompanante << endl;
        }
    }
    if (filtradas.empty()){
        cout << "***NO HAY SOLICITUDES***";
    }
    else{
        cout << "\nCantidad de tarjetas de menu " << menu << ": " << filtradas.size() << endl;
    }

    cout << "\n***CANTIDAD DE PEDIDOS POR TIPO DE MENU:\n";
    for (auto par: funcion(tarjetas)){
        cout << par.first << ": " << par.second << endl;
    }

    return 0;
}