// LoadingScreen.cpp
#include "LoadingScreen.h"
#include <ctime>

LoadingScreen::LoadingScreen() : dataLoaded(false), dataProgress(0) {}

LoadingScreen::~LoadingScreen() {}

void LoadingScreen::Run() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - loading thread");

    enum { STATE_WAITING, STATE_LOADING, STATE_FINISHED } state = STATE_WAITING;
    int framesCounter = 0;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        switch (state) {
            case STATE_WAITING: {
                if (IsKeyPressed(KEY_ENTER)) {
                    int error = pthread_create(&threadId, NULL, &LoadDataThread, this);
                    if (error != 0) TraceLog(LOG_ERROR, "Error creating loading thread");
                    else TraceLog(LOG_INFO, "Loading thread initialized successfully");

                    state = STATE_LOADING;
                }
            } break;
            case STATE_LOADING: {
                framesCounter++;
                if (dataLoaded.load(std::memory_order_relaxed)) {
                    framesCounter = 0;
                    int error = pthread_join(threadId, NULL);
                    if (error != 0) TraceLog(LOG_ERROR, "Error joining loading thread");
                    else TraceLog(LOG_INFO, "Loading thread terminated successfully");

                    state = STATE_FINISHED;
                }
            } break;
            case STATE_FINISHED: {
                if (IsKeyPressed(KEY_ENTER)) {
                    dataLoaded.store(false, std::memory_order_relaxed);
                    dataProgress.store(0, std::memory_order_relaxed);
                    state = STATE_WAITING;
                }
            } break;
            default: break;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        switch (state) {
            case STATE_WAITING: DrawText("PRESS ENTER to START LOADING DATA", 150, 170, 20, DARKGRAY); break;
            case STATE_LOADING: {
                DrawRectangle(150, 200, dataProgress.load(std::memory_order_relaxed), 60, SKYBLUE);
                if ((framesCounter / 15) % 2) DrawText("LOADING DATA...", 240, 210, 40, DARKBLUE);
            } break;
            case STATE_FINISHED: {
                DrawRectangle(150, 200, 500, 60, LIME);
                DrawText("DATA LOADED!", 250, 210, 40, GREEN);
            } break;
            default: break;
        }

        DrawRectangleLines(150, 200, 500, 60, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
}

void *LoadingScreen::LoadDataThread(void *arg) {
    LoadingScreen* instance = static_cast<LoadingScreen*>(arg);

    double timeCounter = 0.0;
    clock_t prevTime = clock();

    while (timeCounter < 5000.0) {
        clock_t currentTime = clock() - prevTime;
        timeCounter = static_cast<double>(currentTime) * 1000.0 / CLOCKS_PER_SEC;

        instance->dataProgress.store(static_cast<int>(timeCounter / 10.0), std::memory_order_relaxed);
    }

    instance->dataLoaded.store(true, std::memory_order_relaxed);

    return 0;
}
