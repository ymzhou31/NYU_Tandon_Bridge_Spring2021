#include <iostream>
using namespace std;

int fib(int n);

int main() {

	int num, fib_term;


	cout << "Please enter a positive integer:";
	cin >> num;
	fib_term = fib(num);
	cout << fib_term;

	return 0;
	
}

int fib(int n) {
	int f1 = 1;
	int f2 = 1;
	int current_term;

	if (n < 3) {
		return f1;
	}

	for (int i = 0; i < n-2; i++) {
		current_term = f1 + f2;
		f1 = f2;
		f2 = current_term;
		
	}

	return current_term;
	
}