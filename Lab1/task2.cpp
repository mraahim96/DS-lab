#include<iostream>
#include<cstring>
using namespace std;

class Exam
{
private:
   char* studentName; 
   char* examDate;
   int score;
public:
    Exam(const char* name, const char* date, int s) {
        studentName = new char[strlen(name) + 1];
        strcpy(studentName, name);
        examDate = new char[strlen(date) + 1];
        strcpy(examDate, date);
        score = s;
    }

    ~Exam() {
        delete[] studentName;
        delete[] examDate;
        cout << "Destructor called" << endl;
    }

    void setExamDetails(const char* name, const char* date, int s) {
        delete[] studentName;
        delete[] examDate;
        studentName = new char[strlen(name) + 1];
        strcpy(studentName, name);
        examDate = new char[strlen(date) + 1];
        strcpy(examDate, date);
        score = s;
    }

    void display() const {
        cout << "Student Name: " << studentName << endl;
        cout << "Exam Date   : " << examDate << endl;
        cout << "Score       : " << score << endl;
    }
};

int main() {
    Exam exam1("Sparrow", "12-Oct-2025", 80);
    cout << "Exam1 details:" << endl;
    exam1.display();

    cout << "-----------------------------" << endl;

    Exam exam2 = exam1;
    cout << "Exam2 details:" << endl;
    exam2.display();

    cout << "-----------------------------" << endl;
    return 0;
}
