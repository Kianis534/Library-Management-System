# 📚 Advanced Library Management System (LMS)

[![C++](https://img.shields.io/badge/C++-17-blue.svg?style=flat&logo=c%2B%2B)](https://isocpp.org/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Build: CMake](https://img.shields.io/badge/Build-CMake%20%7C%20MSBuild-brightgreen.svg)]()

A high-performance, industry-standard Library Management System (LMS) developed in **Modern C++17**. This project demonstrates a complete architectural overhaul of a traditional monolithic system, transforming it into a decoupled, polymorphic, and persistent application. It is designed as a premier educational resource for mastering Object-Oriented Programming (OOP), memory safety, and professional CLI user interface design.

---

## 🌟 Key Features

### 🖥️ Professional Console Interface
*   **Clean Transitions**: Integrated screen-clearing logic (`clearScreen`) ensures a modern UI where previous module data does not clutter the screen.
*   **Controlled Workflow**: "Press Enter to Continue" prompts allow users to review system output before moving to the next action.
*   **Robust Input Handling**: Custom template-based validation (`getValidInput<T>`) eliminates crashes and infinite loops caused by invalid character input.

### 👥 Hierarchical User Management
*   **Contextual Modes**: Separate workflows for **Teachers (Faculty)**, **Students**, and **Staff**.
*   **Borrowing Rules Logic**:
    *   **Faculty**: 90-day duration limit.
    *   **Students**: 7-day duration limit.
    *   **Staff**: 21-day duration limit.
*   **Profile Tracking**: Manages Account Numbers, Names, Contact Info, DOB, and accumulated Fines.

### 📖 Polymorphic Inventory System
*   **Universal Document Support**: Unified management of **Books**, **Journals**, **Magazines**, and **Newspapers**.
*   **Full Stock Lifecycle**: Advanced features for adding stock, searching by library code, checking availability status, and deleting records.
*   **Transaction Tracking**: Automatically records who a document was issued to, the issue date, and the expected return date.

### 💾 Complete Data Persistence (File Handling)
*   **Automatic State Recovery**: Loads all users and documents from disk upon startup.
*   **Persistent Storage**: Saves the entire library state to `users.txt` and `docs.txt` on a clean exit.
*   **System Security Persistence**: Administrator passwords are saved in `admin_pass.txt`, ensuring changes to security settings are remembered across sessions.

---

## 🏗️ Technical Architecture

The project follows professional software engineering patterns to ensure scalability and maintainability:

*   **Repository Pattern**: Centralized data management in `DirectoryUser` and `DirectoryDocument` classes, completely separating the Business Logic from the UI (`Source.cpp`).
*   **Dynamic Memory Safety**: Utilizes `std::unique_ptr` and `std::vector` to manage object lifecycles automatically, preventing memory leaks and allowing for unlimited growth of the library database.
*   **True Polymorphism**: Uses base class interfaces (`User` and `Document`) to handle derived types uniformly, reducing code duplication by over 80%.
*   **Type Safety**: Leverages `enum class` for all categorical data to prevent errors associated with "magic strings" or integers.

---

## 🛠️ Installation & Build Guide

### Prerequisites
*   A C++17 compliant compiler (Visual Studio 2019/2022, GCC, or Clang).
*   CMake (Version 3.10 or higher).

### Method 1: Visual Studio (Recommended for Windows)
1.  Open `LibraryManagementSystem.sln` by double-clicking it.
2.  Right-click the project in the Solution Explorer and select **Build**.
3.  Press **F5** to run the application.

### Method 2: CMake (Cross-Platform CLI)
```bash
# Navigate to the project root
mkdir build
cd build

# Configure and compile
cmake ..
cmake --build .

# Run the system (Executable is generated in the root directory)
../LibraryManagementSystem (or ..\LibraryManagementSystem.exe on Windows)
```

---

## 📂 Project Structure

```text
├── LibraryManagementSystem/      # Core Class Library
│   ├── DirectoryDocument.h/cpp   # Document Repository & Transactions
│   ├── DirectoryUser.h/cpp       # User Repository & Accounting
│   ├── User.h/cpp                # Base User Logic (Inheritance)
│   ├── Document.h/cpp            # Base Document Logic (Inheritance)
│   ├── Types.h/cpp               # Global Enums & Utilities
│   └── ... (Derived Classes)     # Student, Book, Journal, Staff, etc.
├── Source.cpp                    # Main Application Entry Point
├── CMakeLists.txt                # Cross-Platform Build Logic
├── README.md                     # Comprehensive Documentation
└── LibraryManagementSystem.sln   # Visual Studio Solution File
```

---

## ⚖️ License & Contribution

This project is released under the **MIT License**. It is open-source and intended for educational use. Students are encouraged to fork the repository to experiment with advanced C++ features or to add new modules such as a Graphical User Interface (GUI) or an SQL backend.

*SEO Tags: C++ Project, Library Management System, Modern C++17, OOP Tutorial, Data Persistence C++, Clean Code Examples, University Project Help, LMS GitHub.*
