/* ----------------
/* Este ejemplo corresponde al video sobre punteros: https://www.youtube.com/watch?v=s8T7cPnYrz0
/* Ejecución del código paso a paso: http://pythontutor.com/visualize.html#code=%23include%20%3Ciostream%3E%0Ausing%20namespace%20std%3B%0A%0Aint%20main%28%29%20%7B%0A%20%20int*%20y%20%3D%20new%20int%3B%0A%20%20*y%20%3D%2040%3B%0A%20%20cout%20%3C%3C%20y%20%3C%3C%20endl%3B%0A%20%20y%20%3D%20new%20int%3B%0A%20%20cout%20%3C%3C%20y%20%3C%3C%20endl%3B%0A%0A%20%20return%200%3B%0A%7D&cumulative=false&curInstr=0&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=cpp&rawInputLstJSON=%5B%5D&testCasesJSON=%5B%22%5Cn%23%20assert%20%3Ctest%20condition%3E%22%5D&textReferences=false
------------------- */

#include <iostream>
using namespace std;

int main() {
  int* y = new int;
  *y = 40;
  cout << y << endl;
  y = new int;
  cout << y << endl;

  return 0;
}
