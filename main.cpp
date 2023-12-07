#include <raylib.h>
#include "menu/menu.h"
int main() {

    size_t screenWidth = 800;
    size_t screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Cake Factory");

    Menu obj(screenWidth,screenHeight);
    obj.menu_head("Comfy Purble Factory");
    obj.add("Order a Cake", ORDER_CAKE);
    obj.add("Factory Stimulation", FACTORY_SIMULATION);
    obj.add("Exit", EXIT);

    int choice = -1;
    while (choice != EXIT) {
        choice = obj.display();

        switch (choice) {
            case ORDER_CAKE:
                // Handle order a cake
                break;
            case FACTORY_SIMULATION:
                // Handle factory stimulation
                break;
        }
    }

    CloseWindow();
    return 0;
}

