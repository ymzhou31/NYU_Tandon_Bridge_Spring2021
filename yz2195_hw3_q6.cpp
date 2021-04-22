#include <iostream>
using namespace std;

int main() {
	int hours, minutes, time;
	int length;
	string day;
	char colon;
	float cost;


	cout << "Please input day of the week: ";
	cin >> day;
	cout << "Time call started (24 hour notation): ";
	cin >> hours >> colon >> minutes;
	cout << "Length of call in minutes: ";
	cin >> length;

	time = hours * 100 + minutes;
	
	if (day == "Sa" || day == "Su") {
		cost = 0.15 * length;
	}

	else if (day == "Mo" || day == "Tu" || day == "We" || day == "Th" || day == "Fr") {
		if (time >= 800 && time <= 1800)	{
			cost = 0.40 * length;
		}
		else {
			cost = 0.25 * length;
		}

		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);

		cout << "Cost of the call is: $" << cost;
	}
	else {
		cout << "Not a valid day for input.";
	}

	return 0;
}