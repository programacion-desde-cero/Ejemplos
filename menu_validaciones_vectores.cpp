//Explicación: https://youtu.be/Tzu2rCOJn9M
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Alumno{
    int legajo;
    string nombre;
};

struct Grupo{
    int numero;
    int legajo1;
    int legajo2;
};

bool existeLegajo(vector<Alumno> v, int legajo){
    for (Alumno elemento : v){
        if (elemento.legajo == legajo){
            return true;
        }
    }
    return false;
}

vector<Alumno> cargarAlumnos(vector<Alumno> alumnos){
    Alumno alumno;
    cout << "Numero de legajo (-1 corta la carga): ";
    cin >> alumno.legajo;
    while (alumno.legajo!=-1){
        if (existeLegajo(alumnos, alumno.legajo)){
            cout << "Ese legajo ya esta cargado. Ingrese otro." << endl;
        }
        else{
            cout << "Nombre del alumno: ";
            cin.ignore();
            getline(cin, alumno.nombre);
            alumnos.push_back(alumno);
        }
        cout << "Numero de legajo (-1 corta la carga): ";
        cin >> alumno.legajo;
    }
    return alumnos;
}

void imprimirAlumnos(vector<Alumno> alumnos){
    for (auto elemento : alumnos){
        cout << "Legajo: " << elemento.legajo << " - Nombre: " << elemento.nombre << endl;
        cout << "------" << endl;
    }
}

int numerarGrupo(vector<Grupo> grupos){
    if (grupos.empty()){
        return 1;
    }
    else{
        int ultPosicion=grupos.size()-1;
        return grupos[ultPosicion].numero+1;
    }
}

vector<Grupo> cargarGrupos(vector<Grupo> grupos, vector<Alumno> alumnos){
    Grupo grupo;
    cout << "Numero de legajo alumno 1 (-1 corta la carga): ";
    cin >> grupo.legajo1;
    while (grupo.legajo1 != -1){
        if (!existeLegajo(alumnos, grupo.legajo1)){
            cout << "Alumno inexistente. Ingrese otro. " << endl;
        }
        else{
            do{
                cout << "Numero de legajo alumno 2: ";
                cin >> grupo.legajo2;
                if (!existeLegajo(alumnos, grupo.legajo2)){
                    cout << "Alumno inexistente. Ingrese otro. " << endl;
                }
            } while (!existeLegajo(alumnos, grupo.legajo2));

            grupo.numero=numerarGrupo(grupos);

            grupos.push_back(grupo);
            cout << "Grupo agregado exitosamente." << endl;
        }
        cout << "Numero de legajo alumno 1 (-1 corta la carga): ";
        cin >> grupo.legajo1;
    }
    return grupos;
}

string buscarNombrePorLegajo(vector<Alumno> alumnos, int legajo){
    for (auto elemento : alumnos){
        if (elemento.legajo == legajo){
            return elemento.nombre;
        }
    }
    return "";
}

void imprimirGrupos(vector<Grupo> grupos, vector<Alumno> alumnos){
    for (auto elemento : grupos){
        cout << "Grupo: " << elemento.numero << endl;
        cout << "Alumno 1: " << buscarNombrePorLegajo(alumnos, elemento.legajo1) << endl;
        cout << "Alumno 2: " << buscarNombrePorLegajo(alumnos, elemento.legajo2) << endl;
        cout << "---------------------" << endl;
    }
}

int main(){

    vector<Alumno> alumnos;
    vector<Grupo> grupos;
    int opcion;
    do{
        cout << "MENU" << endl;
        cout << "1. Cargar alumnos" << endl;
        cout << "2. Imprimir listado de alumnos" << endl;
        cout << "3. Cargar grupos" << endl;
        cout << "4. Imprimir grupos" << endl;
        cout << "0. Salir" << endl;
        cin >> opcion;
        switch (opcion) {
        case 1:
            alumnos=cargarAlumnos(alumnos);
            break;
        case 2:
            imprimirAlumnos(alumnos);
            break;
        case 3:
            grupos=cargarGrupos(grupos,alumnos);
            break;
        case 4:
            imprimirGrupos(grupos,alumnos);
            break;
        case 0:
            cout << "Muchas gracias por utilizar este programa." << endl;
            break;
        default:
            cout << "Opcion incorrecta." << endl;
        }
    } while (opcion != 0);

    return 0;
}