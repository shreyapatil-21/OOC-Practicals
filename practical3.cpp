
#include <iostream>
using namespace std;
class saving_account
{
    private:
    string acc_holdername;
    int acc_number;
    double balance;
    double interestrate;
    public:
    saving_account(string name,int accnumber,double b,double r)
    {
        acc_holdername=name;
        acc_number=accnumber;
        balance=b;
        interestrate=r;
    }
    void deposit(double amount)
    {
        if(amount>0)
        {
            balance=balance+amount;
            cout<<"deposit:"<<amount<<endl;
        }
    }
    void withdraw(double amount)
    {
        if(amount>0&&amount<=balance)
        {
            balance=balance-amount;
            cout<<"withdraw:"<<amount<<endl;
        }
        else
        {
            cout<<"insufficient balance"<<endl;
        }
    }
    void applyinterest()
    {
        double interest=balance*interestrate/100;
        balance=balance+interest;
        cout<<"interest applyed "<<interest<<endl;
    }
    void display()
    {
        cout<<"saving account:"<<endl;
        cout<<"account holder:"<<acc_holdername<<endl;
        cout<<"account number:"<<acc_number<<endl;
        cout<<"balance:"<<balance<<endl;
        cout<<"interest rate:"<<interestrate<<endl;
        
    }
};
class checking_acc
{
    string acc_holdername;
    int acc_number;
    double balance;
    double transaction_fee;
public:
        checking_acc(string name,int accno,double initialbalance,double fee)
        {
            acc_holdername=name;
            acc_number=accno;
            balance=initialbalance;
            transaction_fee=fee;
        }
        void deposit(double amount)
        {
            if(amount>0)
            {
                balance+=amount;
                cout<<"deposited:"<<amount<<endl;
            }
        }
        void withdraw(double amount)
        {
            double total=amount+transaction_fee;
            if(total<=balance)
            {
                balance-=total;
                cout<<"withdraw "<<amount<<"("<<transaction_fee<<"fee applied)"<<endl;
            }
            else{
                    cout<<"insufficient balance for withdrawl+fee"<<endl;
            }
        }
        void display()
        {
        cout<<"checking account"<<endl;
        cout<<"account holder:"<<acc_holdername<<endl;
        cout<<"account number:"<<acc_number<<endl;
        cout<<"balance:"<<balance<<endl;
        cout<<"transaction fee:"<<transaction_fee<<endl;
        }
};
int main()
{
    saving_account saving("alice",1001,5000.0,3.0);
    checking_acc checking("Bob",1002,3000.0,20.0);
    saving.display();
    saving.deposit(1000);
    saving.withdraw(2000);
    saving.applyinterest();
    saving.display();
    
    checking.display();
    checking.deposit(1500);
    checking.withdraw(1000);
    checking.display();
    return 0;
}



