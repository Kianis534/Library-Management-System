#pragma once
#include "User.h"

class Faculty : public User {
public:
    Faculty();
    Faculty(int accountNumber, const std::string& name, int fine, const std::string& entryDate, const std::string& phoneNo, const std::string& dob, int passward);
    int getMaxBooks() const override;
    std::string getUserType() const override;
};
