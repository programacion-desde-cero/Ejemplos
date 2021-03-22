// Código correspondiente al siguiente video: https://youtu.be/TpaOVCjBAI8

#include <iostream>
#include <string>
#include <map>
using namespace std;


int romanoAInt(string romano) {
    map<char, int> equivalencias;
    equivalencias['M'] = 1000;
    equivalencias['D'] = 500;
    equivalencias['C'] = 100;
    equivalencias['L'] = 50;
    equivalencias['X'] = 10;
    equivalencias['V'] = 5;
    equivalencias['I'] = 1;
    int respuesta = 0;
    for (int i = 0; i < romano.length() - 1; ++i)
    {
        if (equivalencias[romano[i]] < equivalencias[romano[i+1]])
            respuesta -= equivalencias[romano[i]];
        else
            respuesta += equivalencias[romano[i]];
    }
    respuesta += equivalencias[romano[romano.length()-1]];
    return respuesta;
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Error: el programa " << argv[0] << " debe ejecutarse con un argumento.\n";
        return -1;
    }
    else {
        cout << "El decimal equivalente es: " << romanoAInt(argv[1]);
        return 0;
    }
}
