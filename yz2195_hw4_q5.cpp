#include <iostream>
using namespace std;

int main() {

	int input;
	cout << "Please input a positive integer:";
	cin >> input;
	
	for (int i = input; i >= 1; i -= 1) {

		for (int j = 1; j <= input - i; j += 1) {
			cout << " ";
		}

		cout << "*";

		for (int k = 1; k < i; k += 1) {
			cout << "**";
		}
		cout << endl;
	}
	
	for (int i = 1; i <= input; i += 1) {
		
		for (int j = 1; j <= input - i; j += 1) {
			cout << " ";
		}

		cout << "*";
		
		for (int k = 1; k < i; k += 1) {
			cout<<"**";
		}
		cout << endl;
	}
	return 0;
}