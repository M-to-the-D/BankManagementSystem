#include <iostream>
#include <string>
#include <cstdlib> // For sprintf

using namespace std;

const int MAX_ACCOUNTS = 10; // Maximum number of accounts

// Define a structure to represent an account
struct Account {
    string accountNumber;
    string accountHolderName;
    double balance;
    string transactions[100]; // Array to store transaction history
    int transactionCount = 0;
};

// Function to convert double to string
string doubleToString(double value) {
    char buffer[50]; // Adjust the buffer size as needed
    sprintf(buffer, "%.2f", value);
    return buffer;
}

// Function to open a new account
void openAccount(Account accounts[], int &accountCount) {
    if (accountCount < MAX_ACCOUNTS) {
        Account newAccount;
        cout << "Enter Account Number: ";
        cin >> newAccount.accountNumber;
        cout << "Enter Account Holder Name: ";
        cin.ignore();
        getline(cin, newAccount.accountHolderName);
        newAccount.balance = 0.0;
        accounts[accountCount++] = newAccount;
        cout << "Account opened successfully!" << endl;
    } else {
        cout << "Maximum number of accounts reached!" << endl;
    }
}

// Function to deposit money
void depositMoney(Account accounts[], int accountCount) {
    string accountNumber;
    double amount;
    cout << "Enter Account Number: ";
    cin >> accountNumber;
    
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            cout << "Enter Amount to Deposit: ";
            cin >> amount;
            accounts[i].balance += amount;
            accounts[i].transactions[accounts[i].transactionCount++] = "Deposit: +" + doubleToString(amount);
            cout << "Deposit successful. Updated balance: " << accounts[i].balance << endl;
            return;
        }
    }
    
    cout << "Account not found!" << endl;
}

// Function to withdraw money
void withdrawMoney(Account accounts[], int accountCount) {
    string accountNumber;
    double amount;
    cout << "Enter Account Number: ";
    cin >> accountNumber;
    
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            cout << "Enter Amount to Withdraw: ";
            cin >> amount;
            
            if (amount <= accounts[i].balance) {
                accounts[i].balance -= amount;
                accounts[i].transactions[accounts[i].transactionCount++] = "Withdraw: -" + doubleToString(amount);
                cout << "Withdrawal successful. Updated balance: " << accounts[i].balance << endl;
            } else {
                cout << "Insufficient balance!" << endl;
            }
            
            return;
        }
    }
    
    cout << "Account not found!" << endl;
}

// Function to show bank balance
void showBalance(Account accounts[], int accountCount) {
    string accountNumber;
    cout << "Enter Account Number: ";
    cin >> accountNumber;
    
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            cout << "Account Holder Name: " << accounts[i].accountHolderName << endl;
            cout << "Account Balance: " << accounts[i].balance << endl;
            return;
        }
    }
    
    cout << "Account not found!" << endl;
}

// Function to show transaction details
void showTransactions(Account accounts[], int accountCount) {
    string accountNumber;
    cout << "Enter Account Number: ";
    cin >> accountNumber;
    
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            cout << "Transaction History for Account " << accountNumber << ":" << endl;
            for (int j = 0; j < accounts[i].transactionCount; j++) {
                cout << accounts[i].transactions[j] << endl;
            }
            return;
        }
    }
    
    cout << "Account not found!" << endl;
}

int main() {
    Account accounts[MAX_ACCOUNTS];
    int accountCount = 0;
    int choice;
    
    while (true) {
        cout << "===== Menu =====" << endl;
        cout << "1. Open Account" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Show Bank Balance" << endl;
        cout << "5. Show Transaction Details" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                openAccount(accounts, accountCount);
                break;
            case 2:
                depositMoney(accounts, accountCount);
                break;
            case 3:
                withdrawMoney(accounts, accountCount);
                break;
            case 4:
                showBalance(accounts, accountCount);
                break;
            case 5:
                showTransactions(accounts, accountCount);
                break;
            case 6:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    
    return 0;
}

