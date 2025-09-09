#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};
class StudentSystem
{
    Node *head;
    Node *current;

public:
    StudentSystem()
    {
        head = nullptr;
        current = nullptr;
    }
    void addStudent(int rollNumber)
    {
        Node *newNode = new Node(rollNumber);
        newNode->next = nullptr;
        if (head == nullptr)
        {
            head = current = newNode;
            return;
        }
        current->next = newNode;
        current = newNode;
    }
    void removeStudent(int rollNumber)
    {
        if (head == nullptr)
        {
            cout << "No students in the system." << endl;
            return;
        }
        if (head->data == rollNumber)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            if (head == nullptr)
            {
                current = nullptr;
            }
            cout << "Student with roll number " << rollNumber << " has been removed." << endl;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr && temp->next->data != rollNumber)
        {
            temp = temp->next;
        }
        if (temp->next == nullptr)
        {
            cout << "Student with roll number " << rollNumber << " not found." << endl;
            return;
        }
        Node *toDelete = temp->next;
        temp->next = temp->next->next;
        if (temp->next == nullptr)
        {
            current = temp;
        }
        cout << "Student with roll number " << rollNumber << " has been removed."
             << endl;
        delete toDelete;
    }
    void displayStudents()
    {
        if (head == nullptr)
        {
            cout << "No students in the system." << endl;
            return;
        }
        Node *temp = head;
        cout << "Students in the system: ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    StudentSystem s;
    s.addStudent(232);
    s.addStudent(123);

    s.displayStudents();
    s.removeStudent(232);

    s.displayStudents();
    return 0;
}