#include <iostream>
using namespace std;

const int MINUTES_IN_DAYS = 1440, MINUTES_IN_HOURS = 60;

int main() {
	
	int John_days, John_hours, John_minutes;
	int Bill_days, Bill_hours, Bill_minutes;
	int John_total, Bill_total, total;
	int total_days, total_hours, total_minutes, temp;
		
	cout << "Please enter the number of days John has worked:";
	cin >> John_days;
	cout << "Please enter the number of hours John has worked:";
	cin >> John_hours;
	cout << "Please enter the number of minutes John has worked:";
	cin >> John_minutes;

	cout << "Please enter the number of days Bill has worked:";
	cin >> Bill_days;
	cout << "Please enter the number of hours Bill has worked:";
	cin >> Bill_hours;
	cout << "Please enter the number of minutes Bill has worked:";
	cin >> Bill_minutes;

	John_total = John_days * MINUTES_IN_DAYS + John_hours * MINUTES_IN_HOURS + John_minutes;
	Bill_total = Bill_days * MINUTES_IN_DAYS + Bill_hours* MINUTES_IN_HOURS + Bill_minutes;
	total = John_total + Bill_total;

	temp = total;

	total_days = temp / MINUTES_IN_DAYS;
	temp = total % MINUTES_IN_DAYS;
	total_hours = temp / MINUTES_IN_HOURS;
	temp = total % MINUTES_IN_HOURS;
	total_minutes = temp;

	cout << "The total time both of them worked together is: " << total_days << " days, ";
	cout<<  total_hours << " hours, and " << total_minutes << " minutes.";

	return 0;

}
