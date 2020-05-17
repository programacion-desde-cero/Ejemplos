/* ----------------
/* Este ejemplo corresponde al video sobre punteros: https://www.youtube.com/watch?v=s8T7cPnYrz0
/* Ejecución del código paso a paso: http://pythontutor.com/cpp.html#code=%23include%20%3Ciostream%3E%0A%23include%20%3Cstring%3E%0Ausing%20namespace%20std%3B%0A%0Aint%20main%28%29%20%7B%0A%20%20string%20saludo%20%3D%20%22hola%22%3B%0A%20%20string*%20p%20%3D%20%26saludo%3B%0A%20%20cout%20%3C%3C%20p%20%3C%3C%20endl%3B%0A%20%20cout%20%3C%3C%20*p%20%3C%3C%20endl%3B%0A%20%20*p%20%3D%20%22amo%20programar%22%3B%0A%20%20cout%20%3C%3C%20*p%20%3C%3C%20endl%3B%0A%20%20cout%20%3C%3C%20saludo%20%3C%3C%20endl%3B%0A%20%20%0A%20%20return%200%3B%0A%7D&curInstr=0&mode=display&origin=opt-frontend.js&py=cpp&rawInputLstJSON=%5B%5D
------------------- */

#include <iostream>
#include <string>
using namespace std;

int main() {
  string saludo = "hola";
  string* p = &saludo;
  cout << p << endl;
  cout << *p << endl;
  *p = "amo programar";
  cout << *p << endl;
  cout << saludo << endl;
  
  return 0;
}
