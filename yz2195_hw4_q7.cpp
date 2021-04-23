#include <iostream>
using namespace std;

int main() {

	int input, output;

	cout << "Please enter a positive integer:" << endl;
	cin >> input;
	

	for (int i = 1; i <= input; i += 1) {
			
		for (int j = 1; j <= input; j += 1) {

			output = i * j;

			cout << output << "\t";
		}
		cout << endl;
	}

	return 0;
}