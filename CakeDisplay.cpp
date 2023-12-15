#include "CakeDisplay.h"
#include "Cake.h"
#include <raylib.h>

cakeMap mapOfMaps;
void simulateLoading() {

  size_t screenWidth = GetScreenWidth();
  size_t screenHeight = GetScreenHeight();

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
             screenHeight / 2 - 30, 30, BLACK);

    EndDrawing();

    // Simulate work
    std::this_thread::sleep_for(
        std::chrono::milliseconds(25)); // Make the animation twice as fast

    loadingPercentage += 2; // Increase loading by 2% per iteration
    if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_ESCAPE)) {
      return;
    }
  }

  DrawText("Loaded Data Successfully",
           screenWidth / 2 - MeasureText("Loaded Data Successfully", 20) / 2,
           screenHeight / 2 + 20, 20, BLACK);
  EndDrawing();

  std::this_thread::sleep_for(std::chrono::seconds(1));
}

class CakeTable {
public:
  CakeTable(int screenWidth, int screenHeight)
      : screenWidth(screenWidth), screenHeight(screenHeight) {}

  ~CakeTable() {}

  void addCake(int id, int shape, int flavor, int glazing, int sprinkles) {
    Cake cake(id, shape, flavor, glazing, sprinkles);
    cakes.push_back(cake);
  }

  void drawTable() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Draw cakes
    for (size_t i = 0; i < cakes.size(); i++) {
      DrawText(TextFormat("%d", cakes[i].getId()), (screenWidth / 7.f),
               40 + i * 30 - scrollY, 20, RED);
      DrawText(mapOfMaps.shapeMap[cakes[i].getShape()].c_str(),
               2 * (screenWidth / 7.f), 40 + i * 30 - scrollY, 20, GREEN);
      DrawText(mapOfMaps.flavorMap[cakes[i].getFlavor()].c_str(),
               3 * (screenWidth / 7.f), 40 + i * 30 - scrollY, 20, BLUE);
      DrawText(mapOfMaps.glazingMap[cakes[i].getGlazing()].c_str(),
               4 * (screenWidth / 7.f), 40 + i * 30 - scrollY, 20, PURPLE);
      DrawText(mapOfMaps.sprinklesMap[cakes[i].getSprinkles()].c_str(),
               5 * (screenWidth / 7.f), 40 + i * 30 - scrollY, 20, ORANGE);
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

    if ((IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_K)) &&
        scrollY <= totalContentHeight - screenHeight) {
      scrollY += 10.f;
    }
    if ((IsKeyDown(KEY_UP) || IsKeyDown(KEY_J)) && scrollY - 10 >= 0) {
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

  CakeTable cakeTable(screenWidth, screenHeight);
  for (auto &order : orders) {
    cakeTable.addCake(order.getShape(), order.getFlavor(), order.getGlazing(),
                      order.getSprinkles(), order.getId());
  }

  while (!WindowShouldClose()) {
    cakeTable.drawTable();

    if (IsKeyPressed(KEY_ENTER)||IsKeyPressed(KEY_ESCAPE)) {
      return;
    }
  }
}
