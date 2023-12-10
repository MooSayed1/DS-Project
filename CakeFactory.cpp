
// CakeFactory.cpp
#include "CakeFactory.h"

CakeFactory::CakeFactory() {
  loadFromFileToQueue("./dataForCakes.txt");
}

void CakeFactory::addToWaitingQueue(int sh, int g, int f, int s, int d) {
  waitingQueue.push(Cake(sh, g, f, s, waitingQueue.size()));
}

std::string CakeFactory::getShapeString(int shape) {
  auto it = shapeMap.find(shape);
  return (it != shapeMap.end()) ? it->second : "Unknown Shape";
}

std::string CakeFactory::getGlazingString(int glazing) {
  auto it = glazingMap.find(glazing);
  return (it != glazingMap.end()) ? it->second : "Unknown Glazing";
}

std::string CakeFactory::getFlavorString(int flavor) {
  auto it = flavorMap.find(flavor);
  return (it != flavorMap.end()) ? it->second : "Unknown Flavor";
}

std::string CakeFactory::getSprinklesString(int sprinkles) {
  auto it = sprinklesMap.find(sprinkles);
  return (it != sprinklesMap.end()) ? it->second : "Unknown Sprinkles";
}

void CakeFactory::loadFromFileToQueue(const std::string &filename) {
  // Assuming each line in the file represents a cake with attributes
  // separated by spaces Example line: 1 0 2 3 1001 (id shape glazing flavor
  // sprinkles)

  std::ifstream file(filename);
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

std::vector<Cake> CakeFactory::GiveMeCake() {
  std::vector<Cake> vec;
  while (!waitingQueue.empty()) {
    vec.push_back(waitingQueue.front());
    vec.pop_back();
  }
  return vec;
}
