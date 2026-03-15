#pragma once
#include <string>

class Document {
protected:
    std::string Title, Category, ISBN, Author, Status, IssuedTo, IssueDate, ReturnDate, PublicationDate, PublicationYear;
    int Year, LibraryCode;

public:
    Document();
    Document(const std::string& title, const std::string& category, int librarycode, const std::string& isbn,
        int year, const std::string& author, const std::string& status, const std::string& issuedTo, const std::string& issuedate, const std::string& returndate, const std::string& publicationDate, const std::string& publicationYear);
    virtual ~Document() = default;

    std::string getTitle() const;
    std::string getCategory() const;
    int getLibraryCode() const;
    int getYear() const;
    std::string getISBN() const;
    std::string getAuthor() const;
    std::string getStatus() const;
    std::string getIssuedTo() const;
    std::string getIssuedDate() const;
    std::string getReturnDate() const;
    std::string getPublicationDate() const;
    std::string getPublicationYear() const;

    void setPublicationYear(const std::string& pubYear);
    void setPublicationDate(const std::string& pubDate);
    void setReturnDate(const std::string& returnDate);
    void setIssuedDate(const std::string& issueDate);
    void setAuthor(const std::string& author);
    void setStatus(const std::string& status);
    void setIssuedTo(const std::string& issuedTo);
    void setYear(int year);
    void setISBN(const std::string& isbn);
    void setTitle(const std::string& title);
    void setCategory(const std::string& category);
    void setLibraryCode(int libraryCode);

    virtual int getReturnDays() const = 0;
    virtual std::string getDocumentType() const = 0;
};
