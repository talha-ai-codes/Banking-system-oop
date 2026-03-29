#include<iostream>
#include<exception>
using namespace std;
//creat a custom class for Exception handling invalide amount
class InvalideAmountException:public runtime_error{
public:
    InvalideAmountException(const string &msg):runtime_error(msg){};
};
//creat  a custom clss for Exception handling InsufficientBalance
class InsufficientBalanceException:public runtime_error{
public:
    InsufficientBalanceException(const string &msg):runtime_error(msg){};
};

class Account{
private:
    //properties or attributes
    string name;
    string fatherName;
    string Address;
    int AccountID;
    int PhoneNumber;
    int balance;
public:
    static int totalbalance;    //track total balance present in bank
    static int totalAccounts;   //track total accounts created in bank

    //creat a parameterized constructor
    Account(string name,string fatherName,string Address int AccountID,int PhoneNumber,int balance){
        this->name = name;
        this->fatherName = fatherName;
        this->Address = Address;
        this->AccountID = AccountID;
        this->PhoneNumber = PhoneNumber;
        this->balance = balance;
    }
    //creat setters and getters to access private properties of base class in derived
    //setters
    void setName(string name){
        this->name = name;
    }

    void setFatherName(string fatherName){
        this->fatherName = fatherName;
    }

    void setAddress(string Address){
        this->Address = Address;
    }

    void setAccountID(int AccountID){
        this->AccountID = AccountID;
    }

    void setPhoneNumber(int PhoneNumber){
        this->PhoneNumber = PhoneNumber;
    }

    void setBalance(int balance){
        this->balance = balance;
    }
    //getters
    string getName(){
        return name;
    }

    string getFatherName(){
        return fatherName;
    }

    string getAddress(){
        return Address;
    }

    int getAccountID(){
        return AccountID;
    }

    int getPhoneNumber(){
        return PhoneNumber;
    }
    int getBalance(){
        return balance;
    }
    //member functions or methods
    void Deposite(int amount){
        if(amount > 0){
            balance += amount;
            totalbalance += amount;
            cout << amount << " RS is credited successfully." << endl;
        }else{
            throw InvalideAmountException("Amount should be greater than 0.");
        }

    }
    void Withdraw(int amount){
        if(amount > 0 && amount <= balance){
            balance -= amount;
            totalbalance -= amount;
            cout << amount << " RS is withdraw successfully." << endl;
        }else if(amount < 0){
            throw InvalideAmountException("Amount should be greater than 0.");
        }else{
            throw InsufficientBalanceException("Your balance is low");
        }

    }
    virtual void CalculateInterest() = 0; //pure virtual -> abstraction
    virtual void display(){
        cout << "Name : " << name << endl;
        cout << "Father Name : " << fatherName << endl;
        cout << "Adress : " << Address << endl;
        cout << "Account ID : " << AccountID << endl;
        cout << "Phone Number: " << PhoneNumber << endl;
        cout << "Balance  : " << balance << endl;
    }
};

class SavingAccount:public Account{
private:
    //properties of savingaccount
    int interestRate;
    int time;
public:
    //creat a constructor
    SavingAccount(string name,string fatherName,string Address,int PhoneNumber,int AccountID,int balance,int interestRate,int time):
    Account(name,fatherName,Address,PhoneNumber,AccountID,balance){
        this->interestRate = interestRate;
        this->time = time;
        totalbalance += balance;
        totalAccounts++;
    }
    //override base class function calculateInterest()
    void CalculateInterest() override{
        int interest = (getBalance()*interestRate*time)/100;
        setBalance(getBalance()+interest);
        totalbalance += interest;
    }

}