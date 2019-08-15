//Código correspondiente al video https://youtu.be/rpSY0NfbhUo
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct Escritura {
    int fecha;
    string cuit;
    double monto;
};

struct Transaccion {
    string cuit;
    double valor;
};

struct InformacionEscrituras {
    int cantidadEscrituras;
    double montoTotal;
};

struct Nodo {
    Transaccion dato;
    Nodo *siguiente;
};

void insertarOrdenado(vector<Escritura> &escrituras, Escritura e){
    auto iterador=begin(escrituras);
    while ( (iterador != end(escrituras)) && (*iterador).fecha < e.fecha ){
        iterador++;
        while ( (iterador != end(escrituras)) && (*iterador).fecha == e.fecha && (*iterador).cuit < e.cuit ){
            iterador++;
        }
    }
    escrituras.insert(iterador, e);
}

void cargarEscrituras(vector<Escritura> &escrituras){
    Escritura e;
    do{
        cout << "Ingrese cuit (finaliza con CUIT 30-11111111-8): ";
        cin >> e.cuit;
        cout << "Ingrese fecha (AAAAMMDD): ";
        cin >> e.fecha;
        cout << "Ingrese el monto: ";
        cin >> e.monto;
        insertarOrdenado(escrituras, e);
    } while (e.cuit != "30-11111111-8");
}


Nodo* insertarAlFinal(Nodo* inicio, Transaccion t){
    Nodo* nuevo=new Nodo;
    nuevo->dato=t;
    nuevo->siguiente=nullptr;
    if (inicio==nullptr){
        inicio=nuevo;
    }
    else{
        Nodo* p=inicio;
        while (p->siguiente!=nullptr){
            p=p->siguiente;
        }
        p->siguiente=nuevo;
    }
    return inicio;
}

Nodo* cargarTransacciones(Nodo* inicio){
    Transaccion t;
    cout << "Ingrese cuit (finaliza con CUIT 0): ";
    cin >> t.cuit;
    while (t.cuit != "0"){
        cout << "Ingrese monto: ";
        cin >> t.valor;
        
        inicio=insertarAlFinal(inicio, t);
        
        cout << "Ingrese cuit (finaliza con CUIT 0): ";
        cin >> t.cuit;
    }
    return inicio;
}

void contar(const vector<Escritura> &escrituras, map<string, InformacionEscrituras> &mapa){
    InformacionEscrituras contador;
    for (Escritura e : escrituras){
        //Si el cuit no existe en el mapa, lo agrega
        if ( mapa.find(e.cuit) == end(mapa) ){
            contador.cantidadEscrituras=1;
            contador.montoTotal=e.monto;
            mapa[e.cuit]=contador;
        }
        //Si el cuit existe en el mapa, incrementa contador y acumula monto
        else{
            mapa[e.cuit].cantidadEscrituras++;
            mapa[e.cuit].montoTotal += e.monto; 
        }
    }
}

void mostrarDatosPorCuit(const map<string,InformacionEscrituras> &datosPorCuit){
    for (auto par: datosPorCuit)
    {
        if (par.second.cantidadEscrituras > 1){
            cout << "CUIT: " << par.first << endl;
            cout << "Cantidad: " << par.second.cantidadEscrituras << endl;
            cout << "Monto total: " << par.second.montoTotal << endl << endl;
        }
    }
}

set<string> buscarCoincidencias(const map<string,InformacionEscrituras> &mapa, Nodo* inicio){
    set<string> cuits;
    for (Nodo* aux=inicio; aux!=nullptr; aux=aux->siguiente){
        if (mapa.find(aux->dato.cuit) != end(mapa)){
            if (mapa.at(aux->dato.cuit).cantidadEscrituras > 1){
                cuits.insert(aux->dato.cuit);
            }
        }
    }
    return cuits;
}

void imprimirDatos(Transaccion t){
	cout << "* Operacion eliminada:" << endl;
    cout << t.cuit << endl;
    cout << t.valor << endl;
	cout << endl;
}


