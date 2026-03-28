#include<iostream>
#include<vector>
using namespace std;
class Account{
private:
    string name;
    int accountID;
    int balance;
public:
    static int totalbalance;
    Account(string name,int accountID,int balance){
        this->name = name;
        this->accountID = accountID;
        this->balance = balance;
       
    }
    virtual void calculateInterest(){
        cout << "Base class funvtion to calculate interest." << endl;
    }
    //setter
    void setName(string name){
        this->name = name;
    }
    void setAccountID(int accountID){
        this->accountID = accountID;
    }
    void setBalance(int balance){
        this->balance = balance;
    }
    
    string getName(){
        return name;
    }
    int getAccountID(){
        return accountID;
    }
    int getBalance(){
        return balance;
    }
    virtual void display(){
        cout << "this function will be override in derived classes..." << endl;
    }
};
    int Account::totalbalance = 0;
class SavingAccount:public Account{
private:
    int interestRate;
    float time;
public:
    SavingAccount(string name,int accountID,int balance,int interestRate,float time):
    Account(name,accountID,balance){
        this->interestRate = interestRate;
        this->time = time;
        totalbalance += balance;
    }
    void calculateInterest() override{
        int interest = (getBalance() * interestRate * time)/100;
        setBalance(getBalance() + interest);
        totalbalance += interest;
    }
    void display(){
        cout << "name : " << getName() << endl;
        cout << "accountID: " << getAccountID() << endl;
        cout << "balance : " << getBalance() << endl;
    }
};
class CurrentAccount:public Account{
private:
    int servicecharge;
public:
    void setServicecharge(int s){
        servicecharge = s;
    }
    CurrentAccount(string name,int accountID,int balance,int servicecharge)
    :Account(name,accountID,balance){
        this->servicecharge = servicecharge;
        totalbalance += balance;
    }
    void calculateInterest() override{
        cout << "NO INTEREST FOR CURRENT ACCOUNT" << endl;
        setBalance(getBalance() - servicecharge);
        totalbalance -= servicecharge;
    }
    void display() override{
        cout << "name : " << getName() << endl;
        cout << "accountID : " << getAccountID() << endl;
        cout << "balance : " << getBalance() << endl;
        cout << "service charge: " << servicecharge << endl;
    }
};
int main(){
    Account *A1;
    vector<Account*> accounts;
    accounts.push_back(new SavingAccount("talha",01,1000,5,2.5));
    accounts.push_back(new CurrentAccount("ali",02,1000,200));
    accounts.push_back(new SavingAccount("ahmad",03,1000,6,3.4));
    accounts.push_back(new CurrentAccount("hamza",04,1000,300));
    for(int i = 0;i < accounts.size();i++){
        accounts[i]->calculateInterest();
        accounts[i]->display();

    }
    cout << "total balance : " << Account::totalbalance << endl;
    for(auto acc:accounts){
        delete acc;
    }
    return 0;
}