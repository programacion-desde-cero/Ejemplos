//Explicación: https://youtu.be/cLKcJE87I5w
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct Persona{
    string nombre;
    int legajo;
};

map<string,vector<Persona>> cargarDatos(map<string,vector<Persona>> contenedor){
    Persona persona;

    persona.nombre="Marcela Lagos";
    persona.legajo=189;
    contenedor["Administracion"].push_back(persona);

    persona.nombre="Joaquin Huerta";
    persona.legajo=426;
    contenedor["Produccion"].push_back(persona);

    persona.nombre="Ricardo Gimenez";
    persona.legajo=165;
    contenedor["Administracion"].push_back(persona);

    persona.nombre="Jessica Williams";
    persona.legajo=329;
    contenedor["Capacitaciones"].push_back(persona);

    persona.nombre="Jonathan Rojas";
    persona.legajo=253;
    contenedor["Produccion"].push_back(persona);

    persona.nombre="Julia Dominguez";
    persona.legajo=397;
    contenedor["Capacitaciones"].push_back(persona);

    persona.nombre="Rodolfo Quinteros";
    persona.legajo=562;
    contenedor["Produccion"].push_back(persona);

    persona.nombre="Estela Moreno";
    persona.legajo=716;
    contenedor["Produccion"].push_back(persona);

    persona.nombre="Marcelo Ramirez";
    persona.legajo=296;
    contenedor["Produccion"].push_back(persona);

    return contenedor;
}


vector<Persona> insertarOrdenado(vector<Persona> v, Persona p){
    auto elemento = begin(v);
    while ((elemento != end(v)) and ((*elemento).legajo <= p.legajo)){
        elemento++;
    }
    if (elemento == end(v)){
        v.push_back(p);
    }
    else{
        v.insert(elemento, p);
    }
    return v;
}


vector<Persona> filtrarEmpleados(map<string,vector<Persona>> empleados, string area){
    vector<Persona> nuevo;
    for (auto emp = begin(empleados[area]); emp != end(empleados[area]); emp++){
        nuevo=insertarOrdenado(nuevo, (*emp));
    }
    return nuevo;
}


void imprimir(vector<Persona> contenedor){
    for (auto emp = begin(contenedor); emp != end(contenedor); emp++){
        cout << "Nombre: " << emp->nombre << " - Legajo: " << emp->legajo << endl;
    }
}


vector<Persona> eliminarPorDigito(vector<Persona> contenedor, int digito){
    auto p = begin(contenedor);
    while (p != end(contenedor)){
        if ((*p).legajo % 10 == digito){
            p = contenedor.erase(p);
        }
        else{
            p++;
        }
    }
    return contenedor;
}


int main()
{
    map<string,vector<Persona>> empleados;
    empleados=cargarDatos(empleados);

    string area;
    cout << "Area a filtrar: ";
    cin >> area;
    vector<Persona> filtrado;
    filtrado=filtrarEmpleados(empleados, area);

    imprimir(filtrado);

    int digito;
    cout << "Ultimo digito a eliminar: ";
    cin >> digito;
    filtrado=eliminarPorDigito(filtrado, digito);

    imprimir(filtrado);

    return 0;
}