#include<iostream>
#include<vector>
#include<exception>
using namespace std;
//creat a custom class for Exception handling invalide amount
class InvalideAmountException:public runtime_error{
public:
    InvalideAmountException(const string &msg):runtime_error(msg){};
};
//creat  a custom class for Exception handling InsufficientBalance
class InsufficientBalanceException:public runtime_error{
public:
    InsufficientBalanceException(const string &msg):runtime_error(msg){};
};

//creat a custom class to track Duplicate Account
class DuplicateAccountException:public runtime_error{
public:
    DuplicateAccountException(const string &msg):runtime_error(msg){};
};
//creat a class to track invalide account
class AccountNotFoundException:public runtime_error{
public:
    AccountNotFoundException(const string &msg):runtime_error(msg){};
};
//creat a class to track withdraw limit exceeding
class withdrawlimitExceedException:public runtime_error{
public:
    withdrawlimitExceedException(const string &msg):runtime_error(msg){};
};

class Account{
private:
    //properties or attributes
    string name;
    string fatherName;
    string Address;
    string PhoneNumber;
    int AccountID;
    int balance;
    int freeTransaction = 5;
public:
    static int totalbalance;    //track total balance present in bank
    static int totalAccounts;   //track total accounts created in bank

    //creat a parameterized constructor
    Account(string name,string fatherName,string Address ,string PhoneNumber,int AccountID,int balance){
        this->name = name;
        this->fatherName = fatherName;
        this->Address = Address;
        this->AccountID = AccountID;
        this->PhoneNumber = PhoneNumber;
        this->balance = balance;
    }
    //declare virtual destructor
    virtual ~Account(){}
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

