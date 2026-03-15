#include "Magzine.h"

Magzine::Magzine() : Document() {
    Status = "Available";
}

Magzine::Magzine(const std::string& status, const std::string& category, const std::string& title, int librarycode)
    : Document() {
    Status = status;
    Category = category;
    Title = title;
    LibraryCode = librarycode;
}

int Magzine::getReturnDays() const { return 7; }
std::string Magzine::getDocumentType() const { return "Magzine"; }
