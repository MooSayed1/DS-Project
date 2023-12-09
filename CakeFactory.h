
#ifndef CAKEFACTORY_H
#define CAKEFACTORY_H
#include "Cake.h"
#include "Stack.h"
#include "Subll.h"
#include <iostream>
using namespace std;
class CakeFactory {
private:
  Subll<Cake>watingQueue;
  Stack<string> stk;
  Subll<Stack<string>> fact;

public:
  // Getter function
  CakeFactory(){}
  void display(){fact.print();}
  void addCake() {
  Stack<string> stk;
    fact.push(stk);
    fact.addData();
  }
  //code
};
#endif //
