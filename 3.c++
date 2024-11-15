#include <iostream>
using namespace std;

class Base {
public:
    int baseValue;

    Base() : baseValue(10) { 
        cout << "Base class constructor called.\n"; 
    }

    ~Base() {
        cout << "Base class destructor called.\n";
    }

    void displayBase() const {
        cout << "Base class value: " << baseValue << endl;
    }
};

class Derived : public Base {
public:
    int derivedValue;

    Derived() : derivedValue(baseValue) {
        cout << "Derived class constructor called.\n";
    }

    ~Derived() {
        cout << "Derived class destructor called.\n";
    }

    void displayDerived() const {
        cout << "Derived class value: " << derivedValue << endl;
    }
};

int main() {
    Derived obj;
    obj.displayBase();
    obj.displayDerived();
    return 0;
}