int eliminar(Nodo* &inicio)
{
    int cant_eliminadas=0;

    Nodo* aEliminar;
    Nodo* aux=inicio;
    while (aux!=nullptr){
        if (inicio->dato.valor<1000){
			imprimirDatos(inicio->dato);
            aEliminar = inicio;
            inicio = inicio->siguiente;
            aux = aux->siguiente;
            delete aEliminar;
            cant_eliminadas++;
        }
        else{
            if (aux->siguiente!=nullptr && aux->siguiente->dato.valor<1000){
                imprimirDatos(aux->siguiente->dato);
                aEliminar=aux->siguiente;
                aux->siguiente=aux->siguiente->siguiente;
                delete aEliminar;
                cant_eliminadas++;
            }
            else{
                aux=aux->siguiente;
            }
        }
    }
    return cant_eliminadas;
}

void imprimirLista(Nodo* inicio){
    for (Nodo* aux=inicio; aux!= nullptr; aux=aux->siguiente){
        cout << aux->dato.cuit << " - " << aux->dato.valor << endl;
    }
}

//datos para probar el programa
void cargarDatosDePrueba(vector<Escritura> &v, Nodo* &inicio){
    insertarOrdenado(v, {20171203, "27-32196846-1", 10000});
    insertarOrdenado(v, {20180217, "20-49283412-9", 7500});
    insertarOrdenado(v, {20180913, "20-49283412-9", 68700});
    insertarOrdenado(v, {20181008, "20-49283412-9", 11320});;
    insertarOrdenado(v, {20171203, "30-88542111-3", 22500});
    insertarOrdenado(v, {20180913, "30-88542111-3", 40000});
    insertarOrdenado(v, {20171205, "30-88542111-3", 9000});
    insertarOrdenado(v, {20171118, "27-06971822-4", 38000});
    insertarOrdenado(v, {20171203, "20-31457282-8", 8000});
    insertarOrdenado(v, {20180623, "20-31457282-8", 18000});
    insertarAlFinal(inicio, {"30-88542111-3", 40000});
    insertarAlFinal(inicio, {"30-88542111-3", 800});
    insertarAlFinal(inicio, {"27-32196846-1", 4300});
    insertarAlFinal(inicio, {"27-32196846-1", 690});
    insertarAlFinal(inicio, {"27-32196846-1", 1000});
    insertarAlFinal(inicio, {"20-31457282-8", 29000});
    insertarAlFinal(inicio, {"20-31457282-8", 5000});
}


int main()
{
    vector<Escritura> escrituras;
    cout << "***CARGA DE ESCRITURAS: " << endl;
    cargarEscrituras(escrituras);

    Nodo* transacciones;
    transacciones = nullptr;
    cout << "***CARGA DE TRANSACCIONES: " << endl;
    transacciones=cargarTransacciones(transacciones);

    //Para cargar datos de prueba, descomentar la siguiente llamada a función
    //cargarDatosDePrueba(escrituras,transacciones);

	cout << endl;
	
    map<string,InformacionEscrituras> contadorDeEscrituras;
    cout << "***CUITs QUE TIENEN MAS DE 1 ESCRITURA:" << endl;
    contar(escrituras,contadorDeEscrituras);
    mostrarDatosPorCuit(contadorDeEscrituras);

    cout << "***CUITs CON MAS DE 1 ESCRITURA QUE HICIERON TRANSACCIONES INTERNACIONALES: " << endl;
    for ( string cuit : buscarCoincidencias(contadorDeEscrituras,transacciones) ){
        cout << "Numero CUIT: " << cuit << endl;
    }
	
	cout << endl;
	
    cout << "***CANTIDAD DE TRANSACCIONES ELIMINADAS (MONTO MENOR A 1000): " << eliminar(transacciones) << endl << endl;

    cout << "***LISTADO DE TRANSACCIONES EN EL EXTERIOR: " << endl;
    imprimirLista(transacciones);

    return 0;
}