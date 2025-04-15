#include <iostream>
using namespace std;

class Government {
private:
    static Government* instance;

    // Private constructor to prevent instantiation
    Government() {
        cout << "\nA new government has been formed." << endl;
    }

public:
    // Static method to get the singleton instance
    static Government* getInstance() {
        if (instance == nullptr) {
            instance = new Government();
        }
        return instance;
    }

    void govern(const string& message) {
        cout << "Government action: " << message << endl;
    }
};

// Initialize the static member
Government* Government::instance = nullptr;

int main() {
    Government* Gov1 = Government::getInstance();
    Government* Gov2 = Government::getInstance();

    Gov1->govern("Implementing new policies.");
    Gov2->govern("Addressing national security.");

    cout << "Gov1 and Gov2 are the same Government: "
         << (Gov1 == Gov2 ? "true" : "false") << endl;

    return 0;
}
