#include "Cake.h"
#include "sub-list.h"
#include "Queue.h"
#include "Stack.h"
#include <iostream>
using namespace std;

int main() {
  // Creating instances of the Dog class
  Subll<Queue<Stack<int>>> wtf;
  Queue<Stack<int>> wtf2;

  wtf.pushBack(wtf2);

  wtf.pushBack(wtf2);
  wtf.pushBack(wtf2);
  wtf.pushBack(wtf2);
  wtf.pushBack(wtf2);
  wtf.pushBack(wtf2);
  cout << "WTF" << endl;
  return 0;
}
