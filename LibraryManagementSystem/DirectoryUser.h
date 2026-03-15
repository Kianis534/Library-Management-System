#pragma once
#include <vector>
#include <memory>
#include <string>
#include "User.h"
#include "Student.h"
#include "Faculty.h"
#include "Staff.h"
#include "Types.h"

class DirectoryUser {
private:
    std::vector<std::unique_ptr<User>> users;

public:
    DirectoryUser();

    User* findUser(int accountNumber) const;
    void deleteUser(int accountNumber, UserType type);
    void addUser(int accountNumber, UserType type);

    void checkAccountInformation(int accountNumber) const;
    void settingPassword();
    void removeFine(int accountNumber, int userLimitDays);

    int getCount(UserType type) const;

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};
