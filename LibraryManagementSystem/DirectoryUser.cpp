#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <string>
#include "DirectoryUser.h"

using namespace std;

DirectoryUser::DirectoryUser() {}

User* DirectoryUser::findUser(int accountNumber) const {
    for (const auto& user : users) {
        if (user->getAccountNumber() == accountNumber) return user.get();
    }
    return nullptr;
}

int DirectoryUser::getCount(UserType type) const {
    string typeStr = userTypeToString(type);
    int count = 0;
    for (const auto& user : users) {
        if (user->getUserType() == typeStr) count++;
    }
    return count;
}

void DirectoryUser::addUser(int accountNumber, UserType type) {
    if (findUser(accountNumber)) {
        cout << "Error: Account number " << accountNumber << " is already taken.\n";
        return;
    }

    string userName, entryDate, phoneNo, dob;
    cout << "Enter User Name: "; 
    cin >> ws; getline(cin, userName);
    cout << "Enter Contact Number: "; 
    cin >> ws; getline(cin, phoneNo);
    cout << "Enter Entry Date: "; 
    cin >> ws; getline(cin, entryDate);
    cout << "Enter Date of Birth: "; 
    cin >> ws; getline(cin, dob);

    unique_ptr<User> newUser;
    switch (type) {
        case UserType::Student: newUser = make_unique<Student>(accountNumber, userName, 0, entryDate, phoneNo, dob, 0); break;
        case UserType::Faculty: newUser = make_unique<Faculty>(accountNumber, userName, 0, entryDate, phoneNo, dob, 0); break;
        case UserType::Staff:   newUser = make_unique<Staff>(accountNumber, userName, 0, entryDate, phoneNo, dob, 0); break;
        default: return;
    }
    users.push_back(move(newUser));
    cout << "Successfully registered " << userTypeToString(type) << ".\n";
}

void DirectoryUser::deleteUser(int accountNumber, UserType type) {
    string typeStr = userTypeToString(type);
    auto it = find_if(users.begin(), users.end(), [&](const auto& u) {
        return u->getAccountNumber() == accountNumber && u->getUserType() == typeStr;
    });

    if (it != users.end()) {
        users.erase(it);
        cout << "Record for account " << accountNumber << " deleted successfully.\n";
    } else {
        cout << "No record found for account " << accountNumber << " (" << typeStr << ").\n";
    }
}

void DirectoryUser::removeFine(int accountNumber, int userLimitDays) {
    User* user = findUser(accountNumber);
    if (!user) {
        cout << "User Not Found.\n";
        return;
    }

    cout << "Enter Issue Day (1-31): "; int issueDay; cin >> issueDay;
    cout << "Enter Return Day (1-31): "; int returnDay; cin >> returnDay;

    int days = returnDay - issueDay;
    if (days > userLimitDays) {
        int fineAmount = (days - userLimitDays) * 10;
        cout << "Your fine is: " << fineAmount << endl;
        
        while (true) {
            cout << "Enter amount to pay: ";
            int amount; cin >> amount;
            if (amount == fineAmount) {
                user->setFine(0);
                cout << "Fine paid successfully.\n";
                break;
            } else {
                cout << "Incorrect amount. Please pay exactly " << fineAmount << ".\n";
            }
        }
    } else {
        cout << "No fine due for this period.\n";
    }
}

void DirectoryUser::checkAccountInformation(int accountNumber) const {
    User* user = findUser(accountNumber);
    if (user) {
        cout << "\n--- User Details ---\n";
        cout << "Type:           " << user->getUserType() << endl;
        cout << "Name:           " << user->getName() << endl;
        cout << "Account No:     " << user->getAccountNumber() << endl;
        cout << "Max Documents:  " << user->getMaxBooks() << endl;
        cout << "Fine:           " << user->getFine() << endl;
        cout << "DOB:            " << user->getDOB() << endl;
        cout << "Entry Date:     " << user->getEntryDate() << endl;
        cout << "Contact:        " << user->getPhoneNo() << endl;
        cout << "--------------------\n";
    } else {
        cout << "User not found or operating as Guest.\n";
    }
}

void DirectoryUser::settingPassword() {
    cout << "Enter Account Number: ";
    int accNo; cin >> accNo;
    User* user = findUser(accNo);
    if (user) {
        cout << "Enter New Password (numerical): ";
        int newPass; cin >> newPass;
        user->setPassward(newPass);
        cout << "Password updated successfully.\n";
    } else {
        cout << "User not found.\n";
    }
}

void DirectoryUser::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file) return;
    for (const auto& u : users) {
        file << u->getUserType() << "|"
             << u->getAccountNumber() << "|"
             << u->getName() << "|"
             << u->getFine() << "|"
             << u->getEntryDate() << "|"
             << u->getPhoneNo() << "|"
             << u->getDOB() << "|"
             << u->getPassward() << "\n";
    }
}

void DirectoryUser::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) return;
    users.clear();
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string type, accStr, name, fineStr, entry, phone, dob, passStr;
        
        getline(ss, type, '|');
        getline(ss, accStr, '|');
        getline(ss, name, '|');
        getline(ss, fineStr, '|');
        getline(ss, entry, '|');
        getline(ss, phone, '|');
        getline(ss, dob, '|');
        getline(ss, passStr, '|');

        try {
            int accNo = stoi(accStr);
            int fine = stoi(fineStr);
            int pass = stoi(passStr);

            if (type == "Student")
                users.push_back(make_unique<Student>(accNo, name, fine, entry, phone, dob, pass));
            else if (type == "Faculty")
                users.push_back(make_unique<Faculty>(accNo, name, fine, entry, phone, dob, pass));
            else if (type == "Staff")
                users.push_back(make_unique<Staff>(accNo, name, fine, entry, phone, dob, pass));
        } catch (...) { continue; }
    }
}
