#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class NonWithdrawableAccount{
    public:
        virtual void deposit(double amount) = 0;
};
class WithdrawableAccount : public NonWithdrawableAccount{
    public :
        virtual void withdraw( double amount) = 0;
};
class SavingsAccount : public WithdrawableAccount{
    private :
        int balance;

    public : 
        SavingsAccount(){
            balance =0;
        }
        void deposit(double amount) override{
            balance += amount;
            cout<<"amount deposited in savings account and  the updated balance is : "<<balance<<endl;
        }
        void withdraw(double amount) override{
            if(balance >= amount){
                balance -= amount;
                cout<<"amount withdrawn from savings account and  the updated balance is : "<<balance<<endl;
            }
            else{
                cout<<"you have insufficient funds in your savings account "<<endl;
            }
        }
        void showbalance(){
            cout<<"Your savings account balance as of now is : "<<balance<<endl;
        }
};
class CurrentAccount : public WithdrawableAccount{
    private :
        int balance;

    public : 
        void deposit(double amount) override{
            balance += amount;
            cout<<"amount deposited in CurrentAccount and  the updated balance is : "<<balance<<endl;
        }
        void withdraw(double amount) override{
            if(balance >= amount){
                balance -= amount;
                cout<<"amount withdrawn from Current account and  the updated balance is : "<<balance<<endl;
            }
            else{
                cout<<"you have insufficient funds in your Current account "<<endl;
            }
        }
        void showbalance(){
            cout<<"Your CurrentAccount balance as of now is : "<<balance<<endl;
        }
};
class FixeddepositAccount : public NonWithdrawableAccount{
    private : 
    int balance;
    public : 
    void deposit(double amount) override{
        balance += amount;
        cout<<"Deposit successful ,  your fixed deposit account now  has a balance of : "<<balance<<endl;
    }
    void showbalance(){
                cout<<" your fixed deposit account has a balance of : "<<balance<<endl;
    }
};
int main(){
    SavingsAccount * savacc = new SavingsAccount();
    CurrentAccount *curracc = new CurrentAccount();
    FixeddepositAccount* fxdacc = new FixeddepositAccount();
    savacc->deposit(1000);
    savacc->withdraw(500);
    curracc->deposit(1000);
    curracc->withdraw(500);
    fxdacc->deposit(1000);
    savacc->showbalance();
    curracc->showbalance();
    fxdacc->showbalance();
}
