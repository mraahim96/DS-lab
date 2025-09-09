#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string id;
    int courses;
    int* scores;

public:
    Student() {
        id = "";
        courses = 0;
        scores = nullptr;
    }

    void getData() {
        cout << "Student ID: ";
        cin >> id;
        cout << "Total courses: ";
        cin >> courses;
        scores = new int[courses];
        for (int i = 0; i < courses; i++) {
            cout << "Score for course " << i + 1 << ": ";
            cin >> scores[i];
        }
    }

    void showData() {
        cout << id << "\t" << courses << "\t";
        for (int i = 0; i < courses; i++) {
            cout << scores[i];
            if (i < courses - 1) cout << ", ";
        }
        cout << endl;
    }

    ~Student() {
        delete[] scores;
    }
};

int main() {
    int n;
    cout << "How many students? ";
    cin >> n;

    Student list[n];
    for (int i = 0; i < n; i++) {
        cout << "\n--- Student " << i + 1 << " ---\n";
        list[i].getData();
    }

    cout << "\nID\tCourses\tMarks\n";
    for (int i = 0; i < n; i++) {
        list[i].showData();
    }
    return 0;
}
