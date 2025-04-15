#include <iostream>
using namespace std;

// Abstract base class (Transport interface)
class Transport {
public:
    virtual void deliver() = 0;  // Pure virtual function
    virtual ~Transport() = default;  // Virtual destructor
};

// Concrete class: Truck
class Truck : public Transport {
public:
    void deliver() override {
        cout << "Delivering by land in a box truck." << endl;
    }
};

// Concrete class: Ship
class Ship : public Transport {
public:
    void deliver() override {
        cout << "Delivering by sea in a container ship." << endl;
    }
};

// Enum to represent transport types
enum TransportType {
    TRUCK,
    SHIP
};

// Factory class to create appropriate Transport objects
class TransportFactory {
public:
    static Transport* createTransport(TransportType type) {
        switch (type) {
            case TRUCK: return new Truck();
            case SHIP: return new Ship();
            default: return nullptr;
        }
    }
};

// Main function to test the transport creation and delivery
int main() {
    // Create Truck
    Transport* transport = TransportFactory::createTransport(TRUCK);
    if (transport) {
        transport->deliver();
        delete transport;
    }

    // Create Ship
    transport = TransportFactory::createTransport(SHIP);
    if (transport) {
        transport->deliver();
        delete transport;
    }

    return 0;
}
