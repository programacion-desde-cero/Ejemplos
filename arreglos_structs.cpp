//Explicación: https://youtu.be/F-iYfI0VfvM

/* Crear un programa que muestre un menú iterativo para realizar las siguientes acciones, almacenando los datos en arreglos estáticos en memoria:
 * - Almacenar datos de alumnos que cursan una materia: número de legajo, nombre, email y teléfono. Almacenarlos ordenados por legajo. Máximo: 100.
 * Se debe impedir ingresar legajos repetidos.
 * - Almacenar datos de grupos de trabajo en clase, donde cada grupo está conformado por dos alumnos. De los grupos debe almacenarse: un código
 * autonumérico que comenzará en el 1, y los legajos de los dos alumnos que componen el grupo. Máximo: 50.
 * Se debe impedir ingresar legajos de alumnos inexistentes.
 * - Imprimir el listado de todos los alumnos almacenados en el sistema.
 * - Imprimir un listado de los grupos, mostrando el código y los nombres de los alumnos que lo componen.
*/



#include <iostream>
#include <string>

using namespace std;

const int MAX_ALUMNOS=100;
const int MAX_GRUPOS=50;

struct Alumno
{
    int legajo;
    string nombre;
    string email;
    long int telefono;
};

struct Grupo
{
    int codigo;
    int legajo1;
    int legajo2;
};


bool legajoExiste(const Alumno alumnos[], int dlA, int legajo){
    for (int i=0; i!=dlA; i++){
        if (alumnos[i].legajo==legajo)
            return true;
    }
    return false;
}


string buscarNombrePorLegajo(Alumno alumnos[], int dlA, int legajo){
    for (int i=0; i!=dlA; i++){
        if (alumnos[i].legajo==legajo)
            return alumnos[i].nombre;
    }
    return "";
}


void insertarOrdenado(Alumno alumnos[], int &dlA, Alumno alumno){
    int indice = 0;
    if (dlA < MAX_ALUMNOS){

        //Busco dónde insertarlo
        while (indice < dlA && alumnos[indice].legajo <= alumno.legajo)
            indice++;

        //Corrimiento
        for (int j=dlA; j!=indice; j--)
            alumnos[j] = alumnos[j-1];

        //Inserción
        alumnos[indice] = alumno;
        dlA++;
    }
}


void cargarAlumnos(Alumno alumnos[], int &dlA){
    Alumno alumno;
    cout << "Numero de legajo (-1 para cortar la carga): ";
    cin >> alumno.legajo;
    while (alumno.legajo!=-1 && dlA < MAX_ALUMNOS){
        if (legajoExiste(alumnos, dlA, alumno.legajo)){
            cout << "Ese legajo ya está cargado. Por favor, ingrese otro.\n";
        }
        else{
            cout << "Nombre: ";
            cin.ignore();
            getline(cin,alumno.nombre);
            cout << "Email: ";
            getline(cin,alumno.email);
            cout << "Numero de telefono: ";
            cin >> alumno.telefono;
            insertarOrdenado(alumnos,dlA,alumno);
        }
        cout << "Numero de legajo (-1 para cortar la carga): ";
        cin >> alumno.legajo;
    }
}


void imprimirAlumnos(Alumno alumnos[], int dlA){
    for (int i=0; i!=dlA; i++){
        cout << "Legajo: "<< alumnos[i].legajo << " - ";
        cout << "Nombre: "<< alumnos[i].nombre << " - ";
        cout << "Email: "<< alumnos[i].email << " - ";
        cout << "Telefono: "<< alumnos[i].telefono << endl;
        cout << " -------- \n";
    }
}


int leerLegajo(Alumno alumnos[], int dlA, int n){
    int legajo;
    do {
        cout << "Ingrese legajo de participante " << n << " (-1 para cortar): ";
        cin >> legajo;
    } while (!legajoExiste(alumnos, dlA, legajo) && legajo!=-1);
    return legajo;
}


