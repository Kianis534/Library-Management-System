#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <string>
#include "DirectoryDocument.h"

using namespace std;

DirectoryDocument::DirectoryDocument() {}

Document* DirectoryDocument::findDocument(int libraryCode, DocumentType type) const {
    string typeStr = docTypeToString(type);
    for (const auto& doc : documents) {
        if (doc->getLibraryCode() == libraryCode && doc->getDocumentType() == typeStr) return doc.get();
    }
    return nullptr;
}

int DirectoryDocument::getCount(DocumentType type) const {
    string typeStr = docTypeToString(type);
    int count = 0;
    for (const auto& user : documents) {
        if (user->getDocumentType() == typeStr) count++;
    }
    return count;
}

void DirectoryDocument::addDocument(int libraryCode, DocumentType type) {
    if (findDocument(libraryCode, type)) {
        cout << "Error: " << docTypeToString(type) << " with code " << libraryCode << " already exists.\n";
        return;
    }

    string title, author, category, ISBN, pubDate, pubYear;
    int year;
    cout << "Enter title: "; 
    cin >> ws; getline(cin, title);
    cout << "Enter category: "; 
    cin >> ws; getline(cin, category);
    cout << "Enter author: "; 
    cin >> ws; getline(cin, author);
    cout << "Enter year (int): "; 
    cin >> year;
    cout << "Enter ISBN: "; 
    cin >> ws; getline(cin, ISBN);
    cout << "Enter publication date: "; 
    cin >> ws; getline(cin, pubDate);
    cout << "Enter publication year: "; 
    cin >> ws; getline(cin, pubYear);

    unique_ptr<Document> newDoc;
    switch (type) {
        case DocumentType::Book:      newDoc = make_unique<Book>(); break;
        case DocumentType::Journal:   newDoc = make_unique<Journal>(); break;
        case DocumentType::Magzine:   newDoc = make_unique<Magzine>(); break;
        case DocumentType::Newspaper: newDoc = make_unique<Newspaper>(); break;
        default: return;
    }

    newDoc->setLibraryCode(libraryCode);
    newDoc->setTitle(title);
    newDoc->setCategory(category);
    newDoc->setAuthor(author);
    newDoc->setYear(year);
    newDoc->setISBN(ISBN);
    newDoc->setPublicationDate(pubDate);
    newDoc->setPublicationYear(pubYear);
    newDoc->setStatus("Available");
    
    documents.push_back(move(newDoc));
    cout << docTypeToString(type) << " added successfully.\n";
}

void DirectoryDocument::deleteDocument(int libraryCode, DocumentType type) {
    string typeStr = docTypeToString(type);
    auto it = find_if(documents.begin(), documents.end(), [&](const auto& d) {
        return d->getLibraryCode() == libraryCode && d->getDocumentType() == typeStr;
    });

    if (it != documents.end()) {
        documents.erase(it);
        cout << typeStr << " with code " << libraryCode << " deleted successfully.\n";
    } else {
        cout << "No " << typeStr << " found with code " << libraryCode << ".\n";
    }
}

void DirectoryDocument::listDocuments(DocumentType type) const {
    string typeStr = docTypeToString(type);
    bool found = false;
    for (const auto& d : documents) {
        if (d->getDocumentType() == typeStr) {
            cout << "\n--- " << typeStr << " Details ---\n";
            cout << "Code:           " << d->getLibraryCode() << endl;
            cout << "Title:          " << d->getTitle() << endl;
            cout << "Author:         " << d->getAuthor() << endl;
            cout << "ISBN:           " << d->getISBN() << endl;
            cout << "Status:         " << d->getStatus() << endl;
            if (d->getStatus() == "Issued") {
                cout << "Issued To:      " << d->getIssuedTo() << endl;
                cout << "Issue Date:     " << d->getIssuedDate() << endl;
                cout << "Return Date:    " << d->getReturnDate() << endl;
            }
            cout << "-----------------------\n";
            found = true;
        }
    }
    if (!found) cout << "No " << typeStr << "s available in the directory.\n";
}

void DirectoryDocument::checkStatus(int libraryCode, DocumentType type) const {
    Document* d = findDocument(libraryCode, type);
    if (d) cout << "Status: " << d->getStatus() << endl;
    else cout << docTypeToString(type) << " not found.\n";
}

void DirectoryDocument::searchDocument(int libraryCode, DocumentType type) const {
    Document* d = findDocument(libraryCode, type);
    if (d) {
        cout << "Title:  " << d->getTitle() << endl;
        cout << "Author: " << d->getAuthor() << endl;
        cout << "Status: " << d->getStatus() << endl;
    } else cout << docTypeToString(type) << " not found.\n";
}

