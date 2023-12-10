
#ifndef CAKEFACTORY_H
#define CAKEFACTORY_H
#include "Cake.h"
// #include "Subll.h"
#include "Subll.h"
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
  CakeFactory() { loadFromFileToQueue("./dataForCakes.txt"); }
  void addToWaitingQueue(int sh, int g, int f, int s, int d) {
    waitingQueue.push(Cake(sh, g, f, s, waitingQueue.size()));
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
      vec.push_back(waitingQueue.front());// test it @EZZ i see you
      vec.pop_back();
    }
    return vec;
  }
  // code
};
#endif //
