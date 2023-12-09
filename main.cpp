#include<iostream>
#include "Subll.h"
#include "CakeFactory.h"
#include "Stack.h"
#include "menu/menu.h"
#include "menu/submenu.h"
#include <raylib.h>

enum MenuOption { ORDER_CAKE = 1, FACTORY_SIMULATION, EXIT };

int main() {
  // SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  // size_t screenWidth = GetScreenWidth();
  // size_t screenHeight = GetScreenHeight();
  // InitWindow(screenWidth, screenHeight, "Raylib Menu Example");
  //
  // Menu obj(screenWidth, screenHeight);
  // obj.menu_head("Comfy Purble Factory");
  // obj.add("Order a Cake", ORDER_CAKE);
  // obj.add("Factory Stimulation", FACTORY_SIMULATION);
  // obj.add("Exit", EXIT);
  //
  // int choice = -1;
  // while (choice != EXIT) {
  //   choice = obj.display();
  //
  //   switch (choice) {
  //   case ORDER_CAKE:
  //     SubMenu(1);
  //     // Handle order a cake
  //     break;
  //   case FACTORY_SIMULATION:
  //     // Handle factory stimulation
  //     break;
  //   }
  // }
  //
  // CloseWindow();
  CakeFactory obj;
  obj.simulateQueue(3);
  return 0;
}
