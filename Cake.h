#ifndef CAKE_H
#define CAKE_H
#include <cstdio>
#include <iostream>
using namespace std;
  enum class CakeShape {
    ROUND,
    SQUARE,
    RECTANGLE,
    TRIANGLE,
  };

  enum class CakeGlazing {
    CHOCOLATE,
    VANILLA,
    STRAWBERRY,
  };

  enum class CakeFlavor {
    CHOCOLATE,
    VANILLA,
    STRAWBERRY,
  };

  enum class CakeSprinkles {
    GREANLEAF,
    HEART,
    JELLYBEANS,
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
          flavor(CakeFlavor::VANILLA), sprinkles(CakeSprinkles::JELLYBEANS), id(-1),
          status(CakeStatus::WAITING) {}

    // Getter and setter functions for status
    CakeStatus getStatus() const { return status; }
    void setStatus(CakeStatus s) { status = s; }

    CakeShape getShape() const { return shape; }
    CakeGlazing getGlazing() const { return glazing; }
    CakeFlavor getFlavor() const { return flavor; }
    CakeSprinkles getSprinkles() const { return sprinkles; }
    int getId() const { return id; }
  };

#endif // CAKE_H
