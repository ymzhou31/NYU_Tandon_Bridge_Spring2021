#include <iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol);

void printPineTree(int n, char symbol);

int main() {

	int triangles;
	char character;

	cout << "Please enter the number of triangles you want in your tree:\n";
	cin >> triangles;
	cout << "Please enter the character you to build the tree with:\n";
	cin >> character;

	printPineTree(triangles, character);

}

void printShiftedTriangle(int n, int m, char symbol) {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m + n - i; j++) {
			cout << " ";
		}
		for (int k = 1; k < 2*i; k++) {
			cout << symbol;
		}
		cout << endl;
	}
}

void printPineTree(int n, char symbol) {

	for (int i = 1; i <= n; i++) {
		printShiftedTriangle(i + 1, n - i, symbol);
	}

}