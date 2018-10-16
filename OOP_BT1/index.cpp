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

void menu(List & arr) {
	int choose = 0;
	cout << "1. show all books of List" << endl;
	cout << "2. add book into list at first position" << endl;
	cout << "3. add book into list at K position" << endl;
	cout << "4. add book into list at END_OF_LIST position" << endl;
	cout << "5. delete book from list at first position" << endl;
	cout << "6. delete book from list at K position" << endl;
	cout << "7. delete book from list at END_OF_LIST position" << endl;
	cout << "8. update book by id" << endl;
	cout << "9. find Book by ID (BinarySearch): " << endl;
	cout << "10. arrange list by QuickSort" << endl;
	cout << "default: exit!" << endl;
	cout << "Entering you choose: ";
	cin >> choose;
	Book b;
	switch (choose) {
	case 1:
		arr.showAllBooks();
		break;
	case 2:
		arr.addBook(b, 0);
		break;
	case 3:
		arr.addBook(b, 0);
		break;
	case 4:
		arr.addBook(b, arr.getSize());
		break;
	case 5:
		arr.delBook(0);
		break;
	case 6:
		arr.delBook(0);
		break;
	case 7:
		arr.delBook(arr.getSize() - 1);
		break;
	case 8:
	
		break;
	case 9:
		arr.quickSort(0, arr.getSize() - 1, ascending);
		break;
	case 10:
		int n;
		arr.binarySearch(0, arr.getSize() - 1, n ,"0");
		break;
	default:
		exit(1);
		break;
	}
}

int main() {

	Book toan("100000001", "Toan", 2010, 1);
	Book anh("100000003", "Anh", 2010, 1);
	Book van("100000002", "Van", 2010, 1);
	Book su("100000004", "Van", 2010, 1);
	Book toan2("100000005", "Toan", 2010, 1);
	List arr;

	arr.addBook(toan, 0);
	arr.addBook(anh, 0);
	arr.addBook(van, 0);
	arr.addBook(toan);
	arr.addBook(toan);
	arr.addBook(van);
	arr.addBook(su);
	arr.addBook(toan2);
	arr.quickSort(0, arr.getSize() - 1, descending);
	int n = 0;
	Book *p = arr.binarySearch(0, arr.getSize() - 1, n, "100000005");
	cout << arr;
	string ad = "100000002";
	cout << (ad.compare("100000001")) << endl;
	for (int i = 0; i < n; i++) {
		(p + i)->show();
	}

	system("pause");
	return 0;
}