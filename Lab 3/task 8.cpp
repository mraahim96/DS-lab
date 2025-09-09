#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList
{
    Node *head;
    Node *current;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        current = nullptr;
    }

    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
            current = newNode;
        }
        else
        {
            current->next = newNode;
            newNode->prev = current;
            current = newNode;
        }
        cout << "Value " << val << " inserted at End" << endl;
    }

    void deleteAtFront()
    {
        if (head == nullptr)
        {
            cout << "List is empty, nothing to delete" << endl;
            return;
        }
        Node *temp = head;
        if (head->next == nullptr)
        {
            head = nullptr;
            current = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        cout << "Value deleted from front" << endl;
    }

    bool search(int val)
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return false;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == val)
            {
                cout << "Value " << val << " found" << endl;
                return true;
            }
            temp = temp->next;
        }
        cout << "Value " << val << " not found" << endl;
        return false;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        cout << "List: ";
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
    DoublyLinkedList list;
    list.insertAtEnd(1001);
    list.insertAtEnd(1002);
    list.insertAtEnd(1003);
    list.insertAtEnd(1004);

    list.display();

    list.deleteAtFront();
    list.display();

    list.search(1003);
    list.search(10);
    list.search(1001);
}
