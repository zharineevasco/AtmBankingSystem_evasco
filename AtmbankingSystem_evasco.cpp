#include <iostream>
#include <fstream>
using namespace std;

class Account {

public:
    int id;
    string accountName;
    string accountPin;
    double accountBalance;

    void checkBalance() {
        cout << "\nBalance: " << accountBalance << endl;
    }

    void deposit(double amount) {
        accountBalance += amount;
        cout << "Deposit successful!" << endl;
    }

    void withdraw(double amount) {

        if(amount > accountBalance) {
            cout << "Insufficient balance!" << endl;
        }
        else {
            accountBalance -= amount;
            cout << "Withdraw successful!" << endl;
        }
    }

    void changePin(string newPin) {
        accountPin = newPin;
        cout << "PIN changed successfully!" << endl;
    }
};

int main() {

    Account user[5];

   
    ifstream infile("accounts.txt");

    if(!infile) {
        cout << "File not found!" << endl;
        return 0;
    }

    // READ FILE
    for(int i = 0; i < 5; i++) {

        infile >> user[i].id
               >> user[i].accountName
               >> user[i].accountPin
               >> user[i].accountBalance;
    }

    infile.close();

    // LOGIN
    string inputName, inputPin;
    int index = -1;

    cout << "===== ATM LOGIN =====" << endl;

    cout << "Enter Name: ";
    cin >> inputName;

    cout << "Enter PIN: ";
    cin >> inputPin;

   
    for(int i = 0; i < 5; i++) {

        if(user[i].accountName == inputName &&
           user[i].accountPin == inputPin) {

            index = i;
            break;
        }
    }

    if(index == -1) {
        cout << "Invalid login!" << endl;
        return 0;
    }

    int choice;
    double amount;
    string newPin;

    do {

        cout << "\n===== ATM MENU =====" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Change PIN" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                user[index].checkBalance();
                break;

            case 2:
                cout << "Enter amount: ";
                cin >> amount;

                user[index].deposit(amount);
                break;

            case 3:
                cout << "Enter amount: ";
                cin >> amount;

                user[index].withdraw(amount);
                break;

            case 4:
                cout << "Enter new PIN: ";
                cin >> newPin;

                user[index].changePin(newPin);
                break;

            case 5:
                cout << "Thank you for using ATM!" << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while(choice != 5);

 
    ofstream outfile("accounts.txt");

    for(int i = 0; i < 5; i++) {

        outfile << user[i].id << " "
                << user[i].accountName << " "
                << user[i].accountPin << " "
                << user[i].accountBalance << endl;
    }

    outfile.close();

    return 0;
}
