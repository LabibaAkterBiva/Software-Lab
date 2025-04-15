#include <iostream>
using namespace std;

// AppleCharger interface (abstract class)
class AppleCharger {
public:
    virtual void chargePhone() = 0;
    virtual ~AppleCharger() = default;
};

// Iphone13 class
class Iphone13 {
private:
    AppleCharger* appleCharger;
public:
    Iphone13(AppleCharger* charger) : appleCharger(charger) {}

    void chargeIphone() {
        appleCharger->chargePhone();
    }
};

// ChargerXYZ class implementing AppleCharger
class ChargerXYZ : public AppleCharger {
public:
    void chargePhone() override {
        cout << "Your iPhone is charging" << endl;
    }
};

// AndroidCharger interface (abstract class)
class AndroidCharger {
public:
    virtual void chargerAndroidPhone() = 0;
    virtual ~AndroidCharger() = default;
};

// DkCharger class implementing AndroidCharger
class DkCharger : public AndroidCharger {
public:
    void chargerAndroidPhone() override {
        cout << "Your Android phone is charging" << endl;
    }
};

// AdapterCharger class implementing AppleCharger using AndroidCharger
class AdapterCharger : public AppleCharger {
private:
    AndroidCharger* charger;
public:
    AdapterCharger(AndroidCharger* charger) : charger(charger) {}

    void chargePhone() override {
        charger->chargerAndroidPhone();
        cout << "Your phone is charging with Adapter" << endl;
    }
};

// Demo (main function)
int main() {
    cout << "Hello, World!" << endl;

    // Using AdapterCharger to charge iPhone with AndroidCharger
    AppleCharger* charger = new AdapterCharger(new DkCharger());
    Iphone13 iphone13(charger);
    iphone13.chargeIphone();

    delete charger;  // Freeing memory
    return 0;
}
