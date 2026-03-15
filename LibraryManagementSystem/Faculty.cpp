#include "Faculty.h"

Faculty::Faculty() : User() {}
Faculty::Faculty(int accountNumber, const std::string& name, int fine, const std::string& entryDate, const std::string& phoneNo, const std::string& dob, int passward)
    : User(accountNumber, name, fine, entryDate, phoneNo, dob, passward) {}

int Faculty::getMaxBooks() const { return 10; }
std::string Faculty::getUserType() const { return "Faculty"; }
