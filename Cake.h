#ifndef CAKE_H
#define CAKE_H

#include <cstdio>
#include <iostream>

using namespace std;

class Cake {
private:
    int shape;        
    int glazing;      
    int flavor;       
    int sprinkles;   
    int id;
    int status;       

public:
    // Constructor
    Cake(int sh, int g, int f, int s, int d)
        : shape(sh), glazing(g), flavor(f), sprinkles(s), id(d), status(0) {}  // Default status: WAITING

    // Default constructor
    Cake()
        : shape(0), glazing(0), flavor(0), sprinkles(0), id(-1), status(0) {}  // Default status: WAITING

    // Getter and setter functions for status
    int getStatus() const { return status; }
    void setStatus(int s) { status = s; }

    int getShape() const { return shape; }
    int getGlazing() const { return glazing; }
    int getFlavor() const { return flavor; }
    int getSprinkles() const { return sprinkles; }
    int getId() const { return id; }
};

#endif // CAKE_H
