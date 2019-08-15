//Explicación: https://youtu.be/Sgp_7c0G48k
#include <iostream>
#include <string>
using namespace std;

const int MAX=500;

struct t_producto {
    int codigo;
    string descripcion;
    double precio;
    int stock;
};


int cargarProductos(t_producto productos[], int &dimension)
{
    if (dimension==MAX)
        return -1;
    else
    {
        int cod;
        cout << "CODIGO: (0 para finalizar la carga)";
        cin >> cod;
        while (cod != 0)
        {
            productos[dimension].codigo=cod;
            cin.ignore();
            cout << "\nDESCRIPCIÓN: ";
            getline(cin,productos[dimension].descripcion);
            cout << "\nPRECIO: $";
            cin >> productos[dimension].precio;
            cout << "\nSTOCK: $";
            cin >> productos[dimension].stock;
            dimension++;

            cout << "CODIGO: (0 para finalizar la carga)";
            cin >> cod;
        }
        return 0;
    }
}



void imprimirListado(t_producto productos[], int dimension)
{
    for (int i=0; i<dimension; i++)
    {
        cout << "CODIGO: " << productos[i].codigo << "\t";
        cout << "DESCRIPCION: " << productos[i].descripcion << "\t";
        cout << "PRECIO: " << productos[i].precio << "\t";
        cout << "STOCK: " << productos[i].stock << endl;
        cout << "------------" << endl;
    }
}



int main ()
{
    t_producto productos[MAX];
    int dimension_productos = 0;

    int opcion;
    do
    {
        cout << "MENU PRINCIPAL - Elija opción" << endl;
        cout << "1: Cargar productos" << endl;
        cout << "2: Imprimir listado" << endl;
        cout << "3: Salir" << endl;
        cin >> opcion;
        cin.ignore();
        switch (opcion)
        {
        case 1:
            if (cargarProductos(productos, dimension_productos)==-1)
                cout << "No hay espacio en memoria" << endl;
            break;
        case 2:
            imprimirListado(productos, dimension_productos);
            break;
        case 3:
            return 0;
        default:
            cout << "Seleccione opción válida" << endl;
        }
    } while (opcion != 3);
}