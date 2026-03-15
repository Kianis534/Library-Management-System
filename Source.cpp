#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <fstream>
#include "LibraryManagementSystem/DirectoryDocument.h"
#include "LibraryManagementSystem/DirectoryUser.h"
#include "LibraryManagementSystem/Document.h"
#include "LibraryManagementSystem/User.h"
#include "LibraryManagementSystem/Types.h"

// Robust UI Utilities
static void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    std::cout << "\033[2J\033[1;1H"; 
#endif
}

static void waitForKey() {
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cin.get();
}

static void clearBuffer() {
    std::cin.clear();
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
}

template <typename T>
T getValidInput(const std::string& prompt) {
    T input;
    while (true) {
        if (!prompt.empty()) std::cout << prompt;
        if (std::cin >> input) {
            return input;
        } else {
            std::cout << "Invalid input. Please enter a valid value.\n";
            clearBuffer();
        }
    }
}

static std::string getLineInput(const std::string& prompt) {
    if (!prompt.empty()) std::cout << prompt;
    std::string input;
    std::cin >> std::ws;
    std::getline(std::cin, input);
    return input;
}

static DocumentType selectDocType() {
    std::cout << "\n--- Select Document Type ---\n"
         << "1. Book\n2. Journal\n3. Newspaper\n4. Magazine\n"
         << "Choice: ";
    int c = getValidInput<int>("");
    switch(c) {
        case 1: return DocumentType::Book;
        case 2: return DocumentType::Journal;
        case 3: return DocumentType::Newspaper;
        case 4: return DocumentType::Magzine;
        default: return DocumentType::Unknown;
    }
}

static UserType selectUserType() {
    std::cout << "\n--- Select User Type ---\n"
         << "1. Teacher (Faculty)\n2. Student\n3. Staff\n"
         << "Choice: ";
    int c = getValidInput<int>("");
    switch(c) {
        case 1: return UserType::Faculty;
        case 2: return UserType::Student;
        case 3: return UserType::Staff;
        default: return UserType::Unknown;
    }
}

static std::string loadAdminPassword() {
    std::ifstream file("admin_pass.txt");
    std::string pass;
    if (file >> pass) return pass;
    return "admin"; 
}

static void saveAdminPassword(const std::string& pass) {
    std::ofstream file("admin_pass.txt");
    file << pass;
}

static void printHeader() {
    std::cout << "\n====================================================\n"
         << "        LIBRARY MANAGEMENT SYSTEM :: MAIN MENU      \n"
         << "====================================================\n"
         << "1. List All Stocks (Books, Journals, etc.)\n"
         << "2. Check Status of a Specific Document\n"
         << "3. View User Account Information\n"
         << "4. Issue a Document\n"
         << "5. Return a Document\n"
         << "6. Re-issue a Document\n"
         << "7. Remove/Pay Fine of a User\n"
         << "8. Add New Stock to Inventory\n"
         << "9. Change Administrator Password\n"
         << "10. Register a New User\n"
         << "11. Search Documents in Stocks\n"
         << "12. Logout (Switch User Mode)\n"
         << "13. Delete a Record (User or Document)\n"
         << "0. Exit Program\n"
         << "Select an Option: ";
}

