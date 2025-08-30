#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:

    BankAccount() {
        balance = 0.0;
        cout << "Default constructor called. Balance is $0.0" << endl;
    }

   
    BankAccount(double iniBalance) {
        balance = iniBalance;
        cout << "Parameterized constructor called. Balance set to $" << balance << endl;
    }

   
    BankAccount(const BankAccount &other) {
        balance = other.balance;
        cout << "Copy constructor called. Balance copied: $" << balance << endl;
    }

    void deposit(double amount) {
        balance += amount;
    }

   
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }

   
    void printBalance() const {
        cout << "Current balance: $" << balance << endl;
    }
};

int main() {
 
    BankAccount account1;
    cout << "\nAccount1 "; 
    account1.printBalance();

    BankAccount account2(1000.0);
    cout << "\nAccount2 ";
    account2.printBalance();

    BankAccount account3(account2);  
    account3.withdraw(200.0);        

    cout << "\nAfter withdrawing $200 from account3:" << endl;
    cout << "Account3 "; 
    account3.printBalance();
    cout << "Account2 ";
    account2.printBalance();  

    return 0;
}
