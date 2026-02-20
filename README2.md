# Login & Registration System using OOPS in C++

## CodeAlpha Internship – Task 2

This project is a Login and Registration System implemented in C++ using Object-Oriented Programming (OOPS).
It allows users to register with a username and password and later log in using stored credentials.
User data is stored persistently using file handling.

--------------------------------------------------

## Features:
- Object-Oriented Programming based design
- User registration with duplicate username checking
- Password validation (minimum length requirement)
- Password confirmation during registration
- Login authentication using stored credentials
- File-based data storage
- Simple and beginner-friendly console interface

--------------------------------------------------

## OOPS CONCEPTS USED
- Classes and Objects
- Encapsulation
- Abstraction
- Access Specifiers (private / public)
- File Handling (fstream)

--------------------------------------------------

## 🧠 Logic
1. Display menu options (Register / Login / Exit)
2. Registration Process:
   - Take username input
   - Check if username already exists
   - Validate password length
   - Confirm password
   - Store credentials in file
3. Login Process:
   - Take username and password
   - Verify credentials from file
4. Display success or error messages

--------------------------------------------------

## FILE HANDLING
User credentials are stored in a text file named:

users.txt

File format:
username password

Each user is stored on a new line.

--------------------------------------------------

## 💻 Technologies Used
- C++
- Object-Oriented Programming (OOPS)
- File Handling
- Standard C++ Libraries

--------------------------------------------------

## 📂 Project Structure

CodeAlpha_Login_Registration_System/
|
|-- login_registration.cpp
|-- users.txt
|-- README.md

--------------------------------------------------

## 🧪 Sample Output

==============================
   LOGIN & REGISTRATION MENU
==============================
1. Register
2. Login
3. Exit
Choose an option: 1

----- REGISTRATION -----
Enter username: user123
Enter password (min 6 chars): password1
Confirm password: password1
Registration successful!

----- LOGIN -----
Enter username: user123
Enter password: password1
Login successful. Welcome, user123!

--------------------------------------------------

## 👤 Author
Syed Irtiaza Haider Jafri 
CodeAlpha C++ Intern

--------------------------------------------------

## 🔗 Internship Credit
This project is submitted as **Task-2** of the **CodeAlpha C++ Programming Internship**.


