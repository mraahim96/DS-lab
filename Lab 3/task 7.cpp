
#include<iostream>
using namespace std;
struct Node {
    int SeatID;
    bool reserved;
    Node* next;

    Node(int id) {
        SeatID = id;
        reserved = false;
        next = nullptr;
    }
};


class RideManagementSystem{
    Node* head;
    int total_seats;
public:
    RideManagementSystem(int n){
        head = nullptr;
        total_seats = n;
        createSeats(n);
    }
    void createSeats(int n){
        if(total_seats <= 0) return;
        Node* prev = nullptr;
        for(int i =1 ;i<=total_seats;i++){
            Node* newSeat = new Node(i);
            if(head == nullptr){
                head = newSeat;
            } else {
                prev->next = newSeat;
            }
            prev = newSeat;
        }
        prev->next = head;
    }
    void reserveSeat(int id){
        if(id<1 || id>total_seats){
            cout<<"Invalid seat ID"<<endl;
            return;
        }
        Node* temp = head;
        for(int i=1;i<id;i++){
            temp = temp->next;
        }
        if(temp->reserved){
            cout<<"Seat "<<id<<" is already reserved."<<endl;
        } else {
            temp->reserved = true;
            cout<<"Seat "<<id<<" reserved successfully."<<endl;
        }
        return;
    }   
    void display(){
        if(head == nullptr) return;
        Node* temp = head;
        do{
            cout<<"Seat ID: "<<temp->SeatID<<" - "<<(temp->reserved ? "Reserved" : "Available")<<endl;
            temp = temp->next;
        }while(temp != head);
    }
    ~RideManagementSystem(){
        if(head == nullptr) return;
        Node* temp = head->next;
        while(temp != head){
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
        delete head;
    }
};
int main(){
    int n;
    cout<<"Enter total number of seats: ";
    cin>>n;
    RideManagementSystem System(n);
    System.display();
    int choice, seat_id;
    do{
        cout<<"1. Reserve Seat\n2. Display Seats\n3. Exit\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter seat ID to reserve: ";
                cin>>seat_id;
                System.reserveSeat(seat_id);
                break;
            case 2:
                System.display();
                break;
            case 3:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid choice. Try again."<<endl;
        }
    }while(choice != 3);
    return 0;
}