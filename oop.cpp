#include<iostream>
#include<vector>
using namespace std;
class Account{
private:
    string name;
    int accountID;
    int balance;
public:
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
};
class SavingAccount:public Account{
private:
    int interestRate;
    float time;
public:
    SavingAccount(string name,int accountID,int balance,int interestRate,float time):
    Account(name,accountID,balance){
        this->interestRate = interestRate;
        this->time = time;
    }
    void calculateInterest() override{
        int interest = (getBalance() * interestRate * time)/100;
        setBalance(getBalance() + interest);
        cout << "total balance with interest: " << getBalance() << endl;

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
    }
    void calculateInterest() override{
        cout << "NO INTEREST FOR CURRENT ACCOUNT" << endl;
        setBalance(getBalance() - servicecharge);
    }
    void displayInfo(){
        cout << "name : " << getName() << endl;
        cout << "accountID : " << getAccountID() << endl;
        cout << "balance : " << getBalance() << endl;
        cout << "service charge: " << servicecharge << endl;
    }
};
int main(){
    Account *A1;
    SavingAccount SA("talha",01,1000,5,2.3);
    CurrentAccount CA("talha",02,2000,200);
    // A1 = &SA;
    // A1->calculateInterest();
    // A1 = &CA;
    // A1->calculateInterest();
    // SA.display();
    // CA.displayInfo();
    vector<Account*> accounts;
    accounts.push_back(new SavingAccount("talha",01,1000,5,2.5));
    accounts.push_back(new CurrentAccount("ali",02,2000,200));
    accounts.push_back(new SavingAccount("ahmad",03,3000,6,3.4));
    accounts.push_back(new CurrentAccount("hamza",04,4000,300));
    for(int i = 0;i < accounts.size();i++){
        accounts[i]->calculateInterest();
        SA.display();
        CA.displayInfo();

    }
    for(auto acc:accounts){
        delete acc;
    }
    return 0;
}