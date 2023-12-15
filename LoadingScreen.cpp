// LoadingScreen.cpp
#include "LoadingScreen.h"
#include <raylib.h>

LoadingScreen::LoadingScreen()
    : screenWidth(800), screenHeight(600), state(STATE_WAITING) {}

LoadingScreen::~LoadingScreen() {}

void LoadingScreen::Run() {
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        switch (state) {
        case STATE_WAITING:
            if (IsKeyPressed(KEY_ESCAPE)) {
                return;
            }
            if (IsKeyPressed(KEY_ENTER)) {
                startTime = std::chrono::high_resolution_clock::now();
                state = STATE_LOADING;
            }
            break;
        case STATE_LOADING:
            if (IsKeyPressed(KEY_ENTER)||IsKeyPressed(KEY_ESCAPE)) {
                   state = STATE_FINISHED;
            }
            elapsedTime = std::chrono::high_resolution_clock::now() - startTime;
            if (elapsedTime.count() >= 5.0) { // Display loading screen for 5 seconds
                state = STATE_FINISHED;
            }
            break;
        case STATE_FINISHED:
            WaitTime(0.5);
            return;
        default:
            break;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        switch (state) {
        case STATE_WAITING:
            DrawText("PRESS ENTER TO START LOADING DATA", screenWidth / 2.f, screenHeight/2-30, 20, DARKGRAY);
            break;
        case STATE_LOADING:
            DrawRectangle(screenWidth / 2.f, screenHeight/2, static_cast<int>(elapsedTime.count() * 100),
                          60, SKYBLUE); // Adjust the width of the rectangle based on time
            if (static_cast<int>(elapsedTime.count()*4) %2) {
            
            DrawText("LOADING DATA...", screenWidth / 2 + 90, screenHeight/2+10, 40, DARKBLUE);
            }
            break;
        case STATE_FINISHED:
            DrawRectangle(screenWidth / 2.f, screenHeight/2, 500, 60, LIME);
            DrawText("DATA LOADED!", screenWidth/2+90, screenHeight / 2+10, 40, GREEN);
            break;
        default:
            break;
        }

        DrawRectangleLines(screenWidth / 2.f, screenHeight / 2.f, 500, 60, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
}
