#include <iostream>
using namespace std;

void format_name(string first_name, string middle_name, string last_name);

int main() {

	string first, middle, last;

	cout << "Please enter your first, middle, and last name:\n";
	cin >> first >> middle >> last;
	format_name(first, middle, last);

	return 0;
}

void format_name(string first_name, string middle_name, string last_name) {

	string formatted_name;

	formatted_name = last_name + ", " + first_name + " " + middle_name.at(0) + ".";

	cout<<formatted_name;
}