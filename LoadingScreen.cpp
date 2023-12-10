
// LoadingScreen.cpp
#include "LoadingScreen.h"

LoadingScreen::LoadingScreen()
    : screenWidth(800), screenHeight(600), state(STATE_WAITING) {}

LoadingScreen::~LoadingScreen() {}

void LoadingScreen::Run() {
<<<<<<< HEAD
=======
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    // InitWindow(screenWidth, screenHeight, "raylib [core] example - loading thread");

    enum { STATE_WAITING, STATE_LOADING, STATE_FINISHED } state = STATE_WAITING;
    int framesCounter = 0;

    // Introduce a flag to track whether loading has been initiated
    bool loadingInitiated = false;

>>>>>>> db53ff5 (git push)
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        switch (state) {
<<<<<<< HEAD
        case STATE_WAITING:
            if (IsKeyPressed(KEY_ENTER)) {
                startTime = std::chrono::high_resolution_clock::now();
                state = STATE_LOADING;
            }
            break;
        case STATE_LOADING:
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
=======
            case STATE_WAITING: {
                if (IsKeyPressed(KEY_ENTER)) {
                    if (!loadingInitiated) {
                        int error = pthread_create(&threadId, NULL, &LoadDataThread, this);
                        if (error != 0) {
                            TraceLog(LOG_ERROR, "Error creating loading thread");
                        } else {
                            TraceLog(LOG_INFO, "Loading thread initialized successfully");
                            loadingInitiated = true; // Set the flag to true
                            state = STATE_LOADING;
                        }
                    }
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
>>>>>>> db53ff5 (git push)
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        switch (state) {
        case STATE_WAITING:
            DrawText("PRESS ANY TO START LOADING DATA", screenWidth / 2.f, screenHeight/2-30, 20, DARKGRAY);
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

    // CloseWindow();
}

<<<<<<< HEAD
=======


void *LoadingScreen::LoadDataThread(void *arg) {
    LoadingScreen* instance = static_cast<LoadingScreen*>(arg);

    double timeCounter = 0.0;
    clock_t prevTime = clock();

    while (timeCounter < 5000.0) {
        clock_t currentTime = clock() - prevTime;
        
        // Increase loading speed by multiplying the increment factor (e.g., 2.0)
        timeCounter += .004 * static_cast<double>(currentTime) / CLOCKS_PER_SEC;

        instance->dataProgress.store(static_cast<int>(timeCounter / 10.0), std::memory_order_relaxed);
    }

    instance->dataLoaded.store(true, std::memory_order_relaxed);

    return 0;
}

>>>>>>> db53ff5 (git push)
