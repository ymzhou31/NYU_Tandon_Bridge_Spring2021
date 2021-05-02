#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void printDivisors(int num);

int main() {

	int input;

	cout << "Please enter a positive integer >= 2: ";
	cin >> input;

	printDivisors(input);

}

void printDivisors(int num) {

	for (int i = 1; i <= sqrt(num); i++) {
		if (num % i == 0) {
			cout << i << " ";
		}
	}
	for (int i = sqrt(num); i >= 1; i--) {
		if (num % i == 0 && i != sqrt(num)) {
			cout << num/i << " ";
		}
	}
}