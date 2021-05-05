#include <iostream>
using namespace std;

int main() {

	int n;

	cout << "Please enter a positive integer: ";
	cin >> n;

	char symbol1 = 'X', symbol2 = 'O', temp;

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= n; j++) {
			
			if (j % 2 == 0) {
				cout<<symbol2;
			}
			else {
				cout<<symbol1;
			}
			
		}

		temp = symbol1; symbol1 = symbol2; symbol2 = temp;

		cout << endl;
	}
}