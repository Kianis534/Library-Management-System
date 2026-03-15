#pragma once
#include "Document.h"

class Newspaper : public Document {
public:
    Newspaper();
    Newspaper(const std::string& status, const std::string& category, const std::string& title, int librarycode);

    int getReturnDays() const override;
    std::string getDocumentType() const override;
};
