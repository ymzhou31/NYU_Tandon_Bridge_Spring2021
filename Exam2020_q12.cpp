#include <iostream>
using namespace std;

int main() {

	int n, evens_digits = 0, digits_count = 0, more_evens = 0;
	bool counter = true;

	cout<<"Please enter a sequence of positive integers, each one in a separate line. End your sequence by typing -1: \n";

	while (counter) {
		cin >> n;
		if (n == -1) {
			counter = false;
		}
		else {
			while (n > 0) {
				if (n % 2 == 0) {
					evens_digits++;
				}
				n /= 10;
				digits_count++;
			}
			if (evens_digits > (digits_count - evens_digits)) {
				more_evens++;
			}
			evens_digits = 0;
			digits_count = 0;

		}

	}

	cout << "You entered " << more_evens << " more-even numbers";

	return 0;

}