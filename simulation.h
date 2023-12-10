#include "Cake.h"
#include <algorithm>
#include <raylib.h>
#include <string>
#include <vector>

#define PLAY_SCREEN_WIDTH 600
#define PLAY_SCREEN_HEIGHT 600
inline void simulation(std::vector<Cake> v) {
  // Set up the window
  int numSections = 15;
  float loadingPercentage = 0;

  cakeMap mapOfMaps;

  bool AutoAnim = 0;
  int start = std::min(numSections - (int)(int)v.size(), numSections + 4);
  int beg = start;

  double startTime = GetTime(); // Get the initial time

  while (!WindowShouldClose()) {
    BeginDrawing();

    // Clear the screen
    ClearBackground(RAYWHITE);

    // Draw the cake ingredients
    DrawText("Cakes Conveyor:", 10, 10, 20, BLACK);

    // Define cake ingredient positions
    Rectangle shapeRect = {50, 300, 100, 50};
    Rectangle flavorRect = {250, 300, 100, 50};
    Rectangle glazingRect = {450, 300, 100, 50};
    Rectangle sprinklesRect = {650, 300, 100, 50};
    // Add more ingredients as needed
    string Shape = "Shape: ";
    string Flavor = "Flavor: ";
    string Glazing = "Glazing: ";
    string Sprinkles =
        "Sprinkles: " + to_string(beg < (start + 4 + (int)(int)v.size()));

    if (beg > start && beg < start + (int)v.size() + 1)
      Shape += mapOfMaps.shapeMap[v[numSections - beg].getShape()];
    if (beg > start + 1 && beg < start + (int)v.size() + 2)
      Flavor += mapOfMaps.flavorMap[v[numSections - beg + 1].getFlavor()];
    if (beg > start + 2 && beg < start + (int)v.size() + 3)
      Glazing += mapOfMaps.glazingMap[v[numSections - beg + 2].getGlazing()];
    if (beg > start + 3 && beg < start + (int)v.size() + 4) {
      Sprinkles +=
          mapOfMaps.sprinklesMap[v[numSections - beg + 3].getSprinkles()];
    }
    DrawText(Shape.c_str(), shapeRect.x, shapeRect.y - 20, 20, BLACK);
    DrawText(Flavor.c_str(), flavorRect.x, flavorRect.y - 20, 20, BLACK);
    DrawText(Glazing.c_str(), glazingRect.x, glazingRect.y - 20, 20, BLACK);
    DrawText(Sprinkles.c_str(), sprinklesRect.x, sprinklesRect.y - 20, 20,
             BLACK);
    // Print steps for additional ingredients

    // Draw rectangles around the cake ingredients
    DrawRectangleLinesEx(shapeRect, 2, RED);
    DrawRectangleLinesEx(flavorRect, 2, PINK);
    DrawRectangleLinesEx(glazingRect, 2, GREEN);
    DrawRectangleLinesEx(sprinklesRect, 2, BLACK);

    Rectangle overallRectangle = {100, 100, 1000, 50};
    DrawRectangleLinesEx(overallRectangle, 2, BLACK);

    float sectionWidth = overallRectangle.width / numSections;

    for (int i = 1; i < numSections; i++) {
      float sectionX = overallRectangle.x + i * sectionWidth;
      DrawLineV(
          (Vector2){sectionX, overallRectangle.y},
          (Vector2){sectionX, overallRectangle.y + overallRectangle.height},
          RED);
    }
    for (int i = beg + 1; i <= numSections; i++) {
      float sectionX = overallRectangle.x + i * sectionWidth;

      float sectionCenterX = sectionX - sectionWidth / 1.6f;
      if (i > 0)
        DrawText(TextFormat("%d", v[i - 1 - beg].getId()), sectionCenterX,
                 overallRectangle.y + overallRectangle.height / 2 - 10, 20,
                 BLACK);
    }

    // Print a number inside each rectangle
    if ((int)v.size() > numSections - beg && numSections - beg >= 0) {
      DrawText(std::to_string(v[numSections - beg].getId()).c_str(),
               shapeRect.x + 10, shapeRect.y + 10, 20, BLACK);
    }
    if ((int)v.size() > numSections - beg + 1 && numSections - beg + 1 >= 0) {
      DrawText(std::to_string(v[numSections - beg + 1].getId()).c_str(),
               flavorRect.x + 10, flavorRect.y + 10, 20, BLACK);
    }
    if ((int)v.size() > numSections - beg + 2 && numSections - beg + 2 >= 0) {
      DrawText(std::to_string(v[numSections - beg + 2].getId()).c_str(),
               glazingRect.x + 10, glazingRect.y + 10, 20, BLACK);
    }
    if ((int)v.size() > numSections - beg + 3 && numSections - beg + 3 >= 0) {
      DrawText(std::to_string(v[numSections - beg + 3].getId()).c_str(),
               sprinklesRect.x + 10, sprinklesRect.y + 10, 20, BLACK);
    }

    Rectangle descRect = {900, 250, 300, 200};
    Shape = "Shape: ";
    Flavor = "Flavor: ";
    Glazing = "Glazing: ";
    Sprinkles = "Sprinkles: ";
    if (beg <= start + (int)v.size() + 4 && beg > start + 4) {

      Shape += mapOfMaps.shapeMap[v[numSections - beg + 4].getShape()];
      Flavor += mapOfMaps.flavorMap[v[numSections - beg + 4].getFlavor()];
      Glazing += mapOfMaps.glazingMap[v[numSections - beg + 4].getGlazing()];
      Sprinkles +=
          mapOfMaps.sprinklesMap[v[numSections - beg + 4].getSprinkles()];
    }

    DrawRectangleLinesEx(descRect, 2, BLACK);
    DrawText("Product:", descRect.x + 10, descRect.y + 10, 20, PINK);
    DrawText(Shape.c_str(), descRect.x + 20, descRect.y + 30, 20, PINK);
    DrawText(Flavor.c_str(), descRect.x + 20, descRect.y + 50, 20, PINK);
    DrawText(Glazing.c_str(), descRect.x + 20, descRect.y + 70, 20, PINK);
    DrawText(Sprinkles.c_str(), descRect.x + 20, descRect.y + 90, 20, PINK);

    if (IsKeyPressed(KEY_RIGHT) && beg < start + 4 + (int)v.size()) {
      beg++;
      loadingPercentage += ((float)1 / (4 + (int)v.size()) * 100);

    } else if (IsKeyPressed(KEY_LEFT) && beg > start) {
      beg--;
      loadingPercentage -= ((float)1 / (4 + (int)v.size()) * 100);
    } else if (IsKeyPressed(KEY_S)) {
      AutoAnim = !AutoAnim;
    }
    if (AutoAnim && beg < start + 4 + (int)v.size()) {
      double currentTime = GetTime();
      double elapsedTime = currentTime - startTime;
      if (elapsedTime >= 1.0) {
        beg++;
        startTime = currentTime;
        loadingPercentage += ((float)1 / (4 + (int)v.size()) * 100);
      }
    }
    // Check if the mouse is over the play button
    bool mouseOverPlayButton = CheckCollisionPointRec(
        GetMousePosition(),
        (Rectangle){PLAY_SCREEN_WIDTH - 20, PLAY_SCREEN_HEIGHT - 50, 40, 40});

    // Draw play button
    DrawRectangle(PLAY_SCREEN_WIDTH - 20, PLAY_SCREEN_HEIGHT - 50, 40, 40,
                  mouseOverPlayButton ? LIGHTGRAY : GRAY);

    if (AutoAnim) {
      DrawTriangle(
          (Vector2){PLAY_SCREEN_WIDTH - 8, PLAY_SCREEN_HEIGHT - 30 - 8},
          (Vector2){PLAY_SCREEN_WIDTH - 8, PLAY_SCREEN_HEIGHT - 30 + 8},
          (Vector2){PLAY_SCREEN_WIDTH + 8, PLAY_SCREEN_HEIGHT - 30},
          mouseOverPlayButton ? RED : MAROON);
    } else {
      DrawTriangle(
          (Vector2){PLAY_SCREEN_WIDTH - 8, PLAY_SCREEN_HEIGHT - 30 - 8},
          (Vector2){PLAY_SCREEN_WIDTH - 8, PLAY_SCREEN_HEIGHT - 30 + 8},
          (Vector2){PLAY_SCREEN_WIDTH + 8, PLAY_SCREEN_HEIGHT - 30},
          mouseOverPlayButton ? BLACK : DARKGRAY);
    }

    // Toggle isPlaying when the play button is clicked
    if (mouseOverPlayButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
      AutoAnim = !AutoAnim;
    }

    // Check if the mouse is over the step forward button
    bool mouseOverStepForwardButton = CheckCollisionPointRec(
        GetMousePosition(),
        (Rectangle){PLAY_SCREEN_WIDTH + 60, PLAY_SCREEN_HEIGHT - 50, 40, 40});

    // Draw step forward button
    DrawRectangle(PLAY_SCREEN_WIDTH + 60, PLAY_SCREEN_HEIGHT - 50, 40, 40,
                  mouseOverStepForwardButton ? LIGHTGRAY : GRAY);
    DrawText(">>", PLAY_SCREEN_WIDTH + 70, PLAY_SCREEN_HEIGHT - 40, 20,
             mouseOverStepForwardButton ? RED : WHITE);

    // Increment frame when step forward button is clicked
    if (mouseOverStepForwardButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
        beg < start + 4 + (int)v.size()) {
      loadingPercentage += ((float)1 / (4 + (int)v.size()) * 100);

      beg++;
    }

    // Check if the mouse is over the step back button
    bool mouseOverStepBackButton = CheckCollisionPointRec(
        GetMousePosition(),
        (Rectangle){PLAY_SCREEN_WIDTH - 100, PLAY_SCREEN_HEIGHT - 50, 40, 40});

    // Draw step back button
    DrawRectangle(PLAY_SCREEN_WIDTH - 100, PLAY_SCREEN_HEIGHT - 50, 40, 40,
                  mouseOverStepBackButton ? LIGHTGRAY : GRAY);
    DrawText("<<", PLAY_SCREEN_WIDTH - 90, PLAY_SCREEN_HEIGHT - 40, 20,
             mouseOverStepBackButton ? RED : WHITE);

    if (mouseOverStepBackButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
        beg > start) {
      beg--;
      loadingPercentage -= ((float)1 / (4 + (int)v.size()) * 100);
    }

    DrawText("Press RIGHT ARROW to advance", 100, 150, 20, DARKGRAY);
    DrawText("Press LEFT ARROW to go back", 100, 170, 20, DARKGRAY);
    DrawText("Press S to toggle auto-play", 100, 190, 20, DARKGRAY);
    DrawText("Press ENTER to exit", 100, 210, 20, DARKGRAY);

    const int totalWidth = 500;
    size_t screenWidth = GetScreenWidth();
    size_t screenHeight = GetScreenHeight();

    int loadedWidth =
        static_cast<int>(totalWidth * (loadingPercentage / 100.0));

    // ClearBackground(RAYWHITE);

    // Draw loading bar outline
    DrawRectangle((PLAY_SCREEN_WIDTH - 15) - totalWidth / 2,
                  PLAY_SCREEN_HEIGHT + 50, totalWidth, 30, LIGHTGRAY);

    // Draw loading bar progress
    DrawRectangle((PLAY_SCREEN_WIDTH - 15) - totalWidth / 2,
                  PLAY_SCREEN_HEIGHT + 50, loadedWidth, 30, PURPLE);

    // Draw loading text with larger font
    DrawText(TextFormat("%d%%", (int)loadingPercentage), PLAY_SCREEN_WIDTH - 20,
             PLAY_SCREEN_HEIGHT + 50, 30, BLACK);

    // Print additional message after loading completes
    //
    EndDrawing();

    if (IsKeyPressed(KEY_ENTER)) {
      break;
    }
  }
}
