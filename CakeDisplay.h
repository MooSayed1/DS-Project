#ifndef CAKE_DISPLAY_H
#define CAKE_DISPLAY_H
#include "Cake.h"
#include "CakeFactory.h" 
#include <vector>
#include <raylib.h>
#include <thread>

void simulateLoading();
void displayOrders(const std::vector<Cake> &orders);

#endif // CAKE_DISPLAY_H
