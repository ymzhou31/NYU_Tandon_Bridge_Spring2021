#include <iostream>
#include <cmath>
using namespace std;

int printMonthCalendar(int numOfDays, int startingDay);

bool leapYear(int year);

void printYearCalendar(int year, int startingDay);

int main() {
	
	int year, startingDay;
	cout << "Please enter the year:";
	cin >> year;
	cout << "Please enter the day 1/1 starts on:";
	cin >> startingDay;

	printYearCalendar(year, startingDay);
}

int printMonthCalendar(int numOfDays, int startingDay) {
	cout << "Mon\tTue\tWed\tThr\tFri\tSat\tSun\n";
	int day_tracker = 1;
	int weeks_in_month = ceil((numOfDays + startingDay) / 7.0);
	
	for (int i = 1; i <= weeks_in_month; i++){
		for (int j = 1; j <= 7; j++) {
			if (i == 1 && j < startingDay) {
				cout << "\t";
			}
			else {
				cout << day_tracker<<"\t";
				
				if (day_tracker == numOfDays) {
					return j;
				}

				day_tracker += 1;
			}			
		}
		cout << endl;
	}
}

bool leapYear(int year) {

	if (year % 400 == 0)
		return true;

	if (year % 100 == 0)
		return false;
	
	if (year % 4 == 0)
		return true;

	return false;
	
}

void printYearCalendar(int year, int startingDay) {

	int total_days = 365;
	int days_in_month;
	int start_day_month = startingDay;

	if (leapYear(year)) {
		total_days = 366;
	}

	for (int i = 1; i <= 12; i++) {

		switch (i)	{
		case(1):
				cout << "January " << year << endl;
				days_in_month = 31;
				break;

		case(2):
				cout << "February " << year << endl;
				if (leapYear(year)) {
					days_in_month = 29;
				}
				else {
					days_in_month = 28;
				}
				break;
				
		case(3):
				cout << "March " << year << endl;
				days_in_month = 31;
				break;
			
		case(4):
				cout << "April " << year << endl;
				days_in_month = 30;
				break;
			
		case(5):
				cout << "May " << year << endl;
				days_in_month = 31;
				break;
			
		case(6):
				cout << "June " << year << endl;
				days_in_month = 30;
				break;
			
		case(7):
				cout << "July " << year << endl;
				days_in_month = 31;
				break;
		
		case(8):
				cout << "August " << year << endl;
				days_in_month = 31;
				break;
		
		case(9):
				cout << "September " << year << endl;
				days_in_month = 30;
				break;
			
		case(10):
				cout << "October " << year << endl;
				days_in_month = 31;
				break;
			
		case(11):
				cout << "November " << year << endl;
				days_in_month = 30;
				break;
		
		case(12):
				cout << "December " << year << endl;
				days_in_month = 31;
				break;

		default:
			break;
		}

		start_day_month = printMonthCalendar(days_in_month, start_day_month) + 1;
		cout << endl << endl;
	}

}