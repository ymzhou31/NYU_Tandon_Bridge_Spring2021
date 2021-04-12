#include <iostream>
using namespace std;

const int CENTS_IN_DOLLAR = 100;
const int CENTS_IN_QUARTER = 25;
const int CENTS_IN_DIME = 10;
const int CENTS_IN_NICKEL = 5;

int main() {

	int quarters, dimes, nickels, pennies, dollars, cents;
	int total, total_dollars, total_cents;
	

	cout << "Please enter number of coins:"<<endl;
	cout << "# of quarters: ";
	cin >> quarters;
	cout << "# of dimes: ";
	cin >> dimes;
	cout << "# of nickels: ";
	cin >> nickels;
	cout << "# of pennies: ";
	cin >> pennies;

	total = quarters * CENTS_IN_QUARTER + dimes * CENTS_IN_DIME + nickels * CENTS_IN_NICKEL + pennies;

	total_dollars = total / CENTS_IN_DOLLAR;
	total_cents = total % CENTS_IN_DOLLAR;

	cout << "The total is "<<total_dollars<<" dollars and "<<total_cents<<" cents";

	return 0;
}