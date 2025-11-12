#include <iostream>
#include "005.h" 
using namespace std;

int main() {
   string comando;
   while (cin >> comando && comando!="exit")
      Interprete(comando); 
}

