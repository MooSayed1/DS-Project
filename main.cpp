#include "Cake.h"
#include "Subll.h"
#include "Stack.h"
#include <iostream>
using namespace std;

int main() {
  Subll<Stack<string>>s;
  s.push(5);
  s.push(3);
  s.push(8);
  s.push(8);
  s.push(11);
  s.push(11);
  s.push(11);
  s.push(11);
  s.push(24);
  s.pobFront();
  s.pobFront();
  s.pobFront();
  s.pobFront();
  s.pobFront();
  cout<<"Mohamed"<<endl;
  
  s.print();
  return 0;
}
