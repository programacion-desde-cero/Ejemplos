#include <iostream>
#include <vector>
using namespace std;

int sumaDigitos(int num){
   int suma=0;
   while (num!=0){
       suma+=num%10;
       num=num/10;
   }
   return suma;
}

void insertarOrdenado(vector<int> &ordenados, int n){
   auto p = begin(ordenados);
   for (; p != end(ordenados); p++) {
       if (sumaDigitos(*p) > sumaDigitos(n)) {
           ordenados.insert(p, n);
           break;
       }
   }
   if (p == end(ordenados)) {
       ordenados.push_back(n);
   }
}

vector<int> ordenadosSumatoriaDigitos(int arreglo[], int dl){
   vector<int> ordenados;
   for (int i=0; i<dl; i++){
       insertarOrdenado(ordenados, arreglo[i]);
   }
   return ordenados;
}


int main(){
   int arreglo[4] = {734, 1938, 20111, 96};
   int dl=4;
   for (auto numero : ordenadosSumatoriaDigitos(arreglo, dl))
       cout << numero << " ";
   cout << endl;
   return 0;
}