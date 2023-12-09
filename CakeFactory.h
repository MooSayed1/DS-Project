
#ifndef CAKEFACTORY_H
#define CAKEFACTORY_H
#include "Cake.h"
#include "Stack.h"
#include "Subll.h"
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
using namespace std;
class CakeFactory {

public:
  // Enums for cake attributes
  enum class CakeShape {
    ROUND,
    SQUARE,
    RECTANGLE,
    TRIANGLE,
    // Add more shapes as needed
  };

  enum class CakeGlazing {
    CHOCOLATE,
    VANILLA,
    STRAWBERRY,
    CARAMEL,
    // Add more glazing options as needed
  };

  enum class CakeFlavor {
    CHOCOLATE,
    VANILLA,
    STRAWBERRY,
    LEMON,
    // Add more flavor options as needed
  };

  enum class CakeSprinkles {
    NONE,
    CHOCOLATE,
    RAINBOW,
    NUTS,
    // Add more sprinkles options as needed
  };

  enum class CakeStatus {
    WAITING,
    IN_PROGRESS,
    READY,
  };

  class Cake {
  private:
    CakeShape shape;
    CakeGlazing glazing;
    CakeFlavor flavor;
    CakeSprinkles sprinkles;
    int id;
    CakeStatus status;

  public:
    // Constructor
    Cake(CakeShape sh, CakeGlazing g, CakeFlavor f, CakeSprinkles s, int d)
        : shape(sh), glazing(g), flavor(f), sprinkles(s), id(d),
          status(CakeStatus::WAITING) {}

    // Default constructor
    Cake()
        : shape(CakeShape::ROUND), glazing(CakeGlazing::CHOCOLATE),
          flavor(CakeFlavor::VANILLA), sprinkles(CakeSprinkles::NONE), id(-1),
          status(CakeStatus::WAITING) {}

    // Getter and setter functions for status
    CakeStatus getStatus() const { return status; }
    void setStatus(CakeStatus s) { status = s; }

    // Getter functions for other attributes
    CakeShape getShape() const { return shape; }
    CakeGlazing getGlazing() const { return glazing; }
    CakeFlavor getFlavor() const { return flavor; }
    CakeSprinkles getSprinkles() const { return sprinkles; }
    int getId() const { return id; }
  };

private:
  queue<Cake> waitingQueue;

public:
  // Function to add a cake to the waiting queue
  CakeFactory() { loadFromFileToQueue("./dataForCakes.txt"); }
  void addToWaitingQueue(const Cake &cake) { waitingQueue.push(cake); }
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
          Cake cake(static_cast<CakeShape>(shape),
                    static_cast<CakeGlazing>(glazing),
                    static_cast<CakeFlavor>(flavor),
                    static_cast<CakeSprinkles>(sprinkles), id);
          addToWaitingQueue(cake);
        } else {
          // Handle invalid line format
          std::cerr << "Invalid line format in file: " << line << std::endl;
        }
      }
      file.close();
    } else {
      // Handle file not found or other errors
      std::cerr << "Unable to open file: " << filename << std::endl;
    }
  }
  void simulateQueue(int numSimulations) {
    // Check if the waiting queue has enough items to simulate
    if (waitingQueue.size() < numSimulations) {
      std::cerr << "Not enough items in the waiting queue for simulation."
                << std::endl;
      return;
    }

    // Simulate popping and pushing back into the waiting queue
    for (int i = 0; i < numSimulations; ++i) {
      Cake frontCake = waitingQueue.front();
      waitingQueue.pop();
      waitingQueue.push(frontCake);

      // Print information about the simulated cake
      std::cout << "Simulated Cake - ID: " << frontCake.getId()
                << ", Shape: " << static_cast<int>(frontCake.getShape())
                << ", Glazing: " << static_cast<int>(frontCake.getGlazing())
                << ", Flavor: " << static_cast<int>(frontCake.getFlavor())
                << ", Sprinkles: " << static_cast<int>(frontCake.getSprinkles())
                << std::endl;
    }
  }
  // Function to get the front cake from the waiting queue
  Cake getFrontCakeFromQueue() {
    if (!waitingQueue.empty()) {
      Cake frontCake = waitingQueue.front();
      waitingQueue.pop();
      return frontCake;
    } else {
      // Handle empty queue case (return a default cake or throw an exception)
      return Cake();
    }
  }
  // code
};
#endif //
