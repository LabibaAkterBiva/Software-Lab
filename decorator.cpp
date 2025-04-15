#include <iostream>
using namespace std;

// Abstract Base Pizza class
class BasePizza {
public:
    virtual int cost() = 0;
    virtual ~BasePizza() {}
};

// Concrete Pizza types
class Farmhouse : public BasePizza {
public:
    int cost() override {
        return 200;
    }
};

class VegDelight : public BasePizza {
public:
    int cost() override {
        return 100;
    }
};

class Margeright : public BasePizza {
public:
    int cost() override {
        return 180;
    }
};

// Abstract Topping Decorator
class ToppingDecorator : public BasePizza {
protected:
    BasePizza* basePizza;
public:
    ToppingDecorator(BasePizza* pizza) : basePizza(pizza) {}
    virtual ~ToppingDecorator() {
        delete basePizza;
    }
};

// Concrete Toppings
class ExtraCheese : public ToppingDecorator {
public:
    ExtraCheese(BasePizza* pizza) : ToppingDecorator(pizza) {}
    int cost() override {
        return basePizza->cost() + 10;
    }
};

class Mashroom : public ToppingDecorator {
public:
    Mashroom(BasePizza* pizza) : ToppingDecorator(pizza) {}
    int cost() override {
        return basePizza->cost() + 15;
    }
};

// Main function to test
int main() {
    BasePizza* pizza = new Mashroom(new ExtraCheese(new Margeright()));
    cout << "Total cost: " << pizza->cost() << endl;

    delete pizza; // Free memory
    return 0;
}
