#include <iostream>
using namespace std;

void printTriangle(int n);

void printOppositeTriangles(int n);

void printRuler(int n);

int main() {

	printTriangle(4);
	cout << endl;

	printOppositeTriangles(4);
	cout << endl;

	printRuler(4);
	cout << endl;

	return 0;

}


//Part A
void printTriangle(int n) {

	if (n == 0) {
		return;
	}

	else {
		printTriangle(n - 1);
		for (int i = 0; i < n; i++) {
			cout << "*";
		}
		cout << endl;
	}

}


//Part B
void printOppositeTriangles(int n) {
	if (n == 0) {
		return;
	}

	else {
		
		for (int i = 0; i < n; i++) {
			cout << "*";
		}
		cout << endl;

		printOppositeTriangles(n - 1);

		for (int i = 0; i < n; i++) {
			cout << "*";
		}
		cout << endl;
		
		
	}
}

//Part C

void printRuler(int n) {
	if (n <= 1) {
		cout << "-" << endl;
	}
	else {
		printRuler(n - 1);
		for (int i = 0; i < n; i++) {
			cout<<"-";
		}
		cout << endl;
		printRuler(n - 1);
	}
}


