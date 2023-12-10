
// LoadingScreen.h
#ifndef LOADING_SCREEN_H
#define LOADING_SCREEN_H

#include "raylib.h"
#include <pthread.h>
#include <atomic>

class LoadingScreen {
public:
    LoadingScreen();
    ~LoadingScreen();

    void Run();

private:
    pthread_t threadId;
    std::atomic<bool> dataLoaded;
    std::atomic<int> dataProgress;

    static void *LoadDataThread(void *arg);
};

#endif // LOADING_SCREEN_H
