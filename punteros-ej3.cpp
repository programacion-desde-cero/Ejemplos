/* ----------------
/* Este ejemplo corresponde al video sobre punteros: https://www.youtube.com/watch?v=s8T7cPnYrz0
/* Ejecución del código paso a paso: http://pythontutor.com/visualize.html#code=%23include%20%3Ciostream%3E%0Ausing%20namespace%20std%3B%0A%0Avoid%20funcion%28int*%20x%29%20%7B%0A%20%20%20*x%20%3D%2015%3B%20%20%0A%20%20%20return%3B%0A%7D%0A%0Aint%20main%28%29%20%7B%0A%20%20int%20a%20%3D%202%3B%0A%20%20funcion%28%26a%29%3B%0A%20%20cout%20%3C%3C%20a%20%3C%3C%20endl%3B%0A%0A%20%20return%200%3B%0A%7D&cumulative=false&curInstr=0&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=cpp&rawInputLstJSON=%5B%5D&textReferences=false
------------------- */

#include <iostream>
using namespace std;

void funcion(int* x) {
   *x = 15;  
   return;
}

int main() {
  int a = 2;
  funcion(&a);
  cout << a << endl;

  return 0;
}
