
#ifndef CAKEFACTORY_H
#define CAKEFACTORY_H
#include "Cake.h"
// #include "Subll.h"
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
class CakeFactory {
private:
  queue<Cake> waitingQueue;

public:
  CakeFactory() {
    loadFromFileToQueue("./dataForCakes.txt"); 
  }
  void addToWaitingQueue(CakeShape sh, CakeGlazing g, CakeFlavor f, CakeSprinkles s, int d) { waitingQueue.push(Cake(sh,g,f,s,waitingQueue.size())); }
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
          addToWaitingQueue(static_cast<CakeShape>(shape),static_cast<CakeGlazing>(glazing),static_cast<CakeFlavor>(flavor),static_cast<CakeSprinkles>(sprinkles),id);
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
    vector<Cake>ass;
    while(!waitingQueue.empty())
    {
      ass.push_back(waitingQueue.front());
      waitingQueue.pop();
    }
    return ass;


  }
  // code
};
#endif //
