#include "Document.h"

Document::Document() : Year(0), LibraryCode(0), Status("Available") {}

Document::Document(const std::string& title, const std::string& category, int librarycode, const std::string& isbn,
    int year, const std::string& author, const std::string& status, const std::string& issuedTo, const std::string& issuedate, const std::string& returndate, const std::string& publicationDate, const std::string& publicationYear)
    : Title(title), Category(category), LibraryCode(librarycode), ISBN(isbn), Year(year), Author(author),
    Status(status), IssuedTo(issuedTo), IssueDate(issuedate), ReturnDate(returndate),
    PublicationDate(publicationDate), PublicationYear(publicationYear) {}

std::string Document::getTitle() const { return Title; }
std::string Document::getCategory() const { return Category; }
int Document::getLibraryCode() const { return LibraryCode; }
int Document::getYear() const { return Year; }
std::string Document::getISBN() const { return ISBN; }
std::string Document::getAuthor() const { return Author; }
std::string Document::getStatus() const { return Status; }
std::string Document::getIssuedTo() const { return IssuedTo; }
std::string Document::getIssuedDate() const { return IssueDate; }
std::string Document::getReturnDate() const { return ReturnDate; }
std::string Document::getPublicationDate() const { return PublicationDate; }
std::string Document::getPublicationYear() const { return PublicationYear; }

void Document::setPublicationYear(const std::string& pubYear) { PublicationYear = pubYear; }
void Document::setPublicationDate(const std::string& pubDate) { PublicationDate = pubDate; }
void Document::setReturnDate(const std::string& returnDate) { ReturnDate = returnDate; }
void Document::setIssuedDate(const std::string& issueDate) { IssueDate = issueDate; }
void Document::setAuthor(const std::string& author) { Author = author; }
void Document::setStatus(const std::string& status) { Status = status; }
void Document::setIssuedTo(const std::string& issuedTo) { IssuedTo = issuedTo; }
void Document::setYear(int year) { Year = year; }
void Document::setISBN(const std::string& isbn) { ISBN = isbn; }
void Document::setTitle(const std::string& title) { Title = title; }
void Document::setCategory(const std::string& category) { Category = category; }
void Document::setLibraryCode(int libraryCode) { LibraryCode = libraryCode; }
