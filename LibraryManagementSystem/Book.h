#pragma once
#include "Document.h"

class Book : public Document {
public:
    Book();
    Book(const std::string& status, const std::string& category, const std::string& title, int librarycode);

    int getReturnDays() const override;
    std::string getDocumentType() const override;
};
