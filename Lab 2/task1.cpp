#include <iostream>
using namespace std;

class StudentFeeManager {
private:
    int* fees;
    int size;

public:
    StudentFeeManager(int n, int initialFee) {
        size = n;
        fees = new int[size];
        for (int i = 0; i < size; i++) {
            fees[i] = initialFee;
        }
    }

    StudentFeeManager(const StudentFeeManager& other) {
        size = other.size;
        fees = new int[size];
        for (int i = 0; i < size; i++) {
            fees[i] = other.fees[i];
        }
    }

    StudentFeeManager& operator=(const StudentFeeManager& other) {
        if (this != &other) {
            delete[] fees;
            size = other.size;
            fees = new int[size];
            for (int i = 0; i < size; i++) {
                fees[i] = other.fees[i];
            }
        }
        return *this;
    }

    ~StudentFeeManager() {
        delete[] fees;
    }

    void setFee(int index, int amount) {
        if (index >= 0 && index < size) {
            fees[index] = amount;
        }
    }

    void display() const {
        cout << "Student Fees: ";
        for (int i = 0; i < size; i++) {
            cout << fees[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    StudentFeeManager student1(2, 1000);
    cout << "Original Fees: ";
    student1.display();

    StudentFeeManager student2 = student1;
    student2.setFee(1, 4231);

    cout << "After modifying:" << endl;
    cout << "student1: ";
    student1.display();
    cout << "student2: ";
    student2.display();

    return 0;
}
