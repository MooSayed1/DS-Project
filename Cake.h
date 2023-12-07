#ifndef CAKE_H
#define CAKE_H
#include <iostream>
#include <vector>
using namespace std;
class Cake {
private:
  string name;
  vector<string> ingredients;
  string recipe;

public:
  // Getter functions
  string getName() const { return name; }
  vector<string> getIngredients() const { return ingredients; }
  string getRecipe() const { return recipe; }

  // Setter functions
  void setName(const string &cake_name) { name = cake_name; }
  void setIngredients(const vector<string> &cake_ingredients) {
    ingredients = cake_ingredients;
  }
  void setRecipe(const string &cake_recipe) { recipe = cake_recipe; }

  // Constructor
  Cake(const string &cake_name, const vector<string> &cake_ingredients,
       const string &cake_recipe)
      : name(cake_name), ingredients(cake_ingredients), recipe(cake_recipe) {}
  // friend ostream &operator>>(&istream in, &Cake cake) { return in; }
};
#endif // CAKE_H
