#pragma once
#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

class Book;

class List
{
private:
	Book * ds;
	int n;
public:
	List();
	List(const List &);
	~List();
	void addBook(Book &, int = 0);
	void delBook(int = 0);
	void showAllBooks();
	void showAllBooks(const int);
	void update(string ID);
	int hasBook(string);
	Book & operator[] (const int);
	friend ostream & operator << (ostream &, List &);
	friend istream & operator >> (istream &, List &);
	void quickSort(int, int, bool(*compare)(string, string));
	int getSize();
	Book * binarySearch(int, int, int &, string);
};

