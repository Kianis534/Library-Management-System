#include "Journal.h"

Journal::Journal() : Document() {
    Status = "Available";
}

Journal::Journal(const std::string& status, const std::string& category, const std::string& title, int librarycode)
    : Document() {
    Status = status;
    Category = category;
    Title = title;
    LibraryCode = librarycode;
}

int Journal::getReturnDays() const { return 15; }
std::string Journal::getDocumentType() const { return "Journal"; }
