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

**Muhammad Talha**
-GitHub:**talha-ai-codes**

---

## 📌 Note

This project is built for learning purposes to understand:

* OOP in C++
* Real-world system design basics
* Git & GitHub workflow

---

## 🌟 Support

If you like this project, give it a ⭐ on GitHub!

