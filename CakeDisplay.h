
// CakeDisplay.h
#ifndef CAKE_DISPLAY_H
#define CAKE_DISPLAY_H

#include "CakeFactory.h" // Assuming CakeFactory.h is required
#include <vector>
#include <raylib.h>
#include <thread>
#include <pthread.h>        // POSIX style threads management
#include <atomic>           // C++11 atomic data types
#include <ctime>            // Required for: clock()

void simulateLoading();
void displayOrders(const std::vector<Cake> &orders, CakeFactory mahdi);

#endif // CAKE_DISPLAY_H
