//Explicación: https://youtu.be/cLKcJE87I5w
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Persona{
    string nombre;
    int edad;
};

vector<Persona> cargarDatos(vector<Persona> contenedor){
   Persona persona;
   persona.nombre="Marcela";
   persona.edad=43;
   contenedor.push_back(persona);
   persona.nombre="Joaquin";
   persona.edad=28;
   contenedor.push_back(persona);
   persona.nombre="Ricardo";
   persona.edad=26;
   contenedor.push_back(persona);
   persona.nombre="Jessica";
   persona.edad=19;
   contenedor.push_back(persona);
   persona.nombre="Jonathan";
   persona.edad=16;
   contenedor.push_back(persona);
   persona.nombre="Julia";
   persona.edad=32;
   contenedor.push_back(persona); 
   return contenedor;
}


void imprimir(vector<Persona> contenedor){
   for (auto p = begin(contenedor); p != end(contenedor); p++){
       cout << "Nombre: " << p->nombre << " --- Edad: " << p->edad << endl;
   }
}


int main()
{
   vector<Persona> participantes;
   participantes=cargarDatos(participantes);
   imprimir(participantes);
   return 0;
}