int main() {
    DirectoryDocument directoryDoc;
    DirectoryUser directoryUser;
    
    directoryDoc.loadFromFile("docs.txt");
    directoryUser.loadFromFile("users.txt");
    std::string adminPassword = loadAdminPassword();

    bool systemRunning = true;
    while (systemRunning) {
        clearScreen();
        std::cout << "\n\t   Welcome to the Advanced Library Management System\n";
        
        bool loggedIn = false;
        while (!loggedIn && systemRunning) {
            std::cout << "\n--- SYSTEM LOGIN ---\n";
            std::cout << "1) Login with Password\n";
            std::cout << "2) Reset Admin Password (Default: admin)\n";
            std::cout << "3) Exit Program\n";
            int loginChoice = getValidInput<int>("Choice: ");

            if (loginChoice == 1) {
                std::string entered = getLineInput("Enter Password: ");
                if (entered == adminPassword) {
                    std::cout << "\nLogin Successful!\n";
                    loggedIn = true;
                    waitForKey();
                } else {
                    std::cout << "\nAccess Denied: Incorrect Password.\n";
                    waitForKey();
                    clearScreen();
                }
            } else if (loginChoice == 2) {
                adminPassword = getLineInput("Enter New System Password: ");
                saveAdminPassword(adminPassword);
                std::cout << "\nPassword Updated and Saved.\n";
                waitForKey();
                clearScreen();
            } else if (loginChoice == 3) {
                systemRunning = false;
            }
        }

        if (!systemRunning) break;

        bool modeSelected = true;
        while (modeSelected) {
            clearScreen();
            std::cout << "\n--- SELECT USER CONTEXT ---\n";
            std::cout << "1) Teacher (Faculty Mode)\n";
            std::cout << "2) Student Mode\n";
            std::cout << "3) Staff Mode\n";
            std::cout << "4) Logout System\n";
            int mode = getValidInput<int>("Choice: ");

            if (mode == 4) {
                modeSelected = false;
                break;
            }
            if (mode < 1 || mode > 3) continue;

            UserType currentUserType = UserType::Unknown;
            int limitDays = 0;
            if (mode == 1) { currentUserType = UserType::Faculty; limitDays = 90; }
            else if (mode == 2) { currentUserType = UserType::Student; limitDays = 7; }
            else if (mode == 3) { currentUserType = UserType::Staff; limitDays = 21; }

            bool sessionRunning = true;
            while (sessionRunning) {
                clearScreen();
                printHeader();
                int opt = getValidInput<int>("");

                if (opt == 0) { 
                    sessionRunning = false; modeSelected = false; systemRunning = false; 
                    break;
                }
                if (opt == 12) {
                    sessionRunning = false;
                    break;
                }

                switch(opt) {
                    case 1: { 
                        DocumentType t = selectDocType();
                        if (t != DocumentType::Unknown) directoryDoc.listDocuments(t);
                        break;
                    }
                    case 2: {
                        DocumentType t = selectDocType();
                        if (t != DocumentType::Unknown) directoryDoc.checkStatus(getValidInput<int>("Library Code: "), t);
                        break;
                    }
                    case 3: {
                        directoryUser.checkAccountInformation(getValidInput<int>("User Account Number: "));
                        break;
                    }
                    case 4: {
                        DocumentType t = selectDocType();
                        if (t != DocumentType::Unknown) directoryDoc.issueDocument(getValidInput<int>("Library Code: "), t);
                        break;
                    }
                    case 5: {
                        DocumentType t = selectDocType();
                        if (t != DocumentType::Unknown) directoryDoc.returnDocument(getValidInput<int>("Library Code: "), t, limitDays);
                        break;
                    }
                    case 6: {
                        DocumentType t = selectDocType();
                        if (t != DocumentType::Unknown) directoryDoc.reissueDocument(getValidInput<int>("Library Code: "), t, limitDays);
                        break;
                    }
                    case 7: {
                        directoryUser.removeFine(getValidInput<int>("User Account Number: "), limitDays);
                        break;
                    }
                    case 8: {
                        DocumentType t = selectDocType();
                        if (t != DocumentType::Unknown) directoryDoc.addDocument(getValidInput<int>("New Library Code: "), t);
                        break;
                    }
                    case 9: {
                        adminPassword = getLineInput("Enter New System Admin Password: ");
                        saveAdminPassword(adminPassword);
                        std::cout << "Password Changed and Persisted.\n";
                        break;
                    }
                    case 10: {
                        UserType t = selectUserType();
                        if (t != UserType::Unknown) directoryUser.addUser(getValidInput<int>("New Account Number: "), t);
                        break;
                    }
                    case 11: {
                        DocumentType t = selectDocType();
                        if (t != DocumentType::Unknown) directoryDoc.searchDocument(getValidInput<int>("Library Code: "), t);
                        break;
                    }
                    case 13: {
                        std::cout << "\n--- DELETE RECORD ---\n1. Delete User\n2. Delete Document\nChoice: ";
                        int d = getValidInput<int>("");
                        if (d == 1) {
                            UserType ut = selectUserType();
                            if (ut != UserType::Unknown) directoryUser.deleteUser(getValidInput<int>("Account Number: "), ut);
                        } else if (d == 2) {
                            DocumentType dt = selectDocType();
                            if (dt != DocumentType::Unknown) directoryDoc.deleteDocument(getValidInput<int>("Library Code: "), dt);
                        }
                        break;
                    }
                    default: std::cout << "\nInvalid Option selected.\n"; break;
                }
                waitForKey();
            }
        }
    }

    directoryDoc.saveToFile("docs.txt");
    directoryUser.saveToFile("users.txt");
    std::cout << "\nAll data has been saved successfully. Thank you for using LMS!\n";
    return 0;
}
