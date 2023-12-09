#include "Cake.h"
#include "CakeFactory.h"
#include "Stack.h"
#include "Subll.h"
#include "raylib.h"
#include <iostream>
using namespace std;


int main() {
  // Initialization

  CakeFactory obj;
  obj.addCake();
  obj.display();

  return 0;
}
