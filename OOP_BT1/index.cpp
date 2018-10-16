#pragma once
#include <iostream>
#include "Book.h"
#include "List.h"
using namespace std;

bool ascending(string o1, string o2) {
	return o1 < o2;
}
bool descending(string o1, string o2) {
	return o1 > o2;
}
bool checkByID(string id) {

	if (id.length() != 9 || id[0] < '1') return false;
	for (int i = 1; i < 9; i++) {
		if (id[i] < '0') return false;
	}
	return true;
}

void menu(List & arr) {
	int choose = 0;
	cout << "1. show all books of List" << endl;
	cout << "2. add book into list at first position" << endl;
	cout << "3. add book into list at K position" << endl;
	cout << "4. add book into list at END_OF_LIST position" << endl;
	cout << "5. delete book from list at first position" << endl;
	cout << "6. delete book from list at K position" << endl;
	cout << "7. delete book from list at END_OF_LIST position" << endl;
	cout << "8. update book by ID" << endl;
	cout << "9. find Book by ID (BinarySearch): " << endl;
	cout << "10. arrange list by QuickSort Ascending" << endl;
	cout << "11. arrange list by QuickSort Descending" << endl;
	cout << "default: exit!" << endl;
	cout << "Entering you choose: ";
	cin >> choose;
	Book b;
	int k;
	string id;
	switch (choose) {
	case 1:
		arr.showAllBooks();
		break;
	case 2:
		cout << "Nhap thong tin Sach: "<< endl;
		cin >> b;
		arr.addBook(b, 0);
		cout << arr;
		break;
	case 3:
		cout << "Nhap thong tin Sach: " << endl;
		cin >> b;
		do
		{
			cout << "Nhap Vi Tri K Can Chen : ";
			cin >> k;
		} while (k <= 0 || k > arr.getSize());
		arr.addBook(b, k - 1);
		cout << arr;
		break;
	case 4:
		cout << "Nhap thong tin Sach: " << endl;
		cin >> b;
		arr.addBook(b, arr.getSize());
		cout << arr;
		break;
	case 5:
		arr.delBook(0);
		cout << arr;
		break;
	case 6:
		do
		{
			cout << "Nhap Vi Tri K Can Xoa : ";
			cin >> k;
		} while (k <= 0 || k > arr.getSize());
		arr.delBook(k - 1);
		cout << arr;
		break;
	case 7:
		arr.delBook(arr.getSize() - 1);
		cout << arr;
		break;
	case 8: {
		id = "";
		do
		{
			cout << "ID BOOK: ";
			cin.ignore();
			getline(cin, id);
			if (!checkByID(id)) cout << "MOI BAN NHAP LAI ";
		} while (!checkByID(id));
		arr.quickSort(0, arr.getSize() - 1, ascending);
		arr.update(id);
		cout << arr;
		break;
	}
	case 9: {
		id = "";
		do
		{
			cout << "ID BOOK: ";
			cin.ignore();
			getline(cin, id);
			if (!checkByID(id)) cout << "MOI BAN NHAP LAI ";
		} while (!checkByID(id));
		arr.quickSort(0, arr.getSize() - 1, ascending);
		int n;
		Book *p = arr.binarySearch(0, arr.getSize() - 1, n, id);

		for (int i = 0; i < n; i++) {
			(p + i)->show();
		}
		cout << endl;
		break;
	}
	case 10:
		arr.quickSort(0, arr.getSize() - 1, ascending);
		cout << arr;
		break;
	case 11:
		arr.quickSort(0, arr.getSize() - 1, descending);
		cout << arr;
		break;
	default:
		exit(1);
		break;
	}
}

void initData(List & arr) {
	Book toan("100000001", "Toan", 2010, 1);
	Book anh("100000003", "Anh", 2010, 1);
	Book van("100000002", "Van", 2010, 1);
	Book su("100000004", "Van", 2010, 1);
	Book toan2("100000005", "Toan", 2010, 1);

	arr.addBook(toan, 0);
	arr.addBook(anh, 0);
	arr.addBook(van, 0);
	arr.addBook(toan);
	arr.addBook(toan);
	arr.addBook(van);
	arr.addBook(su);
	arr.addBook(toan2);

}
int main() {

	List arr;
	initData(arr);
	do {
		menu(arr);
	} while (true);

	system("pause");
	return 0;
}