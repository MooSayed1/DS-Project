
#ifndef CAKEFACTORY_H
#define CAKEFACTORY_H
#include "Cake.h"
// #include "Subll.h"
#include "Subll.h"
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class CakeFactory {
private:
  queue<Cake> waitingQueue;
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
  CakeFactory() { loadFromFileToQueue("./dataForCakes.txt"); }
  void addToWaitingQueue(int sh, int g, int f, int s, int d) {
    waitingQueue.push(Cake(sh, g, f, s, waitingQueue.size()));
  }

  // Function to get string representation of CakeShape
  std::string getShapeString(int shape) {
    auto it = shapeMap.find(shape);
    return (it != shapeMap.end()) ? it->second : "Unknown Shape";
  }

  // Function to get string representation of CakeGlazing
  std::string getGlazingString(int glazing) {
    auto it = glazingMap.find(glazing);
    return (it != glazingMap.end()) ? it->second : "Unknown Glazing";
  }

  // Function to get string representation of CakeFlavor
  std::string getFlavorString(int flavor) {
    auto it = flavorMap.find(flavor);
    return (it != flavorMap.end()) ? it->second : "Unknown Flavor";
  }

  // Function to get string representation of CakeSprinkles
  std::string getSprinklesString(int sprinkles) {
    auto it = sprinklesMap.find(sprinkles);
    return (it != sprinklesMap.end()) ? it->second : "Unknown Sprinkles";
  }
  void loadFromFileToQueue(const std::string &filename) {
    // Assuming each line in the file represents a cake with attributes
    // separated by spaces Example line: 1 0 2 3 1001 (id shape glazing flavor
    // sprinkles)

    ifstream file(filename);
    if (file.is_open()) {
      std::string line;
      while (std::getline(file, line)) {
        std::istringstream iss(line);
        int id, shape, glazing, flavor, sprinkles;
        if (iss >> id >> shape >> glazing >> flavor >> sprinkles) {
          addToWaitingQueue(shape, glazing, flavor, sprinkles, id);
        } else {
          std::cerr << "Invalid line format in file: " << line << std::endl;
        }
      }
      file.close();
    } else {
      std::cerr << "Unable to open file: " << filename << std::endl;
    }
  }
  vector<Cake> GiveMeCake() {
    vector<Cake> vec;
    while (!waitingQueue.empty()) {
      vec.push_back(waitingQueue.front());
      vec.pop_back();
    }
    return vec;
  }
  // code
};
#endif //
