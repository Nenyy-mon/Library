#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

class Book {
private: string isbn, title, author, edition, publication;

public:
	//setters
	void setIsbn(string a) {
		isbn = a;
	}
	void setTitle(string b) {
		title = b;
	}
	void setAuthor(string c) {
		author = c;
	}
	void setEdition(string d) {
		edition = d;
	}
	void setPublication(string e) {
		publication = e;
	}
	//getters
	string getIsbn() {
		return isbn;
	}
	string getTitle() {
		return title;
	}
	string getAuthor() {
		return author;
	}
	string getEdition() {
		return edition;
	}
	string getPublication() {
		return publication;
	}
};	
int counter = 0;

void addBook(int counter);
void deleteBook(int counter);
void editBook(int counter);
void searchBook(int counter);
void viewAllBooks(int counter);
void quit();


static void increment(int a) {
	a++;
	counter = a;

}
static void decrement(int a) {
	a--;
	counter = a;
}

Book books[10];

int main() {
	string choice;

	system("CLS");
	cout << "LIBRARY MANAGEMENT SYSTEM\n\n";
	cout << "[1]ADD BOOK\n";
	cout << "[2]DELETE BOOK\n";
	cout << "[3]EDIT BOOK\n";
	cout << "[4]SEARCH BOOK\n";
	cout << "[5]VIEW ALL BOOKS\n";
	cout << "[6]QUIT\n\n";

	cout << "ENTER CHOICE: ";
	getline(cin, choice);
	system("CLS");

	if (choice == "1") {
		addBook(counter);
	}
	else if (choice == "2") {
		deleteBook(counter);
	}
	else if (choice == "3") {
		editBook(counter);
	}
	else if (choice == "4") {
		searchBook(counter);
	}
	else if (choice == "5") {
		viewAllBooks(counter);
	}
	else if (choice == "6") {
		quit();
	}
	else {
		main();
	}
	getchar();
	return 0;
}


void addBook(int counter) {
	string isbn, title, author, edition, publication;
	cout << "Add Book\n\n" << endl;
	if (counter < 10) {

		cout << "Enter ISBN\n";
		getline(cin, isbn);
		cout << "Enter title\n";
		getline(cin, title);
		cout << "Enter author\n";
		getline(cin, author);
		cout << "Enter edition \n";
		getline(cin, edition);
		cout << "Enter publication \n";
		getline(cin, publication);
		books[counter].setIsbn(isbn);
		books[counter].setTitle(title);
		books[counter].setAuthor(author);
		books[counter].setEdition(edition);
		books[counter].setPublication(publication);
		increment(counter);
		cout << "\nBOOK ADDED SUCCESSFULLY!\n\nPress any key to continue . . .";
		getchar();
		main();
	}
	else {
		cout << "YOU HAVE REACHED THE MAXIMUM NUMBER OF BOOKS TOBE ADDED!\n\nPress any key to continue . . .";
		getchar();
		main();
	}
}

void deleteBook(int counter) {
	string isbn;
	int choice;
	cout << "Delete book\n\n";
	if (counter == 0) {
		cout << "THERE IS NO BOOK TO DELETE!\n\nPress any key to continue . . .";
		getchar();
		main();
	}
	cout << "Enter isbn\n\n";
	getline(cin, isbn);
	for (int i = 0; i < counter; i++) {
		if (books[i].getIsbn() == isbn) {
			cout << "\nBook found\n\n";
			cout << "\nDo you want to delete it?\n[1]Yes\n[2]No\n\nEnter Choice: ";
			cin >> choice;
			if (choice == '1') {
				books[i].setIsbn("");
				books[i].setTitle("");
				books[i].setAuthor("");
				books[i].setEdition("");
				books[i].setPublication("");
			
			for (int a = i; a < counter; a++) {
				books[a] = books[a + 1];
				}
			books[9].setIsbn(""); //adjustment if the library is full(10 books)
			books[9].setTitle("");
			books[9].setAuthor("");
			books[9].setEdition("");
			books[9].setPublication("");
			decrement(counter); //calling function to decrement counter
			cout << "\nBOOK SUCCESSFULLY DELETED!\n\nPress any key to continue . . .";
			getchar();
			main();

		}
		else {
			main();
			}
		}

	}
			cout << "\nBOOK NOT FOUND!\n\nPress any key to continue . . .";
			getchar();
			main();
}


