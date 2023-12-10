// CakeFactory.h
#ifndef CAKEFACTORY_H
#define CAKEFACTORY_H

#include "Cake.h"
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

class CakeFactory {
private:
  std::vector<Cake> waitingQueue;
public:
  CakeFactory();
  void addToWaitingQueue(int sh, int g, int f, int s, int d);

  void loadFromFileToQueue(const std::string &filename);

  std::vector<Cake> GiveMeCake();
};

#endif // CAKEFACTORY_H
