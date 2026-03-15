#include "Book.h"

Book::Book() : Document() {
    Status = "Available";
}

Book::Book(const std::string& status, const std::string& category, const std::string& title, int librarycode)
    : Document() {
    Status = status;
    Category = category;
    Title = title;
    LibraryCode = librarycode;
}

int Book::getReturnDays() const { return 30; }
std::string Book::getDocumentType() const { return "Book"; }
