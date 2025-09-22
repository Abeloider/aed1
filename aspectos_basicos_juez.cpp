#include <iostream>
using namespace std;

int main (void)
{
  int numcasos, N, M;
  char L;
  cin >> numcasos;
  int i=0; 

  while (i<numcasos) {
    cin >> L >> N >> M;
    if (L == 's') {
      cout << N+M << endl; 
    }
    else if (L == 'r') {
      cout << N-M << endl; 
    } 
    else if (L == 'p') {
      cout << N*M << endl; 
    }
    i++;
   }
  return 0;
}