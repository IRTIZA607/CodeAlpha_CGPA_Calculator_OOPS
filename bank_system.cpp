#include <iostream>
#include <string>
using namespace std;

// Transaction class
class Transaction
{
public:
    string type;
    double amount;

    Transaction(string t, double a)
    {
        type = t;
        amount = a;
    }
};

// Account class
class Account
{
private:
    int accountNumber;
    double balance;
    Transaction history[10]; // store last 10 transactions
    int count;

public:
    Account(int accNo)
    {
        accountNumber = accNo;
        balance = 0;
        count = 0;
    }

    void deposit(double amount)
    {
        balance += amount;
        history[count++] = Transaction("Deposit", amount);
        cout << "Deposit successful.\n";
    }

    void withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient balance.\n";
            return;
        }
        balance -= amount;
        history[count++] = Transaction("Withdrawal", amount);
        cout << "Withdrawal successful.\n";
    }

    void transfer(Account &to, double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient balance for transfer.\n";
            return;
        }
        balance -= amount;
        to.balance += amount;

        history[count++] = Transaction("Transfer Sent", amount);
        to.history[to.count++] = Transaction("Transfer Received", amount);

        cout << "Transfer successful.\n";
    }

    void showAccountInfo()
    {
        cout << "\nAccount Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }

    void showTransactions()
    {
        cout << "\nTransaction History:\n";
        for (int i = 0; i < count; i++)
        {
            cout << history[i].type << " - " << history[i].amount << endl;
        }
    }
};

// Customer class
class Customer
{
private:
    string name;
    Account account;

public:
    Customer(string n, int accNo) : account(accNo)
    {
        name = n;
    }

    Account &getAccount()
    {
        return account;
    }

    void showCustomerInfo()
    {
        cout << "\nCustomer Name: " << name << endl;
        account.showAccountInfo();
    }
};

int main()
{
    Customer c1("Alice", 101);
    Customer c2("Bob", 102);

    c1.getAccount().deposit(5000);
    c1.getAccount().withdraw(1000);
    c1.getAccount().transfer(c2.getAccount(), 2000);

    c1.showCustomerInfo();
    c1.getAccount().showTransactions();

    c2.showCustomerInfo();
    c2.getAccount().showTransactions();

    return 0;
}