#include <iostream>
using namespace std;

class Node
{
public:
    int PhotoID;
    Node *next;
    Node(int id)
    {
        PhotoID = id;
        next = nullptr;
    }
};

class GalleryApp
{
private:
    Node *head;

public:
    GalleryApp()
    {
        head = nullptr;
    }

    void addPhoto(int id)
    {
        Node *newPhoto = new Node(id);
        if (head == nullptr)
        {
            head = newPhoto;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newPhoto;
        }
    }

    void display()
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;
        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << "Photo ID: " << temp->PhotoID << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    int n;
    GalleryApp App1;
    cout << "Enter number of photos: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int id;
        cout << "Enter photo ID: ";
        cin >> id;
        App1.addPhoto(id);
    }
    App1.display();
    return 0;
}
