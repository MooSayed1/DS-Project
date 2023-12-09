#ifndef CAKE_H
#define CAKE_H
#include <iostream>
#include <vector>
using namespace std;
class Cake {
private:
  // vector<string> ingredients;
int shape,glazing,flavor,sprinkles,id;


public:
    // Constructor
    Cake(int sh, int g, int f, int s, int d)
        : shape(sh), glazing(g), flavor(f), sprinkles(s), id(d) {}

    // Default constructor
    Cake()
        : shape(-1), id(-1), glazing(-1), flavor(-1), sprinkles(-1) {}

    // Setter functions
    void setShape(int sh) { shape = sh; }
    void setGlazing(int g) { glazing = g; }
    void setFlavor(int f) { flavor = f; }
    void setSprinkles(int s) { sprinkles = s; }
    void setId(int d) { id = d; }

    // Getter functions
    int getShape() const { return shape; }
    int getGlazing() const { return glazing; }
    int getFlavor() const { return flavor; }
    int getSprinkles() const { return sprinkles; }
    int getId() const { return id; }

    // Member function to display cake data
    void displayData() const {
        std::cout << "Cake ID: " << getId() << "\n";
        std::cout << "Shape: " << getShape() << "\n";
        std::cout << "Glazing: " << getGlazing() << "\n";
        std::cout << "Flavor: " << getFlavor() << "\n";
        std::cout << "Sprinkles: " << getSprinkles() << "\n";
  }
  void addData() {
    //what you need to add yaaa AZOOZ
  }
};
#endif // CAKE_H
