#include "CakeDisplay.h"
#include "CakeFactory.h"
#include "LoadingScreen.h"
#include "menu/menu.h"
#include "menu/submenu.h"
#include "simulation.h"
#include <raylib.h>
#include <unistd.h>

enum MenuOption { ORDER_CAKE = 1, FACTORY_SIMULATION, DISPLAY_ORDERS, EXIT };

int main() {
  LoadingScreen load;
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  size_t screenWidth = GetScreenWidth();
  size_t screenHeight = GetScreenHeight();
  InitWindow(screenWidth, screenHeight, "Comfy Purble Factory");

  // load.Run();
  CakeFactory mahdi;
  Menu obj(screenWidth, screenHeight);
  obj.menu_head("Comfy Purble Factory");
  obj.add("Order a Cake", ORDER_CAKE);
  obj.add("Factory Stimulation", FACTORY_SIMULATION);
  obj.add("Display All Orders", DISPLAY_ORDERS);
  obj.add("Exit", EXIT);

  int choice = -1;
  vector<Cake> test;

  while (choice != EXIT) {
    choice = obj.display();

    int ShapeInd = 0, GlazingInd = 0, FlavorInd = 0, SprinkleInd = 0;
    switch (choice) {
    case ORDER_CAKE:
      ShapeInd = 0, GlazingInd = 0, FlavorInd = 0, SprinkleInd = 0;
      if (SubMenu(ShapeInd, GlazingInd, FlavorInd, SprinkleInd)) {
        mahdi.addToWaitingQueue(ShapeInd, GlazingInd, FlavorInd, SprinkleInd,
                                0);
        // simulateLoading();
      }
      // Handle order a cake
      break;
    case FACTORY_SIMULATION:

      simulation(mahdi.GiveMeCake());
      // Handle factory stimulation
      break;
    case DISPLAY_ORDERS:
      // Retrieve orders and display them
      // displayOrders(mahdi.GiveMeCake(),mahdi);
      //
      break;
      SetConfigFlags(FLAG_WINDOW_RESIZABLE);
      size_t screenWidth = GetScreenWidth();
      size_t screenHeight = GetScreenHeight();
      InitWindow(screenWidth, screenHeight, "Raylib Menu Example");

      // Show loading screen
      LoadingScreen load;
       load.Run();           // --> Loading Screen But Need To Handel

      CakeFactory mahdi;
      Menu obj(screenWidth, screenHeight);
      obj.menu_head("Comfy Purble Factory");
      obj.add("Order a Cake", ORDER_CAKE);
      obj.add("Factory Stimulation", FACTORY_SIMULATION);
      obj.add("Display All Orders", DISPLAY_ORDERS);
      obj.add("Exit", EXIT);

      int choice = -1;
      while (choice != EXIT) {
        choice = obj.display();

        int ShapeInd = 0, GlazingInd = 0, FlavorInd = 0, SprinkleInd = 0;
        switch (choice) {
        case ORDER_CAKE:
          ShapeInd = 0, GlazingInd = 0, FlavorInd = 0, SprinkleInd = 0;
          if (SubMenu(ShapeInd, GlazingInd, FlavorInd, SprinkleInd)) {
            mahdi.addToWaitingQueue(ShapeInd, GlazingInd, FlavorInd,
                                    SprinkleInd, 0);
            simulateLoading();
          }
          // Handle order a cake
          break;
        case FACTORY_SIMULATION:
          // stimulation(mahdi.GiveMeCake());
          // Handle factory stimulation
          break;
        case DISPLAY_ORDERS:
          // Retrieve orders and display them
          vector<Cake> orders = mahdi.GiveMeCake();
          displayOrders(orders, mahdi);
          break;
        }
      }

      CloseWindow();
      return 0;
    }
  }
}
