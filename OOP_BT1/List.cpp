#include "List.h"



List::List()
{
	this->ds = NULL;
	this->n = 0;
}

List::List(const List &list)
{
	this->n = list.n;
	this->ds = new Book[this->n];
	for (int i = 0; i < this->n; i++) {
		(*this)[i] = *(list.ds + i);
	}
}


List::~List()
{
	if (n == 0) {
		delete[] ds;
	}
}

void List::addBook(Book &b, int idx)
{
	int pos = hasBook(b);
	if (pos > -1) {
		idx = pos;
		(*this)[idx].setNumberBook((*this)[idx].getNumberOfBook() + b.getNumberOfBook());
	}
	else {
		n += 1;
		Book * books = new Book[n];
		for (int i = 0; i < n - 1; i++) {
			*(books + i) = (*this)[i];
		}
		*(books + n - 1) = b;
		delete[] this->ds;
		this->ds = new Book[n];
		for (int i = 0; i < n; i++) {
			(*this)[i] = *(books + i);
		}
		delete[] books;
	}

}

void List::delBook(int idx) 
{
	if ((*this)[idx].getNumberOfBook() == 1) {
		Book * temp = new Book[n - 1];
		for (int i = 0, j = 0; i < n; i++) {
			if (i != idx) {
				*(temp + j++) = (*this)[i];
			}
		}
		delete[] this->ds;
		n = n - 1;
		this->ds = new Book[n];
		for (int i = 0; i < n; i++) {
			(*this)[i] = *(temp + i);
		}
		delete[] temp;
	} else {
		(*this)[idx].setNumberBook((*this)[idx].getNumberOfBook() - 1);
	}
}

void List::showAllBooks()
{
	for (int i = 0; i < n; i++) {
		cout << (*this)[i];
	}
}

void List::showAllBooks(const int n)
{
	for (int i = 0; i < n; i++) {
		cout << (*this)[i];
	}
}

int List::hasBook(Book &b)
{
	for (int i = 0; i < n; i++) {
		if ((*this)[i].getID().compare(b.getID()) == 0) return i; 
	}
	return -1;
}


Book & List::operator[](const int idx)
{
	static Book temp;
	if (idx < this->n && idx >= 0) {
		return *(this->ds + idx);
	}
	return temp;
}
void swap(Book &b1, Book &b2) {
	Book temp = b1;
	b1 = b2;
	b2 = temp;
}
void List::quickSort(int left, int right , bool(*compare)(string , string)) {
	int i = left, j = right;
	Book temp = (*this)[(i + j) / 2];
	do
	{
		while (compare((*this)[i].getID(), temp.getID()) && i < right) i++;
		while (compare(temp.getID(), (*this)[j].getID()) && j > left) j--;
		if (i <= j) {
			swap((*this)[i], (*this)[j]);
			i++; j--;
		}
	} while (i <= j);
	if (left < j) quickSort(left, j, compare);
	if (i < right) quickSort(i, right, compare);
}

int List::getSize()
{
	return this->n;
}

Book * List::binarySearch(int left, int right, int &n,  string ID)
{
	cout << "binarySearch: " << left<< ":"<< right<<  endl;
	if (right >= left) {
		int mid = (left + right) / 2;
		if (ID.compare((ds + mid)->getID()) == 0) {
			int before = mid - 1;
			int after = mid + 1;
			cout << before << " : " << after << endl;
			while (ID.compare((ds + before)->getID()) == 0) before--;
			while (ID.compare((ds + after)->getID()) == 0) after++;
			n = after - before - 1;
			Book * arrBook = new Book[n];
			for (int i = before + 1, j = 0; i < after; i++) {
				*(arrBook + j++) = *(ds + i);
			}
			return arrBook;
		}
		if (ID.compare((ds + mid)->getID()) < 0) {
			return binarySearch(left, mid - 1, n, ID);
		}
		return binarySearch(mid + 1, right, n, ID);
	}
	return NULL;
}

ostream & operator<<(ostream & o, List & l)
{ 
	for (int i = 0; i < l.n; i++) {
		o << l[i] << endl;
	}
	return o;
}

istream & operator>>(istream & ip, List & l)
{
	cout << "Nhap N: ";
	ip >> l.n;
	l.ds = new Book[l.n];

	for (int i = 0; i < l.n; i++) {
		cout << "Phan tu thu " << i + 1 << " : ";
		ip >> l[i];
	}
	return ip;
}