    void setPhoneNumber(string PhoneNumber){
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

    string getPhoneNumber(){
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
    virtual void Withdraw(int amount){
        if(freeTransaction > 0 && amount <= balance && amount > 0){
            freeTransaction--;
            balance -= amount;
            totalbalance -= amount;
            cout << amount << " RS is withdraw successfully." << endl;
        }else if (freeTransaction <= 0 && amount <= balance){
            balance -= (amount + 100); //charge after free limit
            totalbalance -= (amount+100);
            cout << amount << " RS is withdraw successfully." << endl;
        }else if(amount < 0){
            throw InvalideAmountException("Amount should be greater than 0.");
        }else{
            throw InsufficientBalanceException("Your balance is low");
        }
        }

    
    virtual void CalculateInterest() = 0; //pure virtual -> abstraction
    virtual void display() = 0; //pure virtual -> abstraction
};

class SavingAccount:public Account{
private:
    //properties of savingaccount
    int interestRate;
    float time;
public:
    //creat a constructor
    SavingAccount(string name,string fatherName,string Address,string PhoneNumber,int AccountID,int balance,int interestRate,float time)
    :Account(name,fatherName,Address,PhoneNumber,AccountID,balance){
        this->interestRate = interestRate;
        this->time = time;
        if(balance < 500){
            setBalance(0);
            throw InvalideAmountException("initial amount for saving account is 500.");
        }
        totalbalance += balance;
        totalAccounts++;
    }
    //override base class function calculateInterest()
    int interest = 0;
    void CalculateInterest() override{
        interest = (getBalance()*interestRate*time)/100;
        setBalance(getBalance()+interest);
        totalbalance += interest;
        cout << "===Interest Applied Successfully===" << endl;
    }
    //creat a function display information fo saving account
    void display() override{
        cout << "Name : " << getName() << endl;
        cout << "Father Name : " << getFatherName() << endl;
        cout << "Address : " << getAddress() << endl;
        cout << "Account ID : " << getAccountID() << endl;
        cout << "Phone Number : " << getPhoneNumber() << endl;
        cout << "Balance : " << getBalance() << endl;
        cout << "total Interest : " << interest << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "-------------------------------------------------" << endl;

    }

};
class CurrentAccount:public Account{
private:
    int serviceCharge;
public:
    //create a contructor
    CurrentAccount(string name,string fatherName,string Address,string PhoneNumber,int AccountID,int balance,int serviceCharge):Account
    (name,fatherName,Address,PhoneNumber,AccountID,balance){
        this->serviceCharge = serviceCharge;
        totalbalance += balance;
        totalAccounts++;
    }
    //override a base class function calculate interest to sub service charges
    void CalculateInterest() override{
        cout << "==NO INTEREST FOR CURRENT ACCOUNT==" << endl;
        setBalance(getBalance() - serviceCharge);
        totalbalance -= serviceCharge;
        cout << "==service charge subtract from your balance==" << endl;
    }
    void display() override{
        cout << "Name : " << getName() << endl;
        cout << "Father Name : " << getFatherName() << endl;
        cout << "Address : " << getAddress() << endl;
        cout << "Account ID : " << getAccountID() << endl;
        cout << "Phone Number : " << getPhoneNumber() << endl;
        cout << "Balance : " << getBalance() << endl;
        cout << "Service charge : " << serviceCharge << endl;
        cout << "--------------------------------------------" << endl;
        cout << "--------------------------------------------" << endl;
    }
};
class StudentAccount:public Account{
private:
    int interestRate = 10;
    int withdrawlimit = 1500;
    int time;
public:
    //creat constructor for student class
    StudentAccount(string name,string fatherName,string Address,string PhoneNumber,int AccountID,int balance,int time):Account
    (name,fatherName,Address,PhoneNumber,AccountID,balance){
        this->time = time;
        totalbalance += balance;
        totalAccounts++;
    }
    //creat function to calculate interest for student account
    int interest;
    void CalculateInterest() override{
        interest = (getBalance()*interestRate*time)/100;
        setBalance(getBalance()+interest);
        totalbalance += interest;
        cout << "===Interest Applied Successfully===" << endl;
    }
    //creat a withdrwal function to override the base class function
    void Withdraw(int amount) override{
        if(amount <= getBalance() && amount <= withdrawlimit){
            setBalance(getBalance() - amount);
            totalbalance -= amount;
            cout << amount << " RS is withdraw Successfully." << endl;
        }else if(amount > getBalance()){
            throw InsufficientBalanceException("====your balance is low====");
        }else{
            throw withdrawlimitExceedException("==yourwithdraw limit Exceeded==");
        }

    }
    //creat a function to display information of student class
    void display(){
        cout << "Name : " << getName() << endl;
        cout << "Father Name : " << getFatherName() << endl;
        cout << "Address : " << getAddress() << endl;
        cout << "Phone Number : " << getPhoneNumber() << endl;
        cout << "Account ID: " << getAccountID() << endl;
        cout << "Interest Rate : " << interestRate << endl;
        cout << "Balance : " << getBalance() << endl;
        cout << "total interest : " << interest << endl;
        cout << "------------------------------------------------------" << endl;
        cout << "------------------------------------------------------" << endl;
    }

};
bool isDuplicateID(vector<Account*>& accounts,int id){
    for(auto acc:accounts){
        if(acc->getAccountID() == id){
            return true;
        }
    }
    return false;
}
 int Account::totalAccounts = 0;
 int Account::totalbalance = 0;
int main(){
    Account *acc;
    vector<Account*> accounts;//container to store multiple accounts dynamically
    while(true){
        int choice;
        cout << "==enter your choice from the following data:== " << endl;
        cout << "1.Creat Account,2.deposit Amount,3.withdraw Amount,4.Apply interest"
        << "5.Search Account,6.Display all Accounts,7.Bank summary,8.Exit" << endl;
        cin >> choice;
        try{
            switch(choice){
                case 1:{
                    int AccountType;
                    cout << "Enter your Account type: 1.saving Account,2.Current Account,3.Student Account: ";
                    cin >> AccountType;
                    if(AccountType < 1 || AccountType > 3){
                        cout << "===Invalide Account type.please try again....===" << endl;
                        break;
                    }
                    if(AccountType == 1){
                        cout << "==Enter your Information for saving Account==" << endl;
                        string name, fatherName,Address,PhoneNumber;int id,balance,interestRate;float time;
                        cin.ignore();
                        cout << "Enter your full Name : ";
                        getline(cin,name);
                        cout << "Enter your Father Name : ";
                        getline(cin,fatherName);
                        cout << "Enter your Address : ";
                        getline(cin,Address);
                        cout << "enter your Phone Number: ";
                        getline(cin,PhoneNumber);
                        if(PhoneNumber.length() < 11){
                            cout << "==Invalide phoneNumber.Pease try again===" << endl;
                            break;
                        }
                        cout << "Enter your Account ID: ";
                        cin >> id;
                        if(isDuplicateID(accounts,id)){
                            throw DuplicateAccountException("AccountID alreay Exist.");
                        }   
                        cout << "Enter balance : ";
                        cin >> balance;
                        cout << "Enter interest Rate : ";
                        cin >> interestRate;
                        cout << "Enter time : ";
                        cin >> time;
                        Account *acc = new SavingAccount(name,fatherName,Address,PhoneNumber,id,balance,interestRate,time);
                        accounts.push_back(acc);
                        cout << "===ACCOUNT IS CREATED===" << endl;
                    }else if(AccountType == 2){
                        cout << "==Enter your Information for Current Account==" << endl;
                        string name, fatherName,Address,PhoneNumber;int id,balance,serviceCharge;
                        cin.ignore();
                        cout << "Enter your full Name : ";
                        getline(cin,name);
                        cout << "Enter your Father Name : ";
                        getline(cin,fatherName);
                        cout << "Enter your Address : ";
                        getline(cin,Address);
                        cout << "enter your Phone Number: ";
                        getline(cin,PhoneNumber);
                        if(PhoneNumber.length() < 11){
                            cout << "Invalide phone Number..please try again..." << endl;
                            break;
                        }
                        cout << "Enter your Account ID: ";
                        cin >> id;
                        if(isDuplicateID(accounts,id)){
                            throw DuplicateAccountException("AccountID alreay Exist.");
                        }
                        cout << "Enter balance : ";
                        cin >> balance;
                        if(balance < 1000){
                            throw InvalideAmountException("intial balance for current account is 1000.");
                        }
                        cout << "Enter Service charge: ";
                        cin >> serviceCharge;
                        Account *acc = new CurrentAccount(name,fatherName,Address,PhoneNumber,id,balance,serviceCharge);
                        accounts.push_back(acc);
                        cout << "===ACCOUNT IS CREATED===" << endl;
                    }else{
                        
                        cout << "--------------Read the following carefully----------------" << endl;
                        cout << "===Details of student Information====" << endl;
                        cout << "===High Interest for students=========" << endl;
                        cout << "===Withdrawal limit to prevent from spending more money====" << endl;
                        cout << "----------------Now Creat your Account----------------" << endl;
                        string name, fatherName,Address,PhoneNumber;int id,balance,interestRate;float time;
                        cin.ignore();
                        cout << "Enter your full Name : ";
                        getline(cin,name);
                        cout << "Enter your father Name : ";
                        getline(cin,fatherName);
                        cout << "Enter your Address : ";
                        getline(cin,Address);
                        cout << "Enter your Phone Number : ";
                        getline(cin,PhoneNumber);
                        if(PhoneNumber.length() < 11){
                            cout << "Invalide PhoneNumber.please try again..." << endl;
                            break;
                        }
                        cout << "Enter your Account ID: ";
                        cin >> id;
                        if(isDuplicateID(accounts,id)){
                            throw DuplicateAccountException("Account Already exist.please try again....");
                        }
                        cout << "Enter balance : ";
                        cin >> balance;
                        if(balance < 250){
                            throw InvalideAmountException("initial Amount for student Account is 250.");
                        }
                        //interest Rate is already initialized for student account in class
                        cout << "Enter time : ";
                        cin >> time;
                        Account *acc = new StudentAccount(name,fatherName,Address,PhoneNumber,id,balance,time);
                        accounts.push_back(acc);
                        cout << "====Account is Created========" << endl;
                    }
                    
                }
                break;
                case 2:{
                    string name;int id,amount;
                    cout << "===Deposit Amount===" << endl;
                    cin.ignore();
                    cout << "Ente your name : ";
                    getline(cin,name);
                    cout << "enter your AccountID : ";
                    cin >> id;
                    cout << "Enter amount: ";
                    cin >> amount;
                    bool found = false;
                    for(auto acc:accounts){
                        if(acc->getName() == name && acc->getAccountID() == id){
                            acc->Deposite(amount);
                            found = true;
                            break;
                        }
                    }
                    if(!found){
                        cout << "==Invalide name or Account ID==" << endl;
                    }
                }
                break;
                case 3:{
                    int id,amount;
                    cout << "===withdraw Amount===" << endl;
                    cout << "Enter your Account ID : ";
                    cin >> id;
                    cout << "Enter amount : ";
                    cin >> amount;
                    bool found = false;
                    for(auto acc:accounts){
                        if(acc->getAccountID() == id){
                            acc->Withdraw(amount);
                            found = true;
                            break;
                        }
                    }
                    if(!found){
                        cout << "===Invalide Account ID===" << endl;
                    }
                }
                break;
                case 4:{
                    int id;
                    cout << "Enter Account ID: ";
                    cin >> id;
                    bool found = false;
                    for(auto acc:accounts){
                        if(acc->getAccountID() == id){
                            acc->CalculateInterest();
                            found = true;
                            break;
                        }
                    }
                    if(!found){
                        cout << "Invalide Account ID.please try again...." << endl;
                    }
                }
                break;
                case 5:{
                    int id;
                    bool found = false;
                    cout << "====search your account by Account ID====" << endl;
                    cout << "Enter your Account ID: ";
                    cin >> id;
                    for(auto acc:accounts){
                        if(acc->getAccountID() == id){
                            acc->display();
                            found = true;
                            break;
                        }
                    }
                    if(!found){
                        throw AccountNotFoundException("Account Not found..try again..");
                    }
                }
                break;
                case 6:{
                    for(auto acc:accounts){
                        acc->display();
                    }
                }
                break;
                case 7:
                    cout << "===========BANK SUMMARY===========" << endl;
                    cout << "Total Accounts in Bank: " << Account::totalAccounts << endl;
                    cout << "Total balance in Bank: " << Account::totalbalance << endl;
                    break;
                case 8:
                    for(auto acc:accounts){
                        delete acc;
                    }
                    cout << "==thanks for using banking system==" << endl;
                    return 0;
                default:
                    cout << "========invalide input...try again....========" << endl;
                    break;
            }

            
        }
        catch(const DuplicateAccountException &e){
            cout << "Exception occured : " << e.what() << endl;
        }
        catch(const InvalideAmountException &e){
            cout << "Execption occured: " << e.what() << endl;
        }
        catch(const InsufficientBalanceException &e){
            cout << "Exception occured : " << e.what() << endl;
        }
        catch(const AccountNotFoundException &e){
            cout << "Exception occured : " << e.what() << endl;
        }
    catch(const withdrawlimitExceedException &e){
        cout << "Exception occured : " << e.what() << endl;
    }

    }
 
    return 0;
}