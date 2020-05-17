/* ----------------
/* Este ejemplo corresponde al video sobre punteros: https://www.youtube.com/watch?v=s8T7cPnYrz0
/* Ejecución del código paso a paso: http://pythontutor.com/cpp.html#code=%23include%20%3Ciostream%3E%0Ausing%20namespace%20std%3B%0A%0Aint%20main%28%29%20%7B%0A%20%20int*%20a%20%3D%20new%20int%287%29%3B%0A%20%20int*%20b%20%3D%20a%3B%0A%20%20*b%20%3D%203%3B%0A%20%20cout%20%3C%3C%20*a%20%3C%3C%20endl%3B%0A%0A%20%20return%200%3B%0A%7D&curInstr=0&mode=display&origin=opt-frontend.js&py=cpp&rawInputLstJSON=%5B%5D
------------------- */

#include <iostream>
using namespace std;

int main() {
  int* a = new int(7);
  int* b = a;
  *b = 3;
  cout << *a << endl;

  return 0;
}
