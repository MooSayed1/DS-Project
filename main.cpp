#include "Cake.h"
#include "Stack.h"
#include "Subll.h"
#include "raylib.h"
#include <iostream>
using namespace std;
void drawMenu() {
    // Clear the screen
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Draw menu items
    DrawText("1. Start Game", 10, 10, 20, BLACK);
    DrawText("2. Options", 10, 40, 20, BLACK);
    DrawText("3. Exit", 10, 70, 20, BLACK);

    EndDrawing();
}

int main() {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Raylib Menu Example");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Update

        // Draw
        drawMenu();
        
        // Check for keyboard input
        if (IsKeyPressed(KEY_ONE)) {
            // Handle option 1
            // You can replace this with your specific functionality
            // e.g., start the game
            // For simplicity, we just print a message here
            printf("Starting the game...\n");
        } else if (IsKeyPressed(KEY_TWO)) {
            // Handle option 2
            // You can replace this with your specific functionality
            // e.g., open options menu
            // For simplicity, we just print a message here
            printf("Opening options menu...\n");
        } else if (IsKeyPressed(KEY_THREE)) {
            // Handle option 3
            // You can replace this with your specific functionality
            // e.g., exit the program
            // For simplicity, we just print a message here
            printf("Exiting the program...\n");
            break;
        }
    }

    // De-Initialization
    CloseWindow();

    return 0;
}
//---------------------------------------------------------
// void displayMenu() {
//   std::cout << "=== Project Menu ===" << std::endl;
//   std::cout << "1. Display Stack" << std::endl;
//   std::cout << "2. Pob Stack 2" << std::endl;
// }
// int main() {
//
//   Stack<string> stk;
//   char ch;
//   while (ch != 'n') {
//     // system("clear");
//     displayMenu();
//     cout << "Enter Number of operation: ";
//     int choice;
//     cin >> choice;
//     switch (choice) {
//     case 1:
//       std::cout << "Executing Option 1" << std::endl;
//       // Add your functionality for Option 1 here
//       stk.displayStack();
//       break;
//     case 2:
//       std::cout << "Executing Option 2" << std::endl;
//       // Add your functionality for Option 2 here
//       stk.pop();
//       break;
//     case 3:
//       std::cout << "Executing Option 3" << std::endl;
//       // Add your functionality for Option 3 here
//       break;
//     case 4:
//       std::cout << "Executing Option 4" << std::endl;
//       // Add your functionality for Option 4 here
//       break;
//     case 5:
//       std::cout << "Exiting the program. Goodbye!" << std::endl;
//       break;
//     default:
//       std::cout << "Invalid choice. Please enter a number between 1 and 5."
//                 << std::endl;
//     }
//     // cout << "Do You Want To Try Again[Y/n]";
//     // cin >> ch;
//   }
//   return 0;
// }
