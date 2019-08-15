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

   return contenedor;
}


void imprimir(map<string,vector<Persona>> contenedor){
    for (auto par = begin(contenedor); par != end(contenedor); par++){
        cout << endl << "***Area: " << par->first << endl;
        for (auto emp = begin(par->second); emp != end(par->second); emp++){
            cout << "Nombre: " << emp->nombre << " - Legajo: " << emp->legajo << endl;
        }
    }
}


int main()
{
   map<string,vector<Persona>> empleados;
   empleados=cargarDatos(empleados);
   imprimir(empleados);
   return 0;
}