#include <iostream>
using namespace std;

int main() {

	int input, temp;
	int powerOf2;

	cout << "Enter decimal number:";
	cin >> input;

	temp = input;
	powerOf2 = 1;

	cout << "The binary representation of " << input << " is ";

	while (powerOf2 < input) {
		powerOf2 *= 2;
	}

	if (powerOf2 > input) {
		powerOf2 /= 2;
	}

	while (temp > 0 || powerOf2 > 0) {
		
		if (temp < powerOf2 || temp == 0)
			cout << 0;
		
		else	{
			cout << 1;
			temp %= powerOf2;
		}

		powerOf2 /= 2;
		
	}

	return 0;

}