void editBook(int counter) {
	system("CLS");
	string editIsbn, choice;
	string isbn, title, author, edition, publication;
	cout << "Edit book\n\n" << endl;
	if (counter == 0) {
		cout << "\nBOOK NOT FOUND!\n\nPress any key to continue . . .";
		getchar();
		main();
	}
	cout << "Enter isbn: \n\n";
	getline(cin, editIsbn);
		for (int i = 0; i < counter; i++) {
			if (books[i].getIsbn()== editIsbn) {
				cout << "Book found: \n\n";
				cout << "ISBN: " << books[i].getIsbn() << endl;
				cout << "Title: " << books[i].getTitle() << endl;
				cout << "Author: " << books[i].getAuthor() << endl;
				cout << "Edition: " << books[i].getEdition() << endl;
				cout << "Publication: " << books[i].getPublication() << endl;
				cout << "\nDo uou want to edit?\n[1]Yes\n[2]No\n\nEnter choice: ";
				getline(cin, choice);
				if (choice == "1") {
					// re-entering the values for new book
					cout << "Enter ISBN: ";
					getline(cin, isbn);
					cout << "Enter Title: ";
					getline(cin, title);
					cout << "Enter Author: ";
					getline(cin, author);
					cout << "Enter Edition: ";
					getline(cin, edition);
					cout << "Enter Publication: ";
					getline(cin, publication);
					books[i].setIsbn(isbn);
					books[i].setTitle(title);
					books[i].setAuthor(author);
					books[i].setEdition(edition);
					books[i].setPublication(publication);
					cout << "\nBOOK EDITED SUCCESSFULLY!\n\nPress any key to continue . . .";
					getchar();
					editBook(counter);//function call to self
				}
				else {
					main();
				}
			}
		}
	cout << "\nBOOK NOT FOUND!\n\nPress any key to continue . . .";
	getchar();
	main();
}

void searchBook(int counter) {
	string isbn;
	bool print = false;
	cout << "Search book: \n\n";
	if (counter == 0) {
		cout << "THERE IS NO BOOK TO DELETE!\n\nPress any key to continue . . .";
		getchar();
		main();
	}
	cout << "Enter isbn: ";
	getline(cin, isbn);
	for (int i = 0; i < counter; i++) {
		if (books[i].getIsbn() == isbn) {
			cout << "Book found: \n\n";
			cout << "ISBN: " << books[i].getIsbn() << endl;
			cout << "Title: " << books[i].getTitle() << endl;
			cout << "Author: " << books[i].getAuthor() << endl;
			cout << "Edition: " << books[i].getEdition() << endl;
			cout << "Publication: " << books[i].getPublication() << endl;
			print = true;
		}
	}
	if (print) {
		cout << "\nPress any key to continue...";
		getchar();
		main();
	}
	else {
		cout << "\nBOOK NOT FOUND\n\nPress any key to continue...";
		getchar();
		main();
	}
}

void viewAllBooks(int counter) {
	cout << "View all books\n\n";
	for (int i = 0; i < counter; i++) {
		cout << "ISBN: " << books[i].getIsbn() << endl;
		cout << "Title: " << books[i].getTitle() << endl;
		cout << "Author: " << books[i].getAuthor() << endl;
		cout << "Edition: " << books[i].getEdition() << endl;
		cout << "Publication: " << books[i].getPublication() << endl;
		cout << "\nPress any key to continue...";
		getchar();
		main();
	}
}

void quit() {
	_exit(1);
}