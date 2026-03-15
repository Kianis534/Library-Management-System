#include "Newspaper.h"

Newspaper::Newspaper() : Document() {
    Status = "Available";
}

Newspaper::Newspaper(const std::string& status, const std::string& category, const std::string& title, int librarycode)
    : Document() {
    Status = status;
    Category = category;
    Title = title;
    LibraryCode = librarycode;
}

int Newspaper::getReturnDays() const { return 1; }
std::string Newspaper::getDocumentType() const { return "Newspaper"; }