void DirectoryDocument::issueDocument(int libraryCode, DocumentType type) {
    Document* d = findDocument(libraryCode, type);
    if (!d) {
        cout << docTypeToString(type) << " not found.\n";
        return;
    }
    if (d->getStatus() == "Issued") {
        cout << "Document is already issued.\n";
        return;
    }

    string name, iDate, rDate;
    cout << "Issue To: "; 
    cin >> ws; getline(cin, name);
    cout << "Issue Date: "; 
    cin >> ws; getline(cin, iDate);
    cout << "Return Date: "; 
    cin >> ws; getline(cin, rDate);

    d->setIssuedTo(name);
    d->setIssuedDate(iDate);
    d->setReturnDate(rDate);
    d->setStatus("Issued");
    cout << "Document issued successfully.\n";
}

void DirectoryDocument::returnDocument(int libraryCode, DocumentType type, int userLimitDays) {
    Document* d = findDocument(libraryCode, type);
    if (!d || d->getStatus() != "Issued") {
        cout << "Document not found or not issued.\n";
        return;
    }

    cout << "Days since issue: "; int days; cin >> days;
    if (days > userLimitDays) {
        int fine = (days - userLimitDays) * 10;
        cout << "Overdue! Fine: " << fine << endl;
        while (true) {
            cout << "Enter fine amount to pay: ";
            int payment; cin >> payment;
            if (payment == fine) {
                cout << "Fine paid.\n";
                break;
            } else cout << "Incorrect amount.\n";
        }
    }

    d->setStatus("Available");
    d->setIssuedTo("");
    d->setIssuedDate("");
    d->setReturnDate("");
    cout << "Document returned successfully.\n";
}

void DirectoryDocument::reissueDocument(int libraryCode, DocumentType type, int userMaxDays) {
    Document* d = findDocument(libraryCode, type);
    if (!d || d->getStatus() != "Issued") {
        cout << "Document not found or not issued.\n";
        return;
    }

    cout << "Days since issue: "; int days; cin >> days;
    if (days > userMaxDays) {
        int fine = (days - userMaxDays) * 10;
        cout << "Deadline passed! Pay fine: " << fine << endl;
        while (true) {
            cout << "Pay: "; int pay; cin >> pay;
            if (pay == fine) {
                cout << "Fine paid.\n";
                break;
            } else cout << "Incorrect.\n";
        }
    }
    cout << "Document re-issued.\n";
}

void DirectoryDocument::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file) return;
    for (const auto& d : documents) {
        file << d->getDocumentType() << "|"
             << d->getLibraryCode() << "|"
             << d->getTitle() << "|"
             << d->getCategory() << "|"
             << d->getAuthor() << "|"
             << d->getYear() << "|"
             << d->getISBN() << "|"
             << d->getStatus() << "|"
             << d->getIssuedTo() << "|"
             << d->getIssuedDate() << "|"
             << d->getReturnDate() << "|"
             << d->getPublicationDate() << "|"
             << d->getPublicationYear() << "\n";
    }
}

void DirectoryDocument::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) return;
    documents.clear();
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string type, libStr, title, cat, author, yearStr, isbn, status, issuedTo, issuedDate, returnDate, pubDate, pubYear;
        
        getline(ss, type, '|');
        getline(ss, libStr, '|');
        getline(ss, title, '|');
        getline(ss, cat, '|');
        getline(ss, author, '|');
        getline(ss, yearStr, '|');
        getline(ss, isbn, '|');
        getline(ss, status, '|');
        getline(ss, issuedTo, '|');
        getline(ss, issuedDate, '|');
        getline(ss, returnDate, '|');
        getline(ss, pubDate, '|');
        getline(ss, pubYear, '|');

        unique_ptr<Document> doc;
        if (type == "Book") doc = make_unique<Book>();
        else if (type == "Journal") doc = make_unique<Journal>();
        else if (type == "Magzine") doc = make_unique<Magzine>();
        else if (type == "Newspaper") doc = make_unique<Newspaper>();

        if (doc) {
            try {
                doc->setLibraryCode(stoi(libStr));
                doc->setTitle(title);
                doc->setCategory(cat);
                doc->setAuthor(author);
                doc->setYear(stoi(yearStr));
                doc->setISBN(isbn);
                doc->setStatus(status);
                doc->setIssuedTo(issuedTo);
                doc->setIssuedDate(issuedDate);
                doc->setReturnDate(returnDate);
                doc->setPublicationDate(pubDate);
                doc->setPublicationYear(pubYear);
                documents.push_back(move(doc));
            } catch (...) { continue; }
        }
    }
}
