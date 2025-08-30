#include <iostream>
using namespace std;

class Box {
private:
    int* value;

public:
    Box(int v = 0) {
        value = new int(v);
    }

    ~Box() {
        delete value;
        cout << "Destructor called" << endl;
    }

    Box(const Box& other) {
        value = new int(*other.value);
        cout << "Copy constructor" << endl;
    }

    Box& operator=(const Box& other) {
        if (this != &other) {
            delete value;
            value = new int(*other.value);
            cout << "Copy assignment" << endl;
        }
        return *this;
    }

    void setValue(int v) {
        *value = v;
    }

    int getValue() const {
        return *value;
    }
};

int main() {
    cout << "Deep Copy Example" << endl;
    Box box1(200);
    cout << "Box1 value: " << box1.getValue() << endl;

    Box box2 = box1; 
    cout << "Box2 value after copy constructor: " << box2.getValue() << endl;

    box2.setValue(500);
    cout << "Box1 value: " << box1.getValue() << endl;
    cout << "Box2 value: " << box2.getValue() << endl;

    Box box3;
    box3 = box1; 
    cout << "Box3 value after copy assignment: " << box3.getValue() << endl;

    box3.setValue(800);
    cout << "Box1 value: " << box1.getValue() << endl;
    cout << "Box3 value: " << box3.getValue() << endl;

    return 0;
}
