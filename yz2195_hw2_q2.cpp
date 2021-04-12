#include <iostream>
using namespace std;

const int CENTS_IN_DOLLAR = 100;
const int CENTS_IN_QUARTER = 25;
const int CENTS_IN_DIME = 10;
const int CENTS_IN_NICKEL = 5;


int main() {

	int dollars, cents, total, temp;
	int	min_quarters, min_dimes, min_nickels, min_pennies;

	cout << "Please enter your amount in the format of dollars and cents separated by a space:" << endl;
	cin >> dollars >> cents;

	total = dollars * CENTS_IN_DOLLAR + cents;
	temp = total;

	min_quarters = temp / CENTS_IN_QUARTER;
	temp %= CENTS_IN_QUARTER;
	min_dimes = temp / CENTS_IN_DIME;
	temp %= CENTS_IN_DIME;
	min_nickels = temp / CENTS_IN_NICKEL;
	temp %= CENTS_IN_NICKEL;
	min_pennies = temp;

	cout << dollars << " dollars and " << cents << " cents are:" << endl;
	cout << min_quarters << " quarters, " << min_dimes << " dimes, " << min_nickels << " nickels and " << min_pennies << " pennies";

	return 0;
}