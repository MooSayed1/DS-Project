
#ifndef CAKEFACTORY_H
#define CAKEFACTORY_H
#include<iostream>
#include "Cake.h"
#include "Subll.h"
#include "Stack.h"
using namespace std;
class cakeFactory{
private:
  Subll<Stack<string>>fact;

public:
    // Getter function
    vector<Cake> getCakes() const { return cakes; }

    // Setter function
    void setCakes(const vector<Cake>& cake_list) { cakes = cake_list; }

    void createNewCake(const string& cake_name, const vector<string>& ingredients, const string& recipe) {
        Cake new_cake(cake_name, ingredients, recipe);
        cakes.push_back(new_cake);

        cout << "New cake created: " << cake_name << endl;
    }

    void processOrder(int order_id, const string& cake_name, int quantity) {
        // Logic to process an order and produce cakes
        // ...

        cout << "Order processed: " << quantity << " " << cake_name << " cakes for order ID " << order_id << endl;
    }

    void performQualityCheck(int batch_id) {
        // Logic to conduct quality checks on a batch of cakes
        // ...

        cout << "Quality check completed for batch ID " << batch_id << endl;
    }
};
#endif // 
