#pragma once
#include "User.h"

class Student : public User {
public:
    Student();
    Student(int accountNumber, const std::string& name, int fine, const std::string& entryDate, const std::string& phoneNo, const std::string& dob, int passward);
    int getMaxBooks() const override;
    std::string getUserType() const override;
};
