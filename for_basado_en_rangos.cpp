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


int cantidadConInicial(map<string,vector<Persona>> contenedor, char letra){
    int cantidad=0;
    for (auto par: contenedor){
        for (Persona empleado: par.second){
            if (empleado.nombre[0]==letra){
                cantidad++;
            }
        }
    }
    return cantidad;
}


int main()
{
    map<string,vector<Persona>> empleados;
    empleados=cargarDatos(empleados);

    char letra;
    cout << "Inicial a buscar: ";
    cin >> letra;
    cout << "Hay " << cantidadConInicial(empleados, letra) << " empleados cuyos nombres empiezan con " << letra << endl;

    return 0;
}