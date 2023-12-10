
// CakeFactory.cpp
#include "CakeFactory.h"

CakeFactory::CakeFactory() {
  loadFromFileToQueue("./dataForCakes.txt");
}

void CakeFactory::addToWaitingQueue(int sh, int g, int f, int s, int d) {
  // waitingQueue.push_back(Cake(sh, g, f, s, waitingQueue.size()));
  waitingQueue.push(Cake(sh, g, f, s, waitingQueue.getSize()));
}
void CakeFactory::displayWaitingSubll()
{
 waitingQueue.print();
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

  return waitingQueue.copyToVector();
}

