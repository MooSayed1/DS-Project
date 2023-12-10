#include "Cake.h"
#include <algorithm>
#include <raylib.h>
#include <string>
#include <vector>

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600
inline void simulation(std::vector<Cake> v) {
  // Set up the window
  int numSections = 15;

  cakeMap mapOfMaps;
  bool AutoAnim = 0;
  int start = std::min(numSections - (int)v.size(), numSections + 4);
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
    string Sprinkles = "Sprinkles: ";

    if (beg > start&&beg<v.size())
      Shape += mapOfMaps.shapeMap[v[numSections - beg].getShape()];
    if (beg > start + 1)
      Flavor += mapOfMaps.flavorMap[v[numSections - beg + 1].getFlavor()];
    if (beg > start + 2)
      Glazing += mapOfMaps.glazingMap[v[numSections - beg + 2].getGlazing()];
    if (beg > start + 3) {
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
    if (v.size() > numSections - beg) {
      DrawText(std::to_string(v[numSections - beg].getId()).c_str(),
               shapeRect.x + 10, shapeRect.y + 10, 20, BLACK);
    }
    if (v.size() > numSections - beg + 1) {
      DrawText(std::to_string(v[numSections - beg + 1].getId()).c_str(),
               flavorRect.x + 10, flavorRect.y + 10, 20, BLACK);
    }
    if (v.size() > numSections - beg + 2) {
      DrawText(std::to_string(v[numSections - beg + 2].getId()).c_str(),
               glazingRect.x + 10, glazingRect.y + 10, 20, BLACK);
    }
    if (v.size() > numSections - beg + 3) {
      DrawText(std::to_string(v[numSections - beg + 3].getId()).c_str(),
               sprinklesRect.x + 10, sprinklesRect.y + 10, 20, BLACK);
    }

    Rectangle descRect = {900, 250, 300, 200};
    Shape = "Shape: ";
    Flavor = "Flavor: ";
    Glazing = "Glazing: ";
    Sprinkles = "Sprinkles: ";
    if (beg > start + v.size() - 6) {

      Shape += mapOfMaps.shapeMap[v[numSections - beg + 4].getShape()];
      Flavor += mapOfMaps.flavorMap[v[numSections - beg + 4].getFlavor()];
      Glazing += mapOfMaps.glazingMap[v[numSections - beg + 4].getGlazing()] +
                 to_string(start + v.size());
      Sprinkles +=
          mapOfMaps.sprinklesMap[v[numSections - beg + 4].getSprinkles()] +
          to_string(beg);
    }

    DrawRectangleLinesEx(descRect, 2, BLACK);
    DrawText("Product:", descRect.x + 10, descRect.y + 10, 20, PINK);
    DrawText(Shape.c_str(), descRect.x + 20, descRect.y + 30, 20, PINK);
    DrawText(Flavor.c_str(), descRect.x + 20, descRect.y + 50, 20, PINK);
    DrawText(Glazing.c_str(), descRect.x + 20, descRect.y + 70, 20, PINK);
    DrawText(Sprinkles.c_str(), descRect.x + 20, descRect.y + 90, 20, PINK);

    if (IsKeyPressed(KEY_ENTER) && beg < start + 4 + v.size()) {
      beg++;
    } else if (IsKeyPressed(KEY_BACKSPACE) && beg > start) {
      beg--;
    } else if (IsKeyPressed(KEY_S)) {
      AutoAnim = !AutoAnim;
    }
    if (AutoAnim && beg < start + 4 + v.size()) {
      double currentTime = GetTime();
      double elapsedTime = currentTime - startTime;
      if (elapsedTime >= 1.0) {
        beg++;
        startTime = currentTime;
      }
    }
    // Check if the mouse is over the play button
    bool mouseOverPlayButton = CheckCollisionPointRec(
        GetMousePosition(),
        (Rectangle){SCREEN_WIDTH - 20, SCREEN_HEIGHT - 50, 40, 40});

    // Draw play button
    DrawRectangle(SCREEN_WIDTH - 20, SCREEN_HEIGHT - 50, 40, 40,
                  mouseOverPlayButton ? LIGHTGRAY : GRAY);

    if (AutoAnim) {
      DrawTriangle((Vector2){SCREEN_WIDTH - 8, SCREEN_HEIGHT - 30 - 8},
                   (Vector2){SCREEN_WIDTH - 8, SCREEN_HEIGHT - 30 + 8},
                   (Vector2){SCREEN_WIDTH + 8, SCREEN_HEIGHT - 30},
                   mouseOverPlayButton ? RED : MAROON);
    } else {
      DrawTriangle((Vector2){SCREEN_WIDTH - 8, SCREEN_HEIGHT - 30 - 8},
                   (Vector2){SCREEN_WIDTH - 8, SCREEN_HEIGHT - 30 + 8},
                   (Vector2){SCREEN_WIDTH + 8, SCREEN_HEIGHT - 30},
                   mouseOverPlayButton ? BLACK : DARKGRAY);
    }

    // Toggle isPlaying when the play button is clicked
    if (mouseOverPlayButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
      AutoAnim = !AutoAnim;
    }

    // Check if the mouse is over the step forward button
    bool mouseOverStepForwardButton = CheckCollisionPointRec(
        GetMousePosition(),
        (Rectangle){SCREEN_WIDTH + 60, SCREEN_HEIGHT - 50, 40, 40});

    // Draw step forward button
    DrawRectangle(SCREEN_WIDTH + 60, SCREEN_HEIGHT - 50, 40, 40,
                  mouseOverStepForwardButton ? LIGHTGRAY : GRAY);
    DrawText(">>", SCREEN_WIDTH + 70, SCREEN_HEIGHT - 40, 20,
             mouseOverStepForwardButton ? RED : WHITE);

    // Increment frame when step forward button is clicked
    if (mouseOverStepForwardButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
        beg < start + 4 + v.size()) {
      beg++;
    }

    // Check if the mouse is over the step back button
    bool mouseOverStepBackButton = CheckCollisionPointRec(
        GetMousePosition(),
        (Rectangle){SCREEN_WIDTH - 100, SCREEN_HEIGHT - 50, 40, 40});

    // Draw step back button
    DrawRectangle(SCREEN_WIDTH - 100, SCREEN_HEIGHT - 50, 40, 40,
                  mouseOverStepBackButton ? LIGHTGRAY : GRAY);
    DrawText("<<", SCREEN_WIDTH - 90, SCREEN_HEIGHT - 40, 20,
             mouseOverStepBackButton ? RED : WHITE);

    // Decrement frame when step back button is clicked
    if (mouseOverStepBackButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
        beg > start) {
      beg--;
    }

    EndDrawing();
  }
}
