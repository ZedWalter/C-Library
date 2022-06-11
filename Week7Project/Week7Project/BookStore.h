#pragma once

#include <iostream>
#include <string>
using namespace std;

class books {
private:
	string Author;
	string Title;
	bool Status;

public:
	books() {
		Author = "";
		Title = "";
		Status = false;
	}
	void AddBook();
	string GetTitle() { return Title;  }
	bool GetStatus() { return Status; }
	ostream& DisplayBooks(ostream&);
	//Switch case to update status
	void UpdateStatus() {
		if (Status == true) {
			Status = false;
		}
		else {
			Status = true;
		}
	}
};

ostream& operator<<(ostream& os, books& account);
