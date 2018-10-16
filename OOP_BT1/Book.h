#pragma once
#include <iostream>
#include "List.h"
#include <string>
using namespace std;


class Book
{
private:
	string idOfBook;
	string nameOfBook;
	int releaseYear;
	int numberOfBook;
	bool hasBook;
public:
	Book();
	Book(string, string, int, int = 1);
	~Book();
	void show();
	//getter - setter

	void setID(string);
	void setName(string);
	void setYear(int);
	void setNumberBook(int);
	string getID();
	string getName();
	int getYear();
	int getNumberOfBook();

	
	friend ostream & operator<< (ostream &, const Book &);
	friend istream & operator>> (istream &, Book &);
	
};

