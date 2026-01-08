#include "Interprete.h"
#include <iostream>

using namespace std;

int main() {
   string comando;
   while (cin >> comando && comando!="exit")
      Interprete(comando);
}
