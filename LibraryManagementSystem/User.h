#pragma once
#include <string>

class User {
protected:
    int AccountNumber;
    int Fine;
    std::string Name;
    std::string EntryDate;
    std::string DOB;
    std::string PhoneNo;
    int Passward;

public:
    User();
    User(int accountNumber, const std::string& name, int fine, const std::string& entryDate, const std::string& phoneNo, const std::string& dob, int passward);
    virtual ~User() = default;

    int getAccountNumber() const;
    std::string getName() const;
    int getFine() const;
    std::string getEntryDate() const;
    std::string getPhoneNo() const;
    std::string getDOB() const;
    int getPassward() const;

    void setFine(int fine);
    void addFine(int amount);
    void payFine(int amount);
    void setName(const std::string& name);
    void setAccountNumber(int accountNumber);
    void setEntryDate(const std::string& entryDate);
    void setPhoneNo(const std::string& phoneNo);
    void setDOB(const std::string& dob);
    void setPassward(int passward);

    virtual int getMaxBooks() const = 0;
    virtual std::string getUserType() const = 0;
};
