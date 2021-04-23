#include <iostream>
using namespace std;

int main() {

	int input, counter, divisor;
	int even_digits, total_digits;

	cout << "Please input a postive integer:";
	cin >> input;
	
	for (int i = 1; i <= input; i += 1) {
		
		counter = i;
		even_digits = 0;
		total_digits = 0;

		while (counter > 0) {
			
			if (counter % 2 == 0) {
				even_digits += 1;
			}

			counter /= 10;
			total_digits += 1;
			
		}

		if (even_digits > (total_digits - even_digits)) {
			cout << i << endl;
		}
		
	}

	return 0;
}