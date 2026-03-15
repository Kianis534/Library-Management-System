#include "User.h"

User::User() : AccountNumber(0), Fine(0), Passward(0) {}

User::User(int accountNumber, const std::string& name, int fine, const std::string& entryDate, const std::string& phoneNo, const std::string& dob, int passward)
    : AccountNumber(accountNumber), Name(name), Fine(fine), EntryDate(entryDate), PhoneNo(phoneNo), DOB(dob), Passward(passward) {}

int User::getAccountNumber() const { return AccountNumber; }
std::string User::getName() const { return Name; }
int User::getFine() const { return Fine; }
std::string User::getEntryDate() const { return EntryDate; }
std::string User::getPhoneNo() const { return PhoneNo; }
std::string User::getDOB() const { return DOB; }
int User::getPassward() const { return Passward; }

void User::setFine(int fine) { Fine = fine; }
void User::addFine(int amount) { Fine += amount; }
void User::payFine(int amount) { 
    Fine -= amount; 
    if(Fine < 0) Fine = 0;
}
void User::setName(const std::string& name) { Name = name; }
void User::setAccountNumber(int accountNumber) { AccountNumber = accountNumber; }
void User::setEntryDate(const std::string& entryDate) { EntryDate = entryDate; }
void User::setPhoneNo(const std::string& phoneNo) { PhoneNo = phoneNo; }
void User::setDOB(const std::string& dob) { DOB = dob; }
void User::setPassward(int passward) { Passward = passward; }
