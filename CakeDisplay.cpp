
// CakeDisplay.cpp
#include "CakeDisplay.h"
#include "Cake.h"

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


void displayOrders(const std::vector<Cake> &orders) {
    size_t screenWidth = GetScreenWidth();
    size_t screenHeight = GetScreenHeight();

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Update

        // Draw
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Cake Orders:", 20, 20, 20, DARKGRAY);

        // Create a rectangle for all orders
        Rectangle ordersRect = {20, 60, 500, static_cast<float>(30 * orders.size())};

        // Draw a filled rectangle as the background for all orders
        DrawRectangleRec(ordersRect, BLUE);

        // Move Y position for the first order
        int yPos = static_cast<int>(ordersRect.y + 5);

        cakeMap mapOfMaps;

        for (const auto &cake : orders) {
            // Draw order details with larger font and white color
            string orderDetails =
                "ID: " + to_string(cake.getId()) +
                " Shape: " + mapOfMaps.shapeMap[cake.getShape()] +
                " Glazing: " + mapOfMaps.glazingMap[cake.getGlazing()] +
                " Flavor: " + mapOfMaps.flavorMap[cake.getFlavor()] +
                " Sprinkles: " + mapOfMaps.sprinklesMap[cake.getSprinkles()];

            DrawText(orderDetails.c_str(), ordersRect.x + 10, yPos, 20, WHITE);

            // Move Y position for the next order
            yPos += 30; // Increase Y position and add some space between orders
        }

        EndDrawing();

        // Return control to the main loop
        if (IsKeyPressed(KEY_ENTER)) {
            break;
        }
    }
}
