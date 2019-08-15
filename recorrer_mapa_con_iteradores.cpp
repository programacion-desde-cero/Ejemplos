//Explicación: https://youtu.be/cLKcJE87I5w
#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Persona{
    string nombre;
    int legajo;
};

map<string,Persona> cargarDatos(map<string,Persona> contenedor){
   Persona persona;
   persona.nombre="Marcela Lagos";
   persona.legajo=189;
   contenedor["Marketing"]=persona;
   persona.nombre="Joaquin Huerta";
   persona.legajo=426;
   contenedor["RR.HH."]=persona;
   persona.nombre="Ricardo Gimenez";
   persona.legajo=165;
   contenedor["Administracion"]=persona;
   persona.nombre="Jessica Williams";
   persona.legajo=329;
   contenedor["Capacitaciones"]=persona;
   persona.nombre="Jonathan Rojas";
   persona.legajo=253;
   contenedor["Proyectos"]=persona;
   persona.nombre="Julia Dominguez";
   persona.legajo=397;
   contenedor["Reclutadores"]=persona;
   return contenedor;
}


void imprimir(map<string,Persona> contenedor){
   for (auto par=begin(contenedor); par!=end(contenedor); par++){
       cout << "Departamento: " << par->first << endl;
       cout << "Jefe: " << par->second.nombre << " --- Legajo: " << par->second.legajo << endl << endl;
   }
}


int main()
{
   map<string,Persona> jefes;
   jefes=cargarDatos(jefes);
   imprimir(jefes);
   return 0;
}