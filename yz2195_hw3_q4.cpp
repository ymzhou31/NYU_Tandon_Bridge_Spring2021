#include <iostream>
using namespace std;

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

int main() {

	double num;
	int option;
	int result;

	cout << "Please enter a Real number:" << endl;
	cin >> num;
	cout << "Choose your rounding method:" << endl;
	cout << "1. Floor round" << endl;
	cout << "2. Ceiling round" << endl;
	cout << "3. Round to the nearest whole number" << endl;
	cin >> option;

	
	switch (option) {

	case FLOOR_ROUND:
		if (num >= 0)
			result = num;
		else if (num == (int)num)
			result = num;
		else
			result = num - 1;
		cout << result;
		break;

	case CEILING_ROUND:
		if (num == (int)num)
			result = num;
		else if	(num >= 0)
			result = num + 1;
		else
			result = num;
		cout << result;
		break;

	case ROUND:
		if (num >= 0)
			result = num + .5;
		else
			result = num - 0.5;
		cout << result;
		break;

	default:
		cout << "Not a valid input";
		break;
	}
	
	return 0;
}