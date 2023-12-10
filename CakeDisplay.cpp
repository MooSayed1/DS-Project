
// CakeDisplay.cpp
#include "CakeDisplay.h"
#include "Cake.h"
#include <raylib.h>

        cakeMap mapOfMaps;
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

// void displayOrders(const std::vector<Cake> &orders) {
//     // ... (copy the content of the original displayOrders function here)
//   size_t screenWidth = GetScreenWidth();
//   size_t screenHeight = GetScreenHeight();
//
//   SetTargetFPS(60);
//
//   // Main game loop
//   while (!WindowShouldClose()) {
//     // Update
//
//     // Draw
//     BeginDrawing();
//
//     ClearBackground(RAYWHITE);
//
//     DrawText("Cake Orders:", 20, 20, 20, DARKGRAY);
//
//     int yPos = 60; // Starting Y position for orders
//     cakeMap mapOfMaps; 
//     for (const auto &cake : orders) {
//
//       string orderDetails =
//           "ID: " + to_string(cake.getId()) +
//           " Shape: " + mapOfMaps.shapeMap[cake.getShape()]+
//           " Glazing: " + mapOfMaps.glazingMap[cake.getGlazing()] +
//           " Flavor: " +mapOfMaps.flavorMap[cake.getFlavor()] +
//           " Sprinkles: " + mapOfMaps.sprinklesMap[cake.getSprinkles()];
//       cout<<orderDetails<<"i'm a detail"<<endl;
//       DrawText(orderDetails.c_str(), 20, yPos, 20, DARKGRAY);
//       yPos += 30; // Increase Y position for the next order
//     }
//
//     EndDrawing();
//
//     // Return control to the main loop
//     if (IsKeyPressed(KEY_ENTER)) {
//       break;
//     }
//   }
// }





class CakeTable {
public:
    CakeTable(int screenWidth, int screenHeight, const char * windowTitle)
        : screenWidth(screenWidth), screenHeight(screenHeight) {
    }

    ~CakeTable() {
        CloseWindow();
    }

    void addCake(int id, int shape, int flavor, int glazing, int sprinkles) {
        Cake cake( id, shape, flavor, glazing, sprinkles );
        cakes.push_back(cake);
    }

void drawTable() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Draw cakes
    for (size_t i = 0; i < cakes.size(); i++) {
        DrawText(TextFormat("%d", cakes[i].getId()), (screenWidth / 7.f), 40 + i * 30 - scrollY, 20, RED);
        DrawText(mapOfMaps.shapeMap[cakes[i].getShape()].c_str(), 2 * (screenWidth / 7.f), 40 + i * 30 - scrollY, 20, GREEN);
        DrawText(mapOfMaps.shapeMap[cakes[i].getFlavor()].c_str(), 3 * (screenWidth / 7.f), 40 + i * 30 - scrollY, 20, BLUE);
        DrawText(mapOfMaps.shapeMap[cakes[i].getGlazing()].c_str(), 4 * (screenWidth / 7.f), 40 + i * 30 - scrollY, 20, PURPLE);
        DrawText(mapOfMaps.shapeMap[cakes[i].getSprinkles()].c_str(), 5 * (screenWidth / 7.f), 40 + i * 30 - scrollY, 20, ORANGE);
    }
    DrawRectangle(0, 0, screenWidth, 30, RAYWHITE);
    // Draw table headers
    DrawText("ID", screenWidth / 7.f, 10, 20, RED);
    DrawText("Shape", 2 * (screenWidth / 7.f), 10, 20, GREEN);
    DrawText("Flavor", 3 * (screenWidth / 7.f), 10, 20, BLUE);
    DrawText("Glazing", 4 * (screenWidth / 7.f), 10, 20, PURPLE);
    DrawText("Sprinkles", 5 * (screenWidth / 7.f), 10, 20, ORANGE);


    EndDrawing();

    // Handle scrolling
    float totalContentHeight = static_cast<float>(cakes.size() * 35);

    if ((IsKeyDown(KEY_DOWN)||IsKeyDown(KEY_K))&& scrollY <= totalContentHeight - screenHeight) {
        scrollY += 10.f;
    }
    if ((IsKeyDown(KEY_UP)||IsKeyDown(KEY_J)) && scrollY - 10 >= 0) {
        scrollY -= 10.f;
    }
}


private:
    int screenWidth;
    int screenHeight;
    std::vector<Cake> cakes;
    int scrollY = 0;
};


void displayOrders(const std::vector<Cake> &orders) {
    const int screenWidth = 1366;
    const int screenHeight = 768;

    CakeTable cakeTable(screenWidth, screenHeight, "Cake Table");
    for (auto & order:orders) {
    cakeTable.addCake( order.getShape(), order.getFlavor(), order.getGlazing(), order.getSprinkles(),order.getId());
    }

    while (!WindowShouldClose()) {
        cakeTable.drawTable();
        if (IsKeyPressed(KEY_ENTER)) {
            break;
        }
    }




}
