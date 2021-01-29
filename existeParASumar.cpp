/*
Dado un arreglo de números ordenados de forma ascendente, hallar un par de ellos cuya suma coincida con otro número, también dado. 
Video explicativo: https://www.youtube.com/watch?v=nADemX9stHY
*/

#include <iostream>
#include <vector>
using namespace std;


bool existeParASumar(const vector<int> &numeros, int resultado) {
	int inferior = 0;
	int superior = numeros.size()-1;
	while (inferior < superior) {
		int s = numeros[inferior] + numeros[superior];
		if (s == resultado)
			return true;
		if (s < resultado)
		    inferior+=1;
		else
		    superior-=1;
	}
	return false;
}


int main() {
    vector<int> a={1, 2, 3, 9};
    if (existeParASumar(a, 8))
        cout << "existe" << endl;
    else
        cout << "no existe" << endl;   
    return 0;
}
