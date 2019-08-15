//Explicación: https://youtu.be/sqTS43OkZjY
/*************** 
* CONSIGNA:
* Codificar un programa que permita leer y almacenar en memoria los datos de personas inscriptas en un curso de un instituto. De cada persona se tiene: número identificatorio, nombre, provincia, si ha pagado o no el valor del curso.
* Realizar los incisos pedidos a continuación:
* a) Cargar en un arreglo estático la información de todos los inscriptos, ingresados por teclado. El arreglo tiene una capacidad máxima de 500 elementos. Se desconoce cuántos inscriptos deberán cargarse. 
* b) Contabilizar e imprimir cuántos inscriptos hay en cada provincia y cuántos inscriptos hay en total.
* d) A partir del arreglo estático cargado en el inciso a, generar un vector que contenga sólo los inscriptos de determinada provincia (dada por el usuario), y luego imprimir todos los elementos de dicho vector.
* c) Dado el arreglo estático del inciso a, eliminar todos los inscriptos que no han pagado. Imprimir el arreglo resultante.
*/


#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

const int MAX=500;

struct Inscripto{
   int numero;
   string nombre;
   string provincia;
   bool pago;
};

void carga(Inscripto inscriptos[], int &dl){
   int numero;
   char pago;
   cout << "Numero identificador (-1 para cortar): ";
   cin >> numero;
   while (numero!=-1 && dl < MAX){
       inscriptos[dl].numero=numero;
       cout << "Nombre: ";
       cin.ignore();
       getline(cin,inscriptos[dl].nombre);
       cout << "Provincia: ";
       getline(cin,inscriptos[dl].provincia);
       cout << "Pago? ('S' / 'N'): ";
       do {
           cin >> pago;
           if (toupper(pago)!='S' && toupper(pago)!='N'){
               cout << "Pago? (debe ingresar 'S' o 'N'): ";
           }
       } while(toupper(pago)!='S' && toupper(pago)!='N');
       if (toupper(pago)=='S')
           inscriptos[dl].pago=true;
       else
           inscriptos[dl].pago=false;

       dl++;
       if (dl < MAX){
           cout << "Numero identificador (-1 para cortar): ";
           cin >> numero;
       }
   }
}

void eliminarImpagos(Inscripto inscriptos[], int &dl){
   int i=0;
   while (i<dl){
       if (inscriptos[i].pago==false){
           for (int j=i; j<dl-1; j++)
               inscriptos[j]=inscriptos[j+1];
           dl--;
       }
       else
           i++;
   }
}

map<string,int> contabilizarPorProvincia(Inscripto inscriptos[], int dl){
   map<string,int> contadores;
   for (int i=0; i<dl; i++){
       if (contadores.find(inscriptos[i].provincia)==contadores.end())
           contadores[inscriptos[i].provincia]=1;
       else
           contadores[inscriptos[i].provincia]++;
   }
   return contadores;
}


vector <Inscripto> inscriptosDeProvincia(Inscripto inscriptos[], int dl, string provincia){
   vector <Inscripto> nuevo;
   for (int i=0; i<dl; i++){
       if (inscriptos[i].provincia == provincia){
           nuevo.push_back(inscriptos[i]);
       }
   }
   return nuevo;
}

void imprimirVector(vector <Inscripto> vec){
   for (Inscripto persona: vec){
       cout << "Numero ID: " << persona.numero << "\n";
       cout << "Nombre: " << persona.nombre << "\n";
       cout << "Provincia: " << persona.provincia << "\n";
       if (persona.pago){
           cout << "Pago \n";
       }
       else{
           cout << "Impago \n";
       }
       cout << "------------\n";
   }
}

void imprimirArreglo(Inscripto inscriptos[], int dl){
    for (int i=0; i<dl; i++){
        cout << "Numero ID: " << inscriptos[i].numero << "\n";
        cout << "Nombre: " << inscriptos[i].nombre << "\n";
        cout << "Provincia: " << inscriptos[i].provincia << "\n";
        cout << "------------\n";
    }
}


int main(){
   Inscripto inscriptos[MAX];
   int dl=0;

   cout << "***CARGA DE LOS DATOS***\n";
   carga(inscriptos,dl);

   cout << "\n***CANTIDAD DE INSCRIPTOS POR PROVINCIA***\n";
   map<string,int> contadores=contabilizarPorProvincia(inscriptos,dl);
   for (auto contador: contadores)
       cout << contador.first << ": " << contador.second << "\n";

   cout << "\n***CANTIDAD DE INSCRIPTOS EN TOTAL: " << dl << "***\n";

   string provincia;
   cout << "\n***PROVINCIA PARA IDENTIFICAR INSCRIPTOS: ";
   cin.ignore();
   getline(cin,provincia);
   imprimirVector(inscriptosDeProvincia(inscriptos,dl,provincia));

   cout << "\n***LISTADO TOTAL EXCEPTUANDO INSCRIPCIONES IMPAGAS: ***\n";
   eliminarImpagos(inscriptos,dl);
   imprimirArreglo(inscriptos,dl);

   return 0;
}