#include "CakeFactory.h"
#include "menu/menu.h"
#include "menu/submenu.h"
#include "stimulation.h"
#include <raylib.h>

enum MenuOption { ORDER_CAKE = 1, FACTORY_SIMULATION, EXIT };

int main() {
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  size_t screenWidth = GetScreenWidth();
  size_t screenHeight = GetScreenHeight();
  InitWindow(screenWidth, screenHeight, "Raylib Menu Example");
  CakeFactory mahdi;


  Menu obj(screenWidth, screenHeight);
  obj.menu_head("Comfy Purble Factory");
  obj.add("Order a Cake", ORDER_CAKE);
  obj.add("Factory Stimulation", FACTORY_SIMULATION);
  obj.add("Exit", EXIT);

  int choice = -1;
  while (choice != EXIT) {
    choice = obj.display();

      int ShapeInd=0,GlazingInd=0,FlavorInd=0,SprinkleInd=0;
    switch (choice) {
    case ORDER_CAKE:
      ShapeInd=0,GlazingInd=0,FlavorInd=0,SprinkleInd=0;
      if (SubMenu(ShapeInd,GlazingInd,FlavorInd,SprinkleInd)){
        mahdi.addToWaitingQueue(static_cast<CakeShape>(ShapeInd),static_cast<CakeGlazing>(GlazingInd),static_cast<CakeFlavor>(FlavorInd),static_cast<CakeSprinkles>(SprinkleInd), 0);
      }
      cout<<ShapeInd<<" "<<GlazingInd<<" "<<FlavorInd<<" "<<SprinkleInd;
      // Handle order a cake

      break;
    case FACTORY_SIMULATION:

      stimulation(mahdi.GiveMeCake());
      // Handle factory stimulation
      break;
    }
  }

  CloseWindow();
  return 0;
}
