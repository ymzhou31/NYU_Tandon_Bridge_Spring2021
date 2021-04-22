#include <iostream>
using namespace std;

int main() {

	string name, status;
	int grad_year, current_year, years_to_grad;

	cout << "Please enter your name:";
	cin >> name;
	cout << "Please enter your graduation year:";
	cin >> grad_year;
	cout << "Please enter current year:";
	cin >> current_year;

	years_to_grad = grad_year - current_year;

	if (years_to_grad <= 0)	{
		status = "Graduated";
	}
	else	{
		switch (years_to_grad) {
		case 1:
			status = "a Senior";
			break;

		case 2:
			status = "a Junior";
			break;

		case 3:
			status = "a Sophomore";
			break;

		case 4:
			status = "a Freshman";
			break;

		default:
			status = "not in college yet";
			break;
		}
	}
	
	cout << name << ", you are " << status;

	return 0;
}