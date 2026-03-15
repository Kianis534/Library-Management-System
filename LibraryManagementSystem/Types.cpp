#include "Types.h"

std::string userTypeToString(UserType type) {
    switch(type) {
        case UserType::Student: return "Student";
        case UserType::Faculty: return "Faculty";
        case UserType::Staff: return "Staff";
        default: return "Unknown";
    }
}

UserType stringToUserType(const std::string& str) {
    if (str == "Student") return UserType::Student;
    if (str == "Faculty") return UserType::Faculty;
    if (str == "Staff") return UserType::Staff;
    return UserType::Unknown;
}

std::string docTypeToString(DocumentType type) {
    switch(type) {
        case DocumentType::Book: return "Book";
        case DocumentType::Journal: return "Journal";
        case DocumentType::Magzine: return "Magzine";
        case DocumentType::Newspaper: return "Newspaper";
        default: return "Unknown";
    }
}

DocumentType stringToDocType(const std::string& str) {
    if (str == "Book") return DocumentType::Book;
    if (str == "Journal") return DocumentType::Journal;
    if (str == "Magzine") return DocumentType::Magzine;
    if (str == "Newspaper") return DocumentType::Newspaper;
    return DocumentType::Unknown;
}
