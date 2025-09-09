#include <iostream>
using namespace std;

class ProductStockManager {
private:
    int* stock;
    int count;

public:
    ProductStockManager(int n, int init) {
        count = n;
        stock = new int[count];
        for (int i = 0; i < count; i++) {
            stock[i] = init;
        }
    }

    ProductStockManager(const ProductStockManager& other) {
        count = other.count;
        stock = new int[count];
        for (int i = 0; i < count; i++) {
            stock[i] = other.stock[i];
        }
    }

    ProductStockManager& operator=(const ProductStockManager& other) {
        if (this != &other) {
            delete[] stock;
            count = other.count;
            stock = new int[count];
            for (int i = 0; i < count; i++) {
                stock[i] = other.stock[i];
            }
        }
        return *this;
    }

    ~ProductStockManager() {
        delete[] stock;
    }

    void updateStock(int idx, int qty) {
        if (idx >= 0 && idx < count) {
            stock[idx] = qty;
        }
    }

    void show() const {
        for (int i = 0; i < count; i++) {
            cout << stock[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ProductStockManager p1(5, 230);
    cout << "p1 initial: ";
    p1.show();

    ProductStockManager p2 = p1;
    p2.updateStock(1, 210);

    cout << "After change:\n";
    cout << "p1: ";
    p1.show();
    cout << "p2: ";
    p2.show();

    return 0;
}
