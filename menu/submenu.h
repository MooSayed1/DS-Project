#include "raylib.h"
#include <string>

#define MAX_SHAPE_OPTIONS 3
#define MAX_FLAVOR_OPTIONS 3
#define MAX_GLAZING_OPTIONS 3
#define MAX_SPRINKLE_OPTIONS 3

typedef struct {
  Rectangle rect;
  Texture2D image;
  Texture2D activeImage;
  const char *name;
} ToggleOption;
inline void DrawToggleOption(ToggleOption *option, bool active) {
  DrawTexture(active ? option->activeImage : option->image, option->rect.x,
              option->rect.y, WHITE);

  if (option->image.width == 0) {
    DrawText(option->name, option->rect.x, option->rect.y, 20,
             active ? RED : BLACK);
  } else
    DrawText(option->name,
             option->rect.x + option->rect.width / 2 -
                 MeasureText(option->name, 20) / 2.f,
             option->rect.y + option->rect.height + 10, 20, BLACK);
}
inline void DrawPreText(std::string name, float x, float y, bool active) {

  DrawText(name.c_str(), x, y, 20, active ? RED : BLACK);
}

inline void updateResolution(float &width, float &height) {
  // Check if window size has changed
  if (IsWindowResized()) {
    width = GetScreenWidth();
    height = GetScreenHeight();
  }
}

