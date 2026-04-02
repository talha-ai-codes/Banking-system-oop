# TWO PROJECT INCLUDED IN THIS DISCRIPTION
# 1.PROJECT 1 -> FILE NAME -> project1.cpp
# 2.PROJECT 2 -> FILE NAME -> main.cpp
# Banking-system-oop
# 💰 Banking System (C++ OOP Project)

## 📌 Overview

This is a console-based Banking System developed in C++ using Object-Oriented Programming (OOP).
The project simulates real-world banking operations such as account creation, transactions, and interest handling.

It is designed as a beginner-to-intermediate level project to strengthen OOP concepts and practical implementation.

---

## 🚀 Features

* Create **Saving Account** and **Current Account**
* Deposit Money into an account
* Withdraw Money with balance validation
* Apply Interest (only for Saving Accounts)
* Deduct Service Charges (only for Current Accounts)
* Search Account by Account ID
* Display All Accounts with details
* Track:

  * Total Bank Balance (using static variable)
  * Total Number of Accounts

---

## 🧠 OOP Concepts Used

* **Encapsulation** (private data + getters/setters)
* **Inheritance** (SavingAccount, CurrentAccount ← Account)
* **Polymorphism** (virtual functions & overriding)
* **Abstraction**
* **Static Members** (total balance & accounts tracking)

---

## 📂 Project Structure

```
project/
│── project1.cpp   (Main Banking System Logic)
│── main.cpp       (Practice / Testing File)
│── oop.cpp        (OOP Concepts Practice)
```

---

## ▶️ How to Run

### 1️⃣ Compile the Program

```bash
g++ project1.cpp -o bank
```

### 2️⃣ Run the Program

```bash
./bank
```

---

## 📸 Sample Output

```
====SAVING ACCOUNT====
Name : talha
AccountID : 1
Balance : 1165
Interest Applied Successfully

====CURRENT ACCOUNT====
Name : Ahmad
AccountID : 2
Service Charges Deducted
Balance : 1700
```

---

## ⚙️ System Workflow

1. User selects option from menu
2. Creates account (Saving / Current)
3. Performs operations:

   * Deposit / Withdraw
   * Apply Interest
   * Search / Display
4. System updates total balance using static variables

---

## ⭐ Future Improvements

* File Handling (Save/Load data from file)
* Login System (Username & Password)
* GUI Version (using Qt or other libraries)
* ATM Simulation Features
* Transaction History Tracking

---

## 👨‍💻 Author

**Muhammad Talha** <br>
**talha-ai-code**
--------------------


---

## 📌 Note

This project is built for learning purposes to understand:

* OOP in C++
* Real-world system design basics
* Git & GitHub workflow

---

## 🌟 Support

If you like this project, give it a ⭐ on GitHub!
=========================================================================
===========================================================================
============================================================================
************PROJECT2***************
**********FILE -> main.cpp ********
# 🏦 Advanced Banking System (C++ OOP + Exception Handling)

## 📌 Overview

This project is an advanced **Banking System** implemented in C++ using Object-Oriented Programming (OOP) principles and robust Exception Handling.

It simulates a real-world banking environment where multiple types of accounts are managed, transactions are processed, and errors are handled gracefully.

---

## 🚀 Key Features

### 🧾 Account Management

* Create multiple account types:

  * Saving Account
  * Current Account
  * Student Account
* Unique Account ID validation
* Store accounts dynamically using vectors

---

### 💰 Transactions

* Deposit money with validation
* Withdraw money with:

  * Balance check
  * Free transaction limit
  * Service charges (Current Account)
  * Withdrawal limit (Student Account)

---

### 📈 Interest & Charges

* Saving Account → Interest calculation
* Current Account → Service charge deduction
* Student Account → Higher interest rate + withdrawal limit

---

### 🔍 Account Operations

* Search account by ID
* Display individual account details
* Display all accounts

---

### 🏦 Bank Summary

* Total number of accounts
* Total bank balance (using static members)

---

## ⚠️ Exception Handling

Custom exceptions are implemented for real-world error handling:

* `InvalidAmountException`
* `InsufficientBalanceException`
* `DuplicateAccountException`
* `AccountNotFoundException`
* `WithdrawLimitExceededException`

All critical operations are protected using `try-catch` blocks.

---

## 🧠 OOP Concepts Used

### ✔ Encapsulation

* Private data members with getters/setters

### ✔ Inheritance

* Base class: `Account`
* Derived classes:

  * `SavingAccount`
  * `CurrentAccount`
  * `StudentAccount`

### ✔ Polymorphism

* Virtual functions (`Withdraw`, `CalculateInterest`, `display`)
* Runtime binding using base class pointers

### ✔ Abstraction

* Pure virtual functions in base class

---

## 🏗️ Project Structure

```text
Account (Abstract Base Class)
   │
   ├── SavingAccount
   ├── CurrentAccount
   └── StudentAccount
```

---

## 🛠️ Technologies Used

* C++
* Standard Template Library (STL)
* Object-Oriented Programming
* Exception Handling

---

## ▶️ How to Run

1. Compile the program:

```bash
g++ project2.cpp -o banking
```

2. Run the executable:

```bash
./banking
```

---

## 🖥️ Sample Output

```text
==enter your choice from the following data:==
1.Create Account  2.Deposit Amount  3.Withdraw Amount
4.Apply Interest  5.Search Account  6.Display All
7.Bank Summary    8.Exit

Enter choice: 1
Enter Account Type: 1 (Saving)
Enter Name: Ali
Enter Account ID: 101
Enter Balance: 1000
===ACCOUNT IS CREATED===

Enter choice: 2
Enter Account ID: 101
Enter Amount: 500
500 RS is credited successfully.

Enter choice: 3
Enter Account ID: 101
Enter Amount: 200
200 RS is withdraw successfully.

Enter choice: 7
===========BANK SUMMARY===========
Total Accounts in Bank: 1
Total balance in Bank: 1300
```

---

## ▶️ How to Use

* Run the program and choose options from the menu
* Create an account before performing transactions
* Use Account ID for all operations
* Invalid operations are handled using exceptions

---

## 📁 File Information

* **Main File:** `main.cpp`
* Contains:

  * Full OOP Implementation
  * Exception Handling
  * Banking Logic

---

## 💡 Design Highlights

* Real-world inspired banking system
* Clean OOP architecture
* Custom exception handling
* Dynamic memory management using pointers

---

## 📌 Future Improvements

* File handling (data persistence)
* GUI interface
* Database integration
* User authentication system

---

## 👨‍💻 Author

**Muhammad Talha**
GitHub: https://github.com/talha-ai-codes

---

## ⭐ Note

This project is part of my journey to mastering C++, OOP, and building real-world software systems.

