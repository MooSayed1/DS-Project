#include <raylib.h>
#include <algorithm>
#include <string>
#include "Cake.h"
#include <vector>

inline void stimulation(std::vector<Cake> v ) {
  // Set up the window
  int numSections = 15;


  int beg = std::min(numSections-(int)v.size(),numSections+4);


  while (!WindowShouldClose()) {
    BeginDrawing();

    // Clear the screen
    ClearBackground(RAYWHITE);

    // Draw the cake ingredients
    DrawText("Cake Ingredients:", 10, 10, 20, BLACK);

    // Define cake ingredient positions
    Rectangle shapeRect = {50, 300, 100, 50};
    Rectangle flavorRect = {250, 300, 100, 50};
    Rectangle glazingRect = {450, 300, 100, 50};
    Rectangle sprinklesRect = {650, 300, 100, 50};
    // Add more ingredients as needed
    DrawText("Shape:", shapeRect.x, shapeRect.y - 20, 20, BLACK);
    DrawText("Flovor:", flavorRect.x, flavorRect.y - 20, 20, BLACK);
    DrawText("Glazing:", glazingRect.x, glazingRect.y - 20, 20, BLACK);
    DrawText("Sprinkles:", sprinklesRect.x, sprinklesRect.y - 20, 20, BLACK);
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
       if(i>0)
      DrawText(TextFormat("%d", v[i - 1 - beg].getId()), sectionCenterX,
               overallRectangle.y + overallRectangle.height / 2 - 10, 20,
               BLACK);
    }

    // Print a number inside each rectangle
    if (v.size() > numSections - beg) {
      DrawText(std::to_string(v[numSections - beg].getId()).c_str(), shapeRect.x + 10,
               shapeRect.y + 10, 20, BLACK);
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

    Rectangle descRect = {100, 500, 300, 200};
    DrawRectangleLinesEx(descRect, 2, BLACK);
    DrawText("Product:", descRect.x + 10, descRect.y + 10, 20, PINK);
    DrawText("Shape:", descRect.x + 20, descRect.y + 30, 20, PINK);
    DrawText("Flavor:", descRect.x + 20, descRect.y + 50, 20, PINK);
    DrawText("Glazing:", descRect.x + 20, descRect.y + 70, 20, PINK);
    DrawText("Sprinkles:", descRect.x + 20, descRect.y + 90, 20, PINK);
    if (IsKeyPressed(KEY_ENTER)) {
      beg++;
    }

    EndDrawing();
  }


}
