#include <iostream>
#include <string>
using namespace std;

class Shop {
private:
    string productName;
    int* quantities;
    int NumberOfBranches;

public:
    Shop(const string& name, int branches) {
        productName = name;
        NumberOfBranches = branches;
        quantities = new int[NumberOfBranches];
        for (int i = 0; i < NumberOfBranches; i++) {
            quantities[i] = 0;
        }
    }

    Shop(const Shop& other) {
        productName = other.productName;
        NumberOfBranches = other.NumberOfBranches;
        quantities = new int[NumberOfBranches];
        for (int i = 0; i < NumberOfBranches; i++) {
            quantities[i] = other.quantities[i];
        }
    }

    Shop& operator=(const Shop& other) {
        if (this != &other) {
            delete[] quantities;
            productName = other.productName;
            NumberOfBranches = other.NumberOfBranches;
            quantities = new int[NumberOfBranches];
            for (int i = 0; i < NumberOfBranches; i++) {
                quantities[i] = other.quantities[i];
            }
        }
        return *this;
    }

    ~Shop() {
        delete[] quantities;
    }

    void setQuantity(int branch, int qty) {
        if (branch >= 0 && branch < NumberOfBranches) {
            quantities[branch] = qty;
        }
    }

    void display() const {
        cout << "Product: " << productName << endl;
        for (int i = 0; i < NumberOfBranches; i++) {
            cout << "Branch " << i + 1 << ": " << quantities[i] << endl;
        }
    }
};

int main() {
    Shop s1("Iphone", 3);
    s1.setQuantity(0, 10);
    s1.setQuantity(1, 25);
    s1.setQuantity(2, 20);

    Shop s2 = s1;
    s2.setQuantity(0, 89);

    Shop s3("Nvidia", 2);
    s3 = s1;

    s1.display();
    s2.display();
    s3.display();
}
