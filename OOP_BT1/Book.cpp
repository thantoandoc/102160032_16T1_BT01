#include "Book.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
using namespace std;

bool checkID(string id) {

	if (id.length() != 9 || id[0] < '1') return false;
	for (int i = 1; i < 9; i++) {
		if (id[i] < '0') return false;
	}
	return true;
}

Book::Book()
{
	this->idOfBook = "";
	this->nameOfBook = "";
	this->releaseYear = 0;
	this->numberOfBook = 0;
	this->hasBook = false;
}

Book::Book(string id, string name, int year, int number)
{
	if (checkID(id)) {
		this->idOfBook = id;
		this->nameOfBook = name;
		this->releaseYear = year;
		this->numberOfBook = number;
		this->hasBook = (number > 0) ? true : false;
	}
	else {
		(*this) = Book();
	}
}


Book::~Book()
{
}
void Book::show() {
	cout << "ID: " << this->idOfBook << "\tNAME: " << this->nameOfBook << "\tYEAR: " << this->releaseYear << "\tNumberOfBook: " << this->numberOfBook << "\tHasBook: " << this->hasBook << endl;
}

void Book::setID(string id)
{
	this->idOfBook = id;
}

void Book::setName(string name)
{
	this->nameOfBook = name;
}

void Book::setYear(int y)
{
	this->releaseYear = y;
}

void Book::setNumberBook(int n)
{
	this->numberOfBook = n;
	this->hasBook = (n) ? true : false;
}

string Book::getID()
{
	return this->idOfBook;
}

string Book::getName()
{
	return string(this->nameOfBook);
}

int Book::getYear()
{
	return this->releaseYear;
}

int Book::getNumberOfBook()
{
	return this->numberOfBook;
}

ostream & operator << (ostream & o, const Book & b) {
	o << "ID: " << b.idOfBook << "\tNAME: " << b.nameOfBook << "\tYEAR: " << b.releaseYear << "\tNumberOfBook: " << b.numberOfBook << "\tHasBook: " << b.hasBook << endl;
	return o;
}
istream & operator >> (istream & ip, Book & b) {
	string name, id;
	int release, number;
	do
	{
		cout << "ID BOOK: ";
		getline(ip, id);
	} while (!checkID(id));
	cout << "NAME BOOK: ";
	getline(ip, name);
	cout << "RELEASE YEAR: ";
	ip >> release;
	cout << "NUMBER OF BOOK: ";
	ip >> number;
	b = Book(id, name, release, number);
	return ip;
}