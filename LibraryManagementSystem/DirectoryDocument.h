#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Document.h"
#include "Book.h"
#include "Journal.h"
#include "Magzine.h"
#include "Newspaper.h"
#include "Types.h"

class DirectoryDocument {
private:
    std::vector<std::unique_ptr<Document>> documents;

public:
    DirectoryDocument();

    Document* findDocument(int libraryCode, DocumentType type) const;
    void addDocument(int libraryCode, DocumentType type);
    void deleteDocument(int libraryCode, DocumentType type);
    void listDocuments(DocumentType type) const;
    void checkStatus(int libraryCode, DocumentType type) const;
    void searchDocument(int libraryCode, DocumentType type) const;

    void issueDocument(int libraryCode, DocumentType type);
    void returnDocument(int libraryCode, DocumentType type, int userLimitDays);
    void reissueDocument(int libraryCode, DocumentType type, int userMaxDays);

    int getCount(DocumentType type) const;

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};
