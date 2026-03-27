#include<iostream>
#include<vector>
using namespace std;
class Account{
private:
    //properties or attributes
    string name;
    int AccountID;
    int balance;
public:
    static int totalBalance; //it will store whole balance of bank
    static int totalAccounts;
    //setter
    void setName(string name){
        this->name = name;
    }
    void setAccountID(int AccountID){
        this->AccountID = AccountID;
    }
    void setBalance(int balance){
        this->balance = balance;
    }
    //getter
    string getName(){
        return name;
    }
    int getAccountID(){
        return AccountID;
    }
    int getBalance(){
        return balance;
    }
    //creat a constructor for Account class
    Account(string name,int AccountID,int balance){
        this->name = name;
        this->AccountID = AccountID;
        this->balance = balance;
    }
    virtual ~Account(){}
    //creat a function to deposite amount
    void deposite(int amount){
        if(amount > 0){
            balance += amount;
            totalBalance += amount;
        }else{
            cout << "invalide amount." << endl;
        }
    }
    //creat a function to withdraw amount from account
    void withdraw(int amount){
        if(amount <= balance){
            balance -= amount;
            totalBalance -= amount;
        }else{
            cout << "insuficient balance." << endl;
        }
    }
    //creat a function to calculate interest and ovveride in a base clase
    virtual void calculateInterest(){
        cout << "this a base class virtual function for calculating interest." << endl;
    }
    //creat a display virtual function to display detail of an account
    virtual void display(){
        cout << "displaying details of account....." << endl;
    }

};
  int Account::totalBalance = 0;
  int Account::totalAccounts = 0;
class SavingAccount:public Account{
private:
    int interestRate;
    float time;
public:
    SavingAccount(string name,int AccountID,int balance,int interestRate,float time):
    Account(name,AccountID,balance){
        this->interestRate = interestRate;
        this->time = time;
        totalBalance += balance;
        totalAccounts++;
    }
    int interest = 0;
    void calculateInterest() override{
        interest = (getBalance() * interestRate * time)/100;
        setBalance(getBalance() + interest);
        totalBalance += interest;
        cout << "total balance with interest: " << getBalance() << endl;
    }
    void display() override{
        cout << "====SAVING ACCOUNT====" << endl;
        cout << "Name : " << getName() << endl;
        cout << "AcountID : " << getAccountID() << endl;
        cout << "balance : " << getBalance() << endl;
        cout << "interestRate : " << interestRate << endl;
        cout << "time : " << time << endl;
        cout << "total interest: " << interest << endl;
        cout << "=====your total balance after interest=======" << endl;
        cout << "total balance : " << getBalance() << endl;
        
    }
};
class CurrentAccount:public Account{
private:
    float serviceCharge;
public:
    //first creat constructor
    CurrentAccount(string name,int AccountID,int balance,float serviceCharge):
    Account(name,AccountID,balance){
        this->serviceCharge = serviceCharge;
        totalBalance += balance;
        totalAccounts++;
    }
    //creat a function to override base class function 
    void calculateInterest() override{
        cout << "=======NO INTEREST FOR CURRENT ACCOUNT======" << endl;
        setBalance(getBalance() - serviceCharge);
        totalBalance -= serviceCharge;

    }
    // creat a display function to show detail of current account
    void display() override{
        cout << "====CURRENT ACCOUNT====" << endl;
        cout << "Name : " << getName() << endl;
        cout << "AccountID : " << getAccountID() << endl;
        cout << "Service charges : " << serviceCharge << endl;
        cout << "Balance : " << getBalance() << endl;
    }

};
int main(){
    Account *acc;
    vector<Account*> accounts;
    while(true){
        int choice,accountType;
        cout << "1.creat account,2.Deposite amount,3.withdraw amount,4.display all accounts "
        << " 5.apply interest,6.search Account,7.show total balance and accounts,8.exit" << endl;
        cout << "enter your choice from above.";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "enter your account type 1 for saving 2 for current.";
                cin >> accountType;
                if(accountType < 1 || accountType > 2){
                    cout << "invalide choice." << endl;
                    break;
                }
                cin.ignore();
                if(accountType == 1){
                    string name;int balance,AccountID,interestRate;float time;
                    cout << "enter your name: ";
                    getline(cin,name);
                    cout << "enter you id : ";
                    cin >> AccountID;
                    cout << "enter balance : ";
                    cin >> balance;
                    cout << "enter your interest Rate: ";
                    cin >> interestRate;
                    cout << "enter time :";
                    cin >> time;
                    accounts.push_back(new SavingAccount(name,AccountID,balance,interestRate,time));
                }else{
                    string name;int AccountID,balance,serviceCharge;
                    cout << "enter your name: ";
                    getline(cin,name);
                    cout << "enter accountID: ";
                    cin >> AccountID;
                    cout << "enter balance : ";
                    cin >> balance;
                    cout << "enter service charges: ";
                    cin >> serviceCharge;
                    accounts.push_back(new CurrentAccount(name,AccountID,balance,serviceCharge));
                }
                break;
            case 2:{
                int id,amount;
                cout << "==deposite amount in your account==" << endl;
                cout << "enter your account ID: ";
                cin >> id;
                cout << "enter amount.";
                cin >> amount;
                bool found = false;
                for(auto acc:accounts){
                    if(acc->getAccountID() == id){
                        acc->deposite(amount);
                        found = true;
                        cout << "==submitted successfuly==" << endl;
                        break;
                    }
                    }
                    if(!found){
                        cout << "invalide account ID." << endl;
                    }
                    break;
                }
            case 3:{
                int amount,id;
                cout << "enter your ID:";
                cin >> id;
                cout << "enter amount: ";
                cin >> amount;
                bool found = false;
                for(auto acc:accounts){
                    if(acc->getAccountID() == id && amount > 0){
                        acc->withdraw(amount);
                        found = true;
                        cout << "==withdraw successful==" << endl;
                        break;
                    }

                }
                if(!found){
                    cout << "Invalide account." << endl;
                }
            }
                break;
            case 4:
                cout << "===display all account===" << endl;
                for(auto acc:accounts){
                    acc->display();
                }
                break;
            case 5:{
                int id;
                cout << "enter account ID: ";
                cin >> id;
                bool found = false;
                for(auto acc:accounts){
                    if(acc->getAccountID() == id){
                        acc->calculateInterest();
                        found = true;
                        break;
                    }
                    cout <<"***----------------------***" << endl;
                    
                }
                if(!found){
                    cout << "ivalide account ID: " << endl;
                }
            }
                break;
            case 6:{
                int amount,id;
                bool found = false;
                cout << "===search your account by AccountID===" << endl;
                cout << "enter your accountID: ";
                cin >> id;
                for(auto acc:accounts){
                    if(acc->getAccountID() == id){
                        acc->display();
                        found = true;
                        break;
                    }
                }
                if(!found){
                    cout << "Account Not Found." << endl;
                }
            }
                break;
            case 7:
                cout <<"total accounts in bank: " <<  Account::totalAccounts << endl;
                cout <<"total balance : " << Account::totalBalance << endl;
                break;
            case 8:
                cout << "========THANK YOU...FOR USING BANKING SYSTEM!========" << endl;
                for(auto acc:accounts){
                    delete acc;
                }
                    return 0; 
        }
    }
    return 0;
}