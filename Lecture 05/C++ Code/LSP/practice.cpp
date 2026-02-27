#include<iostream>
using namespace std;
class Account{
    public :
        virtual void withdraw(double amount) = 0;
        virtual void deposit(double amount) = 0;
};
class SavingAccount : public Account {
private:
    double balance;

public:
    SavingAccount() { 
        balance = 0; 
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " in Savings Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " from Savings Account. New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds in Savings Account!\n";
        }
    }
};
class CurrentAccount : public Account {
    private :
        double balance;
    public :
        CurrentAccount(){
            balance = 0;
        }
        void deposit(double amount){
            balance += amount;
            cout << "Deposited: " << amount << " in Current Account. New Balance: " << balance << endl;
        }
        void withdraw(double amount){
            if (balance >= amount) {
                balance -= amount;
                cout << "Withdrawn: " << amount << " from Current Account. New Balance: " << balance << endl;
            } else {
                cout << "Insufficient funds in Current Account!\n";
            }
        }
};
class FixedTermAccount : public Account {
    private :
        double balance;
    public :
        FixedTermAccount(){
            balance = 0;
        }
        void deposit(double amount){
            balance += amount;
            cout << "Deposited: " << amount << " in Fixed Term Account. New Balance: " << balance << endl;
        }
        void withdraw(double amount){
            // throw some exception or print some message that withdrawal is not allowed from fixed term account
            cout << "Withdrawals are not allowed from Fixed Term Account!\n";
        }
};  
// here we are violating LSP because we are not able to use the withdraw function for FixedTermAccount which is a derived class of Account. 
// This is because the withdraw function is not implemented in the FixedTermAccount class and it is not possible to withdraw money from a fixed term account.
int main(){
    Account* acc1 = new SavingAccount();
    Account* acc2 = new CurrentAccount();
    Account* acc3 = new FixedTermAccount();

    acc1->deposit(1000);
    acc1->withdraw(500);

    acc2->deposit(2000);
    acc2->withdraw(1500);

    acc3->deposit(3000);
    acc3->withdraw(1000); // This will print a message that withdrawals are not allowed from Fixed Term Account

    delete acc1;
    delete acc2;
    delete acc3;

    return 0;
}