void cargarGrupos(Grupo grupos[], int &dlG, Alumno alumnos[], int dlA){
    int ultElemento;
    Grupo grupo;
    grupo.legajo1=leerLegajo(alumnos, dlA, 1);
    while (grupo.legajo1 != -1) {
        grupo.legajo2=leerLegajo(alumnos, dlA, 2);
        if (dlG==0){
            grupo.codigo=1;
        }
        else{
            ultElemento=dlG-1;
            grupo.codigo=grupos[ultElemento].codigo+1;
        }

        if (dlG < MAX_GRUPOS){
            grupos[dlG]=grupo;
            dlG++;
            cout << "Grupo agregado exitosamente.\n\n";
            grupo.legajo1=leerLegajo(alumnos, dlA, 1);
        }
        else{
            cout << "No se puede agregar el grupo.\n\n";
            break;
        }
    }
}


void imprimirGrupos(Grupo grupos[], int dlG, Alumno alumnos[], int dlA){
    for (int i=0; i!=dlG; i++){
        cout << "Grupo " << grupos[i].codigo << endl;
        cout << "Alumno 1: " << buscarNombrePorLegajo(alumnos, dlA, grupos[i].legajo1) << endl;
        cout << "Alumno 2: " << buscarNombrePorLegajo(alumnos, dlA, grupos[i].legajo2) << endl;
        cout << "-----------";
    }
}


/*Carga de datos de prueba*/
void cargarDatosDePrueba(Alumno alumnos[], int &dlA, Grupo grupos[], int &dlG)
{
    Alumno alumno;
    alumno={14562, "Josefina Meza", "jmeza@universidad.com", 56723565};
    insertarOrdenado(alumnos,dlA,alumno);
    alumno={12684, "Manuel Moreira", "mmoreira@universidad.com", 43560056};
    insertarOrdenado(alumnos,dlA,alumno);
    alumno={13118, "Alejandro Gomez", "agomez@universidad.com", 64223053};
    insertarOrdenado(alumnos,dlA,alumno);
    alumno={11902, "Marisa Iriarte", "miriarte@universidad.com", 74534230};
    insertarOrdenado(alumnos,dlA,alumno);
    alumno={12938, "Esteban Iraola", "eiraola@universidad.com", 99182321};
    insertarOrdenado(alumnos,dlA,alumno);
    alumno={14109, "Lorena Juarez", "ljuarez@universidad.com", 23943566};
    insertarOrdenado(alumnos,dlA,alumno);
    alumno={15739, "Karina Alonso", "kalonso@universidad.com", 92304324};
    insertarOrdenado(alumnos,dlA,alumno);
    alumno={13486, "Luis Pereyra", "lpereyra@universidad.com", 83025348};
    insertarOrdenado(alumnos,dlA,alumno);

    grupos[0]={1, 14562, 12938};
    grupos[1]={2, 13486, 13118};
    grupos[2]={3, 12684, 11902};
    grupos[3]={4, 14109, 15739};
    dlG=4;
}



//INICIO DEL PROGRAMA
int main()
{
    Alumno alumnos[MAX_ALUMNOS];
    int dlA=0;
    Grupo grupos[MAX_GRUPOS];
    int dlG=0;

    cargarDatosDePrueba(alumnos, dlA, grupos, dlG);

    int opcion;
    do
    {
        cout << "***MENU***";
        cout << "\n1. Cargar alumnos";
        cout << "\n2. Imprimir datos completos de alumnos";
        cout << "\n3. Cargar grupos";
        cout << "\n4. Imprimir grupos (nombres de los integrantes)";
        cout << "\n0. Salir";
        cout << "\nSeleccione opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cargarAlumnos(alumnos, dlA);
            break;
        case 2:
            imprimirAlumnos(alumnos, dlA);
            break;
        case 3:
            cargarGrupos(grupos,dlG,alumnos,dlA);
            break;
        case 4:
            imprimirGrupos(grupos,dlG,alumnos,dlA);
            break;
        case 0:
            return 0;
        default:
            cout << "Opcion incorrecta. Seleccione nuevamente: ";
        }
    } while (opcion != 0);
}