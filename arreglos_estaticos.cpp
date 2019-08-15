//Explicación: https://youtu.be/AQj-JYfAHSQ
/*
* La universidad posee información histórica sobre los alumnos de una carrera en el último año lectivo (no más de 1000). De cada uno almacena: nombre y apellido, legajo, cantidad de inasistencias a clase, calificación promedio obtenida en el año.
* Almacenar esta información en un arreglo estático.
* Se pide:
* A. Imprimir nombre y apellido de los alumnos que tuvieron más de 5 inasistencias.
* B. Imprimir nombre, apellido y legajo de los alumnos cuya calificación promedio sea mayor a la calificación promedio total (se debe calcular un promedio de las calificaciones de todos los alumnos en el listado).
* C. Imprimir el número de legajo de aquellos alumnos que tienen promedio mayor o igual a nueve.
*/


#include <iostream>
#include <string>
using namespace std;

const int MAX=1000;

struct Alumno{
    string nombre;
    int legajo;
    int inasistencias;
    float promedio;
};

int cargar(Alumno alumnos[], int dl){
    int legajo;
    cout << "Legajo: ";
    cin >> legajo;
    while (legajo!=0 && dl<MAX){
        alumnos[dl].legajo=legajo;
        cout << "Nombre y apellido: ";
        cin.ignore();
        getline(cin, alumnos[dl].nombre);
        cout << "Inasistencias: ";
        cin >>  alumnos[dl].inasistencias;
        cout << "Promedio: ";
        cin >> alumnos[dl].promedio;
        dl++;

        cout << "Legajo: ";
        cin >> legajo;
    }
    return dl;
}


float promedioTotal(Alumno alumnos[], int dl){
    float suma=0;
    for (int i=0; i<dl; i++){
        suma+=alumnos[i].promedio;
    }
    return (float)suma/(float)dl;
}


void promedioMayorAlTotal(Alumno alumnos[], int dl){
    float promedioGeneral=promedioTotal(alumnos, dl);
    for (int i=0; i<dl; i++){
        if (alumnos[i].promedio > promedioGeneral){
            cout << alumnos[i].nombre << "\t" << alumnos[i].legajo << endl;
        }
    }
}



void imprimirInasistencias(Alumno alumnos[], int dl){
    for (int i=0; i<dl; i++){
        if (alumnos[i].inasistencias > 5){
            cout << "Nombre y apellido: " << alumnos[i].nombre << endl;
        }
    }
}


void mejoresPromedios(Alumno alumnos[], int dl, int calificacionASuperar){
    for (int i=0; i<dl; i++){
        if (alumnos[i].promedio >= calificacionASuperar){
            cout << alumnos[i].legajo << endl;
        }
    }
}


int main()
{
    Alumno alumnos[MAX];
    int dl=0;
    dl=cargar(alumnos, dl);

    cout << "Alumnos con mas de 5 inasistencias: " << endl;
    imprimirInasistencias(alumnos, dl);

    cout << "Superan el promedio total: " << endl;
    promedioMayorAlTotal(alumnos, dl);

    cout << "Promedio de 9 o mas: " << endl;
    mejoresPromedios(alumnos, dl, 9);

    return 0;
}