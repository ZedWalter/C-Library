#include <iostream>
#include <string>
#include "BookStore.h"
using namespace std;

//Adds a new book into the list
void books::AddBook() {
	string author;
	string title;


	cout << "Enter the Author's last name: ";
	cin >> author;
	cout << "Enter the Title: ";
	cin >> title;



	Author = author;
	Title = title;
	Status = false;
}

//Displays books in a friendly format
ostream& books::DisplayBooks(ostream& os) {
	os << "Author: "
		<< this->Author
		<< "  Title: "
		<< this->Title
		<< "  Checked Out?: "
		<< this->Status
		<< endl;
	return os;
}
//Override the output operator
ostream& operator<<(ostream& os, books& account) {
	return account.DisplayBooks(os);
}
