#include <iostream>
using namespace std;

int main() {

	int count;
	cout << "Please enter a positive integer:";
	cin >> count;
	int i = 1;
	int result = 2;
	
	//implementation using while loop
	cout << "section a" << endl;

	while (i <= count) {
		cout << result << endl;
		result += 2;
		i += 1;
	}

	//implementation using for loop
	cout << "section b" << endl;

	for (i = 1, result = 2; i <= count; i += 1, result +=2) {
		cout << result << endl;
	}

	return 0;
}