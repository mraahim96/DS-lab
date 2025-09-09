#include <iostream>
#include <cstring>
using namespace std;

class FruitShopInventory {
private:
    int totalFruits;
    int details;
    int** records;

    int& safe(int r, int c) {
        if (r < 0 || r >= totalFruits || c < 0 || c >= details) {
            throw out_of_range("Invalid index!");
        }
        return records[r][c];
    }

public:
    FruitShopInventory(int count, int startQty, int startPrice) {
        totalFruits = count;
        details = 2;
        records = new int*[totalFruits];
        for (int i = 0; i < totalFruits; i++) {
            records[i] = new int[details];
            records[i][0] = startQty;
            records[i][1] = startPrice;
        }
    }

    FruitShopInventory(const FruitShopInventory& other) {
        totalFruits = other.totalFruits;
        details = other.details;
        records = new int*[totalFruits];
        for (int i = 0; i < totalFruits; i++) {
            records[i] = new int[details];
            for (int j = 0; j < details; j++) {
                records[i][j] = other.records[i][j];
            }
        }
    }

    FruitShopInventory& operator=(const FruitShopInventory& other) {
        if (this == &other) return *this;
        for (int i = 0; i < totalFruits; i++) delete[] records[i];
        delete[] records;
        totalFruits = other.totalFruits;
        details = other.details;
        records = new int*[totalFruits];
        for (int i = 0; i < totalFruits; i++) {
            records[i] = new int[details];
            for (int j = 0; j < details; j++) {
                records[i][j] = other.records[i][j];
            }
        }
        return *this;
    }

    ~FruitShopInventory() {
        for (int i = 0; i < totalFruits; i++) {
            delete[] records[i];
        }
        delete[] records;
    }

    void changeStock(int index, int quantity, int price) {
        safe(index, 0) = quantity;
        safe(index, 1) = price;
    }

    void printInventory(const string items[]) {
        cout << "\nFruit Market Inventory\n";
        for (int i = 0; i < totalFruits; i++) {
            cout << items[i] 
                 << " -> " << safe(i, 0) << " pcs"
                 << " | Rs. " << safe(i, 1) << "\n";
        }
        cout << endl;
    }
};

int main() {
    string fruits[] = {"Bananas", "Apples", "Grapes"};
    FruitShopInventory mainShop(3, 20, 50);

    cout << "Main Shop:";
    mainShop.printInventory(fruits);

    FruitShopInventory branchShop = mainShop;

    mainShop.changeStock(2, 35, 60); 

    cout << "Main Shop (after update):";
    mainShop.printInventory(fruits);

    cout << "Branch Shop:";
    branchShop.printInventory(fruits);

    return 0;
}
