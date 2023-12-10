
// LoadingScreen.h
#ifndef LOADING_SCREEN_H
#define LOADING_SCREEN_H

#include "raylib.h"
#include <chrono>

class LoadingScreen {
public:
    LoadingScreen();
    ~LoadingScreen();

    void Run();

private:
    float screenWidth;
    float screenHeight;

    std::chrono::high_resolution_clock::time_point startTime;
    std::chrono::duration<double> elapsedTime;

    enum { STATE_WAITING, STATE_LOADING, STATE_FINISHED } state;
};

#endif // LOADING_SCREEN_H

