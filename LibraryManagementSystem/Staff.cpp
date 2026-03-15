#include "Staff.h"

Staff::Staff() : User() {}
Staff::Staff(int accountNumber, const std::string& name, int fine, const std::string& entryDate, const std::string& phoneNo, const std::string& dob, int passward)
    : User(accountNumber, name, fine, entryDate, phoneNo, dob, passward) {}

int Staff::getMaxBooks() const { return 5; }
std::string Staff::getUserType() const { return "Staff"; }
