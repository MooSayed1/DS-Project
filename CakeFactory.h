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
  std::queue<Cake> waitingQueue;

  // Mapping for CakeShape
  std::unordered_map<int, std::string> shapeMap{
      {0, "Round"}, {1, "Square"}, {2, "Rectangle"}, {3, "Triangle"}};

  // Mapping for CakeGlazing
  std::unordered_map<int, std::string> glazingMap{
      {0, "Chocolate"}, {1, "Vanilla"}, {2, "Strawberry"}};

  // Mapping for CakeFlavor
  std::unordered_map<int, std::string> flavorMap{
      {0, "Chocolate"}, {1, "Vanilla"}, {2, "Strawberry"}};

  // Mapping for CakeSprinkles
  std::unordered_map<int, std::string> sprinklesMap{
      {0, "Greenleaf"}, {1, "Heart"}, {2, "Jellybeans"}};

public:
  CakeFactory();
  void addToWaitingQueue(int sh, int g, int f, int s, int d);

  // Function to get string representation of CakeShape
  std::string getShapeString(int shape);

  // Function to get string representation of CakeGlazing
  std::string getGlazingString(int glazing);

  // Function to get string representation of CakeFlavor
  std::string getFlavorString(int flavor);

  // Function to get string representation of CakeSprinkles
  std::string getSprinklesString(int sprinkles);

  void loadFromFileToQueue(const std::string &filename);

  std::vector<Cake> GiveMeCake();
};

#endif // CAKEFACTORY_H
