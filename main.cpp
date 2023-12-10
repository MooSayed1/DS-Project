#include "CakeFactory.h"
#include "menu/menu.h"
#include "menu/submenu.h"
// #include "stimulation.h"
#include <chrono>
#include <raylib.h>
#include <thread>
#include <unistd.h>

void displayOrders(const vector<Cake> &orders,CakeFactory mahdi);
enum MenuOption { ORDER_CAKE = 1, FACTORY_SIMULATION, DISPLAY_ORDERS, EXIT };

void simulateLoading() {
  size_t screenWidth = GetScreenWidth();
  size_t screenHeight = GetScreenHeight();

  // InitWindow(screenWidth, screenHeight, "Loading Line Animation");

  int loadingPercentage = 0;
  const int totalWidth = 500;
  int loadedWidth = static_cast<int>(totalWidth * (loadingPercentage / 100.0));

  SetTargetFPS(120);

  while (!WindowShouldClose() && loadingPercentage <= 100) {
    loadedWidth = static_cast<int>(totalWidth * (loadingPercentage / 100.0));

    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Draw loading bar outline
    DrawRectangle(screenWidth / 2 - totalWidth / 2, screenHeight / 2 - 30,
                  totalWidth, 30, LIGHTGRAY);

    // Draw loading bar progress
    DrawRectangle(screenWidth / 2 - totalWidth / 2, screenHeight / 2 - 30,
                  loadedWidth, 30, BLUE);

    // Draw loading text with larger font
    DrawText(TextFormat("%d%%", loadingPercentage), screenWidth / 2 - 30,
             screenHeight / 2 - 50, 30, BLACK);

    EndDrawing();

    // Simulate work
    std::this_thread::sleep_for(
        std::chrono::milliseconds(25)); // Make the animation twice as fast

    // Update loading progress
    loadingPercentage += 2; // Increase loading by 2% per iteration
  }

  // Print additional message after loading completes
  DrawText("Loaded Data Successfully",
           screenWidth / 2 - MeasureText("Loaded Data Successfully", 20) / 2,
           screenHeight / 2 + 20, 20, BLACK);
  EndDrawing();

  // Wait for 1 second
  std::this_thread::sleep_for(std::chrono::seconds(1));
}
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
        mahdi.addToWaitingQueue(ShapeInd, GlazingInd, FlavorInd, SprinkleInd,
                                0);
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
      displayOrders(orders,mahdi);
      break;
    }
  }

  CloseWindow();
  return 0;
}

void displayOrders(const vector<Cake> &orders,CakeFactory mahdi) {
  size_t screenWidth = GetScreenWidth();
  size_t screenHeight = GetScreenHeight();

  SetTargetFPS(60);

  // Main game loop
  while (!WindowShouldClose()) {
    // Update

    // Draw
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText("Cake Orders:", 20, 20, 20, DARKGRAY);

    int yPos = 60; // Starting Y position for orders

    for (const auto &cake : orders) {

      string orderDetails =
          "ID: " + to_string(cake.getId()) +
          " Shape: " + mahdi.getShapeString(cake.getShape()) +
          " Glazing: " + mahdi.getGlazingString(cake.getGlazing()) +
          " Flavor: " + mahdi.getFlavorString(cake.getFlavor()) +
          " Sprinkles: " + mahdi.getSprinklesString(cake.getSprinkles());
      DrawText(orderDetails.c_str(), 20, yPos, 20, DARKGRAY);
      yPos += 30; // Increase Y position for the next order
    }

    EndDrawing();

    // Return control to the main loop
    if (IsKeyPressed(KEY_ENTER)) {
      break;
    }
  }
}
