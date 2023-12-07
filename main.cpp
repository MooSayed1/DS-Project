#include "Cake.h"
#include "Subll.h"
#include "Stack.h"
#include <iostream>
using namespace std;

int main() {
  Subll<int>s;
  s.push(5);
  s.push(3);
  s.push(8);
  s.push(8);
  s.push(11);
  s.push(11);
  s.push(11);
  s.push(11);
  s.print();
  return 0;
}
