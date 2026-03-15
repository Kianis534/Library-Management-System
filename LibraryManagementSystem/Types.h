#pragma once
#include <string>

enum class UserType { Student, Faculty, Staff, Unknown };
enum class DocumentType { Book, Journal, Magzine, Newspaper, Unknown };

std::string userTypeToString(UserType type);
UserType stringToUserType(const std::string& str);
std::string docTypeToString(DocumentType type);
DocumentType stringToDocType(const std::string& str);
