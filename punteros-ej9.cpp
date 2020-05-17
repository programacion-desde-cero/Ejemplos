/* ----------------
/* Este ejemplo corresponde al video sobre punteros: https://www.youtube.com/watch?v=s8T7cPnYrz0
/* Ejecución del código paso a paso: http://pythontutor.com/visualize.html#code=%23include%20%3Ciostream%3E%0Ausing%20namespace%20std%3B%0A%0Avoid%20funcion%28int*%20x%29%20%7B%0A%20%20delete%20x%3B%0A%7D%0A%0A%0Aint%20main%28%29%20%7B%0A%20%20int*%20z%20%3D%20new%20int%285%29%3B%0A%20%20funcion%28z%29%3B%0A%20%20cout%20%3C%3C%20*z%3B%0A%0A%20%20return%200%3B%0A%7D&cumulative=false&curInstr=0&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=cpp&rawInputLstJSON=%5B%5D&textReferences=false
------------------- */

#include <iostream>
using namespace std;

void funcion(int* x) {
  delete x;
}


int main() {
  int* z = new int(5);
  funcion(z);
  cout << *z;

  return 0;
}
