#include <iostream>
#include <string>
#include "BookStore.h"
#include <list>

//Finds a book by its title, IS case sensitive <- needs work
books* FindBook(list<books>& accounts) {
    string FindTitle;
    cout << "Enter the Title of the book to find: ";
    cin >> FindTitle;
    for (auto it = accounts.begin(); it != accounts.end(); it++) {
        string CurrentTitle = it->GetTitle();
        if (CurrentTitle == FindTitle) {
            return &*it;
        }
    }
    cout << "This book does not exist.\n";
    return NULL;
}

//Used to find the current status of the book to check it out
books* FindStatus(list<books>& accounts) {
    string FindTitle;
    cout << "Enter the Title of the book to find: ";
    cin >> FindTitle;
    for (auto it = accounts.begin(); it != accounts.end(); it++) {
        string CurrentTitle = it->GetTitle();
        if (CurrentTitle == FindTitle) {
            bool CurrentStatus = it->GetStatus();
            if (CurrentStatus == false) {
                return &*it;
            }
            else if (CurrentStatus == true) {
                cout << "Sorry this book is already checked out. \n";
                return NULL;
            }
        }
    }
    cout << "This book does not exist.\n";
    return NULL;
}

int main()
{
    //Create the list to store books into
    list<books> store = {};
    int choice = 0;

    //Start the loop and display options
    bool start = true;
    while (start) {
        cout << "0. Quit program\n";
        cout << "1. Display all books\n";
        cout << "2. Check a book out\n";
        cout << "3. Check a book in\n";
        cout << "4. Add a new book\n";
        cout << "5. Find a book by title\n";
        cin >> choice;
        //End code when user selects
        if (choice == 0) {
            break;
        }
        //Displays all books
        else if (choice == 1) {
            for (auto it = store.begin(); it != store.end(); it++)
                cout << *it << endl;
        }
        //Checks out a book
        else if (choice == 2) {
            books* Current = FindStatus(store);
            if (Current != NULL) {
                Current->UpdateStatus();
                cout << "The book has been checked out\n";

            }
        }
        //Checks in a book, this currently has no error handling so if a book is currently in it will check it out. <- needs works
        else if (choice == 3) {
            books* Current = FindBook(store);
            if (Current != NULL) {
                Current->UpdateStatus();
                cout << "The book has been checked in\n";
            }
        }
        //Adds a book to the list
        else if (choice == 4) {
            books NewBook;
            NewBook.AddBook();
            store.push_back(NewBook);
        }
        //Finds a book in the list
        else if (choice == 5) {
            books* Current = FindBook(store);
            if (Current != NULL) {
                cout << "Book Found: " << *Current << endl;
            }
        }
    }
}