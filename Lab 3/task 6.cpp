#include <iostream>
using namespace std;

struct Node
{
    int taskID;
    Node *next;
    Node(int id)
    {
        taskID = id;
        next = nullptr;
    }
};

class TaskList
{
public:
    Node *head;
    TaskList()
    {
        head = nullptr;
    }

    void addTask(int id)
    {
        Node *newNode = new Node(id);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    static Node *mergeLists(Node *l1, Node *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        if (l1->taskID <= l2->taskID)
        {
            l1->next = mergeLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeLists(l1, l2->next);
            return l2;
        }
    }

    void displayTasks()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->taskID << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    TaskList list1, list2, merged;

    list1.addTask(1001);
    list1.addTask(1003);
    list1.addTask(1005);

    list2.addTask(1002);
    list2.addTask(1004);
    list2.addTask(1006);

    merged.head = TaskList::mergeLists(list1.head, list2.head);

    merged.displayTasks();

    return 0;
}