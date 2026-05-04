#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string name;
    double balance;

public:
    void createAccount() {
        cout << "\nEnter Account Number: ";
        cin >> accountNumber;
        cin.ignore();

        cout << "Enter Customer Name: ";
        getline(cin, name);

        cout << "Enter Initial Balance: ";
        cin >> balance;

        saveToFile();
        cout << "\nAccount created successfully!\n";
    }

    void deposit() {
        int accNo;
        double amount;

        cout << "\nEnter Account Number: ";
        cin >> accNo;

        if (searchAccount(accNo)) {
            cout << "Enter Amount to Deposit: ";
            cin >> amount;

            balance += amount;
            updateFile();

            cout << "\nAmount deposited successfully!\n";
            cout << "Updated Balance: " << balance << endl;
        } else {
            cout << "\nAccount not found!\n";
        }
    }

    void withdraw() {
        int accNo;
        double amount;

        cout << "\nEnter Account Number: ";
        cin >> accNo;

        if (searchAccount(accNo)) {
            cout << "Enter Amount to Withdraw: ";
            cin >> amount;

            if (amount <= balance) {
                balance -= amount;
                updateFile();

                cout << "\nAmount withdrawn successfully!\n";
                cout << "Remaining Balance: " << balance << endl;
            } else {
                cout << "\nInsufficient balance!\n";
            }
        } else {
            cout << "\nAccount not found!\n";
        }
    }

    void checkBalance() {
        int accNo;

        cout << "\nEnter Account Number: ";
        cin >> accNo;

        if (searchAccount(accNo)) {
            cout << "\nAccount Number: " << accountNumber << endl;
            cout << "Customer Name: " << name << endl;
            cout << "Balance: " << balance << endl;
        } else {
            cout << "\nAccount not found!\n";
        }
    }

    void displayAllAccounts() {
        ifstream file("bank_records.txt");

        if (!file) {
            cout << "\nNo records found!\n";
            return;
        }

        cout << "\n--- All Customer Records ---\n";

        while (file >> accountNumber) {
            file.ignore();
            getline(file, name);
            file >> balance;

            cout << "\nAccount Number: " << accountNumber;
            cout << "\nCustomer Name: " << name;
            cout << "\nBalance: " << balance << endl;
        }

        file.close();
    }

    void saveToFile() {
        ofstream file("bank_records.txt", ios::app);

        file << accountNumber << endl;
        file << name << endl;
        file << balance << endl;

        file.close();
    }

    bool searchAccount(int accNo) {
        ifstream file("bank_records.txt");

        while (file >> accountNumber) {
            file.ignore();
            getline(file, name);
            file >> balance;

            if (accountNumber == accNo) {
                file.close();
                return true;
            }
        }

        file.close();
        return false;
    }

    void updateFile() {
        ifstream file("bank_records.txt");
        ofstream temp("temp.txt");

        int accNo;
        string custName;
        double bal;

        while (file >> accNo) {
            file.ignore();
            getline(file, custName);
            file >> bal;

            if (accNo == accountNumber) {
                temp << accountNumber << endl;
                temp << name << endl;
                temp << balance << endl;
            } else {
                temp << accNo << endl;
                temp << custName << endl;
                temp << bal << endl;
            }
        }

        file.close();
        temp.close();

        remove("bank_records.txt");
        rename("temp.txt", "bank_records.txt");
    }
};

int main() {
    BankAccount account;
    int choice;

    do {
        cout << "\n====== Bank Management Application ======\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Amount\n";
        cout << "3. Withdraw Amount\n";
        cout << "4. Check Balance\n";
        cout << "5. Display All Accounts\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            account.createAccount();
            break;

        case 2:
            account.deposit();
            break;

        case 3:
            account.withdraw();
            break;

        case 4:
            account.checkBalance();
            break;

        case 5:
            account.displayAllAccounts();
            break;

        case 6:
            cout << "\nThank you for using Bank Management Application!\n";
            break;

        default:
            cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}
