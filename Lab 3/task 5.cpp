#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node *next;
    Node(int v) {
        value = v;
        next = nullptr;
    }
};

class StockSystem {
    Node *first;
    Node *last;
public:
    StockSystem() {
        first = nullptr;
        last = nullptr;
    }

    void insertItem(int v) {
        Node *node = new Node(v);
        if(first == nullptr) {
            first = node;
            last = node;
        } else {
            last->next = node;
            last = node;
        }
        cout << "Added product with code " << v << endl;
    }

    void showItems() {
        if(first == nullptr) {
            cout << "No products in stock." << endl;
            return;
        }
        cout << "Current stock: ";
        Node *temp = first;
        while(temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void arrangeItems() {
        if(first == nullptr || first->next == nullptr) {
            cout << "Not enough products to arrange." << endl;
            return;
        }
        for(Node *i = first; i != nullptr; i = i->next) {
            for(Node *j = i->next; j != nullptr; j = j->next) {
                if(i->value > j->value) {
                    swap(i->value, j->value);
                }
            }
        }
        cout << "Products arranged in order." << endl;
    }
};

int main() {
    StockSystem stock;
    stock.insertItem(12);
    stock.insertItem(10);
    stock.insertItem(32);

    cout << "\nBefore arranging:" << endl;
    stock.showItems();

    stock.insertItem(5);
    cout << "\nAfter adding one more product:" << endl;
    stock.showItems();

    stock.arrangeItems();
    cout << "\nAfter arranging:" << endl;
    stock.showItems();
}
