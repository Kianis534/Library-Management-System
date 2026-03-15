#include "Student.h"

Student::Student() : User() {}
Student::Student(int accountNumber, const std::string& name, int fine, const std::string& entryDate, const std::string& phoneNo, const std::string& dob, int passward)
    : User(accountNumber, name, fine, entryDate, phoneNo, dob, passward) {}

int Student::getMaxBooks() const { return 3; }
std::string Student::getUserType() const { return "Student"; }