inline bool SubMenu(int &activeShapeInd, int &activeGlazingInd,
                    int &activeFlavorInd, int &activeSprinkleInd) {
  float height = GetScreenHeight();
  float width = GetScreenWidth();

  Sound fxHovering; // Keep the sound as a member variable
  Sound fxPressing; // Keep the sound as a member variable
  fxHovering = LoadSound("./resources/shooting-sound-fx-159024.mp3");
  fxPressing = LoadSound("./resources/notification-sound-7062.mp3");

  ToggleOption shapeOptions[MAX_SHAPE_OPTIONS];
  ToggleOption flavorOptions[MAX_FLAVOR_OPTIONS];
  ToggleOption glazingOptions[MAX_GLAZING_OPTIONS];
  ToggleOption sprinkleOptions[MAX_SPRINKLE_OPTIONS];
  ToggleOption saveOption;
  ToggleOption cancelOption;

  const int rows = 6;
  int selected = 0;
  int Saved = -1;

  // Initialize shape options
  shapeOptions[0].image = LoadTexture("./resources/Circle1.png");
  shapeOptions[0].activeImage = LoadTexture("./resources/Circle2.png");
  shapeOptions[0].rect =
      (Rectangle){width / 3, height / 10 + 100,
                  static_cast<float>(shapeOptions[0].image.width),
                  static_cast<float>(shapeOptions[0].image.height)};
  shapeOptions[0].name = "Circle";

  shapeOptions[1].image = LoadTexture("./resources/Rect1.png");
  shapeOptions[1].activeImage = LoadTexture("./resources/Rect2.png");
  shapeOptions[1].rect =
      (Rectangle){width / 3 + 200, height / 10 + 100,
                  static_cast<float>(shapeOptions[1].image.width),
                  static_cast<float>(shapeOptions[1].image.height)};
  shapeOptions[1].name = "Rectangle";

  shapeOptions[2].image = LoadTexture("./resources/Heart1.png");
  shapeOptions[2].activeImage = LoadTexture("./resources/Heart2.png");
  shapeOptions[2].rect =
      (Rectangle){width / 3 + 400, height / 10 + 100,
                  static_cast<float>(shapeOptions[2].image.width),
                  static_cast<float>(shapeOptions[2].image.height)};
  shapeOptions[2].name = "Heart";

  // Initialize flavor options
  flavorOptions[0].image = LoadTexture("./resources/Chocolate1.png");
  flavorOptions[0].activeImage = LoadTexture("./resources/Chocolate2.png");
  flavorOptions[0].rect =
      (Rectangle){width / 3, height / 10 + 200,
                  static_cast<float>(flavorOptions[0].image.width),
                  static_cast<float>(flavorOptions[0].image.height)};
  flavorOptions[0].name = "Chocolate";

  flavorOptions[1].image = LoadTexture("./resources/Vanilla1.png");
  flavorOptions[1].activeImage = LoadTexture("./resources/Vanilla2.png");
  flavorOptions[1].rect =
      (Rectangle){width / 3 + 200, height / 10 + 200,
                  static_cast<float>(flavorOptions[1].image.width),
                  static_cast<float>(flavorOptions[1].image.height)};
  flavorOptions[1].name = "Vanilla";

  flavorOptions[2].image = LoadTexture("./resources/Strawberry1.png");
  flavorOptions[2].activeImage = LoadTexture("./resources/Strawberry2.png");
  flavorOptions[2].rect =
      (Rectangle){width / 3 + 400, height / 10 + 200,
                  static_cast<float>(flavorOptions[2].image.width),
                  static_cast<float>(flavorOptions[2].image.height)};
  flavorOptions[2].name = "Strawberry";

  glazingOptions[0].image = LoadTexture("./resources/ChocolateGlaze1.png");
  glazingOptions[0].activeImage =
      LoadTexture("./resources/ChocolateGlaze2.png");
  glazingOptions[0].rect =
      (Rectangle){width / 3, height / 10 + 300,
                  static_cast<float>(glazingOptions[0].image.width),
                  static_cast<float>(glazingOptions[0].image.height)};
  glazingOptions[0].name = "Chocolate";

  glazingOptions[1].image = LoadTexture("./resources/VanillaGlaze1.png");
  glazingOptions[1].activeImage = LoadTexture("./resources/VanillaGlaze2.png");
  glazingOptions[1].rect =
      (Rectangle){width / 3 + 200, height / 10 + 300,
                  static_cast<float>(glazingOptions[1].image.width),
                  static_cast<float>(glazingOptions[1].image.height)};
  glazingOptions[1].name = "Vanilla";

  glazingOptions[2].image = LoadTexture("./resources/StrawberryGlaze1.png");
  glazingOptions[2].activeImage =
      LoadTexture("./resources/StrawberryGlaze2.png");
  glazingOptions[2].rect =
      (Rectangle){width / 3 + 400, height / 10 + 300,
                  static_cast<float>(glazingOptions[2].image.width),
                  static_cast<float>(glazingOptions[2].image.height)};
  glazingOptions[2].name = "Strawberry";
  // Initialize sprinkle options
  sprinkleOptions[0].image = LoadTexture("./resources/Greanleaf1.png");
  sprinkleOptions[0].activeImage = LoadTexture("./resources/Greanleaf2.png");
  sprinkleOptions[0].rect =
      (Rectangle){width / 3 + 20, height / 10 + 400,
                  static_cast<float>(sprinkleOptions[0].image.width),
                  static_cast<float>(sprinkleOptions[0].image.height)};
  sprinkleOptions[0].name = "Grean Leaf";

  sprinkleOptions[1].image = LoadTexture("./resources/Jelly1.png");
  sprinkleOptions[1].activeImage = LoadTexture("./resources/Jelly2.png");
  sprinkleOptions[1].rect =
      (Rectangle){width / 3 + 220, height / 10 + 400,
                  static_cast<float>(sprinkleOptions[1].image.width),
                  static_cast<float>(sprinkleOptions[1].image.height)};
  sprinkleOptions[1].name = "Jelly beans";

  sprinkleOptions[2].image = LoadTexture("./resources/HeartSprink1.png");
  sprinkleOptions[2].activeImage = LoadTexture("./resources/HeartSprink2.png");
  sprinkleOptions[2].rect =
      (Rectangle){width / 3 + 420, height / 10 + 400,
                  static_cast<float>(sprinkleOptions[2].image.width),
                  static_cast<float>(sprinkleOptions[2].image.height)};
  sprinkleOptions[2].name = "Heart";

  saveOption.rect =
      (Rectangle){width / 2, height / 10 + 525,
                  static_cast<float>(MeasureText("Save", 20)), 40};
  saveOption.name = "Save";

  cancelOption.rect =
      (Rectangle){width / 2, height / 10 + 575,
                  static_cast<float>(MeasureText("Cancel", 20)), 40};
  cancelOption.name = "cancel";

  SetTargetFPS(60);

  while (!WindowShouldClose() && Saved == -1) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Choose", width / 2 - MeasureText("Chose", 20) / 2.f, height / 20,
             40, BLACK);

    // Draw the category titles
    DrawPreText("Cake SHAPE:", height / 4,
                shapeOptions[0].rect.y + shapeOptions[0].rect.height / 2.f,
                selected == 0);

    DrawPreText("Cake FLAVOR:", height / 4,
                flavorOptions[0].rect.y + flavorOptions[0].rect.height / 2.f,
                selected == 1);
    DrawPreText("Cake GLAZING:", height / 4,
                glazingOptions[0].rect.y + glazingOptions[0].rect.height / 2.f,
                selected == 2);
    DrawPreText("Cake Sprinkles:", height / 4,
                sprinkleOptions[0].rect.y +
                    sprinkleOptions[0].rect.height / 2.f,
                selected == 3);
    // Check for mouse clicks on shape options
    for (int i = 0; i < MAX_SHAPE_OPTIONS; i++) {
      if (CheckCollisionPointRec(GetMousePosition(), shapeOptions[i].rect)) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
          activeShapeInd = i;
          selected = 0;
          PlaySound(fxPressing);
        }
      }
      DrawToggleOption(&shapeOptions[i], activeShapeInd == i);
    }

    // Check for mouse clicks on flavor options
    for (int i = 0; i < MAX_FLAVOR_OPTIONS; i++) {
      if (CheckCollisionPointRec(GetMousePosition(), flavorOptions[i].rect)) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
          activeFlavorInd = i;
          selected = 1;
          PlaySound(fxPressing);
        }
      }
      DrawToggleOption(&flavorOptions[i], activeFlavorInd == i);
    }

    // Check for mouse clicks on glazing options
    for (int i = 0; i < MAX_GLAZING_OPTIONS; i++) {
      if (CheckCollisionPointRec(GetMousePosition(), glazingOptions[i].rect)) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
          activeGlazingInd = i;
          selected = 2;
          PlaySound(fxPressing);
        }
      }
      DrawToggleOption(&glazingOptions[i], activeGlazingInd == i);
    }
    // Check for mouse clicks on sprinkle options
    for (int i = 0; i < MAX_SPRINKLE_OPTIONS; i++) {
      if (CheckCollisionPointRec(GetMousePosition(), sprinkleOptions[i].rect)) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
          activeSprinkleInd = i;
          selected = 3;
          PlaySound(fxPressing);
        }
      }
      DrawToggleOption(&sprinkleOptions[i], activeSprinkleInd == i);
    }
    // Check for mouse clicks on save
    if (CheckCollisionPointRec(GetMousePosition(), saveOption.rect)) {
      if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        PlaySound(fxPressing);
        selected = 4;
        Saved = 1;
      }
    }
    DrawToggleOption(&saveOption, selected == 4);
    // Check for mouse clicks on cancel
    if (CheckCollisionPointRec(GetMousePosition(), cancelOption.rect)) {
      if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        PlaySound(fxPressing);
        selected = 5;
        Saved = 0;
      }
    }
    DrawToggleOption(&cancelOption, selected == 5);

    if (IsKeyPressed(KEY_RIGHT)) {
      switch (selected) {
      case 0:
        activeShapeInd = (activeShapeInd + 1) % MAX_SHAPE_OPTIONS;
        break;
      case 1:
        activeFlavorInd = (activeFlavorInd + 1) % MAX_FLAVOR_OPTIONS;
        break;
      case 2:
        activeGlazingInd = (activeGlazingInd + 1) % MAX_GLAZING_OPTIONS;
        break;
      case 3:
        activeSprinkleInd = (activeSprinkleInd + 1) % MAX_SPRINKLE_OPTIONS;
        break;
      }
      PlaySound(fxPressing);

    } else if (IsKeyPressed(KEY_LEFT)) {
            PlaySound(fxHovering);

      switch (selected) {
      case 0:
        activeShapeInd =
            (activeShapeInd + MAX_SHAPE_OPTIONS - 1) % MAX_SHAPE_OPTIONS;
        break;
      case 1:
        activeFlavorInd =
            (activeFlavorInd + MAX_FLAVOR_OPTIONS - 1) % MAX_FLAVOR_OPTIONS;
        break;
      case 2:
        activeGlazingInd =
            (activeGlazingInd + MAX_GLAZING_OPTIONS - 1) % MAX_GLAZING_OPTIONS;
        break;
      case 3:
        activeSprinkleInd = (activeSprinkleInd + MAX_SPRINKLE_OPTIONS - 1) %
                            MAX_SPRINKLE_OPTIONS;
        break;
      }

    } else if (IsKeyPressed(KEY_UP)) {
      selected = (selected + rows - 1) % rows;
      PlaySound(fxHovering);
    } else if (IsKeyPressed(KEY_DOWN)) {
      selected = (selected + 1) % rows;
      PlaySound(fxHovering);
    } else if (IsKeyPressed(KEY_ENTER)) {
      switch (selected) {
      case 4:
        PlaySound(fxPressing);
        Saved = 1;
        break;
      case 5:
        PlaySound(fxPressing);
        Saved = 0;
        break;
      }
    }
    // Check if window size has changed
    if (IsWindowResized()) {
      width = GetScreenWidth();
      height = GetScreenHeight();

      // Update the position and size of the shape options
      for (int i = 0; i < MAX_SHAPE_OPTIONS; i++) {
        shapeOptions[i].rect.x = (width / 3) + i * 200;
        shapeOptions[i].rect.y = height / 10 + 100;
        shapeOptions[i].rect.width =
            static_cast<float>(shapeOptions[i].image.width);
        shapeOptions[i].rect.height =
            static_cast<float>(shapeOptions[i].image.height);
      }

      // Update the position and size of the flavor options
      for (int i = 0; i < MAX_FLAVOR_OPTIONS; i++) {
        flavorOptions[i].rect.x = (width / 3) + i * 200;
        flavorOptions[i].rect.y = height / 10 + 200;
        flavorOptions[i].rect.width =
            static_cast<float>(flavorOptions[i].image.width);
        flavorOptions[i].rect.height =
            static_cast<float>(flavorOptions[i].image.height);
      }

      // Update the position and size of the glazing options
      for (int i = 0; i < MAX_GLAZING_OPTIONS; i++) {
        glazingOptions[i].rect.x = (width / 3) + i * 200;
        glazingOptions[i].rect.y = height / 10 + 300;
        glazingOptions[i].rect.width =
            static_cast<float>(glazingOptions[i].image.width);
        glazingOptions[i].rect.height =
            static_cast<float>(glazingOptions[i].image.height);
      }

      // Update the position and size of the sprinkle options
      for (int i = 0; i < MAX_SPRINKLE_OPTIONS; i++) {
        sprinkleOptions[i].rect.x = (width / 3) + i * 200 + 20;
        sprinkleOptions[i].rect.y = height / 10 + 400;
        sprinkleOptions[i].rect.width =
            static_cast<float>(sprinkleOptions[i].image.width);
        sprinkleOptions[i].rect.height =
            static_cast<float>(sprinkleOptions[i].image.height);
      }

      // Update the position and size of the save option
      saveOption.rect.x = (width / 2);
      saveOption.rect.y = height / 10 + 550;
      saveOption.rect.width = static_cast<float>(MeasureText("Save", 20));
      saveOption.rect.height = 40;

      // Update the position and size of the cancel option
      cancelOption.rect.x = (width / 2);
      cancelOption.rect.y = height / 10 + 575;
      cancelOption.rect.width = static_cast<float>(MeasureText("Cancel", 20));
      cancelOption.rect.height = 40;
    }
    EndDrawing();

  }

  // Unload textures for shape options
  for (int i = 0; i < MAX_SHAPE_OPTIONS; i++) {
    UnloadTexture(shapeOptions[i].image);
    UnloadTexture(shapeOptions[i].activeImage);
  }

  // Unload textures for flavor options
  for (int i = 0; i < MAX_FLAVOR_OPTIONS; i++) {
    UnloadTexture(flavorOptions[i].image);
    UnloadTexture(flavorOptions[i].activeImage);
  }

  // Unload textures for glazing options
  for (int i = 0; i < MAX_GLAZING_OPTIONS; i++) {
    UnloadTexture(glazingOptions[i].image);
    UnloadTexture(glazingOptions[i].activeImage);
  }

  // Unload textures for sprinkles options
  for (int i = 0; i < MAX_SPRINKLE_OPTIONS; i++) {
    UnloadTexture(sprinkleOptions[i].image);
    UnloadTexture(sprinkleOptions[i].activeImage);
  }
  
  UnloadSound(fxHovering);
  UnloadSound(fxPressing);
  if (Saved == 1) {
    return true;
  } else {
    return false;
  }
}
