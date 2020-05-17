/* ----------------
/* Este ejemplo corresponde al video sobre punteros: https://www.youtube.com/watch?v=s8T7cPnYrz0
/* Ejecución del código paso a paso: http://pythontutor.com/visualize.html#code=%23include%20%3Ciostream%3E%0A%23include%20%3Cstring%3E%0Ausing%20namespace%20std%3B%0A%0Aint%20main%28%29%20%7B%0A%20%20int*%20n%20%3D%20new%20int%3B%0A%20%20*n%20%3D%2018%3B%0A%20%20cout%20%3C%3C%20sizeof%28*n%29%20%3C%3C%20endl%3B%0A%20%20cout%20%3C%3C%20sizeof%28n%29%20%3C%3C%20endl%3B%20%20%0A%20%20char*%20c%20%3D%20new%20char%3B%0A%20%20*c%20%3D%20'x'%3B%0A%20%20cout%20%3C%3C%20sizeof%28*c%29%20%3C%3C%20endl%3B%0A%20%20cout%20%3C%3C%20sizeof%28c%29%20%3C%3C%20endl%3B%0A%20%20%0A%20%20return%200%3B%0A%7D&cumulative=false&curInstr=9&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=cpp&rawInputLstJSON=%5B%5D&textReferences=false
------------------- */

#include <iostream>
#include <string>
using namespace std;

int main() {
  int* n = new int;
  *n = 18;
  cout << sizeof(*n) << endl;
  cout << sizeof(n) << endl;  
  char* c = new char;
  *c = 'x';
  cout << sizeof(*c) << endl;
  cout << sizeof(c) << endl;
  
  return 0;
}
