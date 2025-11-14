#include <iostream>
using namespace std;

// Base class: LibraryItem
class LibraryItem {
protected:
    int itemID;
    string title;

public:
    void getItemInfo() {
        cout << "Enter Item ID: ";
        cin >> itemID;
        cout << "Enter Title: ";
        cin.ignore();  // ignore leftover newline
        getline(cin, title);
    }

    void displayItemInfo() {
        cout << "\nItem ID: " << itemID;
        cout << "\nTitle: " << title;
    }
};

// Derived class: Book
class Book : public LibraryItem {
    string author;

public:
    void getBookInfo() {
        getItemInfo();
        cout << "Enter Author: ";
        getline(cin, author);
    }

    void displayBookInfo() {
        displayItemInfo();
        cout << "\nAuthor: " << author;
        cout << "\nType: Book";
    }
};

// Derived class: Magazine
class Magazine : public LibraryItem {
    int issueNumber;

public:
    void getMagazineInfo() {
        getItemInfo();
        cout << "Enter Issue Number: ";
        cin >> issueNumber;
    }

    void displayMagazineInfo() {
        displayItemInfo();
        cout << "\nIssue Number: " << issueNumber;
        cout << "\nType: Magazine";
    }
};

// Main function
int main() {
    Book b;
    cout << "\nEnter Book Details:\