# 🏦 Bank Management Application

A simple console-based Bank Management System built in C++ that allows users to create accounts, deposit/withdraw funds, and view account details using file-based storage.

# Features

- **Create Account** – Register a new customer with account number, name, and initial balance
- **Deposit** – Add funds to an existing account
- **Withdraw** – Withdraw funds with insufficient balance protection
- **Check Balance** – View account details and current balance
- **Display All Accounts** – List all registered customer records

# Getting Started

### Prerequisites

- A C++ compiler (g++, clang++, or MSVC)
- Terminal / Command Prompt

### Compilation

```bash
g++ -o bank_management main.cpp
```

### Run

```bash
./bank_management        # Linux/macOS
bank_management.exe      # Windows
```

---

## Usage

On launch, you'll see a menu:

```
====== Bank Management Application ======
1. Create Account
2. Deposit Amount
3. Withdraw Amount
4. Check Balance
5. Display All Accounts
6. Exit
```

Enter the number corresponding to the action you want to perform and follow the prompts.

---

## Data Storage

All account records are stored locally in a plain text file called `bank_records.txt`, created automatically in the same directory as the executable. Each record is stored as:

```
<accountNumber>
<customerName>
<balance>
```

---

## Project Structure

```
.
├── main.cpp            # Main source file
├── bank_records.txt    # Auto-generated data file (runtime)
└── README.md
```

---

## Limitations

- No password/authentication on accounts
- Account numbers must be unique (no validation enforced)
- Data stored in plain text (not encrypted)
- Single-user, single-session application

---

## License

This project is open source and free to use for educational purposes.
