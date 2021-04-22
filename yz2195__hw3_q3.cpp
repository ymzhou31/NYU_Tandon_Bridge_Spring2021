#include <iostream>
#include <cmath>
using namespace std;

int main() {

	double a, b, c;
	double sqrt_value;
	double solution1, solution2;
	string solution_count;

	cout << "Please enter value of a: ";
	cin >> a;
	cout << "Please enter value of b: ";
	cin >> b;
	cout << "Please enter value of c: ";
	cin >> c;

	if (a == 0) {
		if (b == 0 && c == 0) {
			solution_count = "infinite solutions";
		}
		else {
			solution_count =  "no solution";
		}
	}

	else	{
		sqrt_value = pow(b, 2) - 4 * a * c;

		if (sqrt_value < 0) {
			solution_count = "no real solution";
		}
		else if (sqrt_value == 0) {
			solution1 = -b / (2 * a); 
			solution_count = "a single real solution";
		}
		else	{
			solution1 = (-b + sqrt(sqrt_value)) / (2 * a);
			solution2 = (-b - sqrt(sqrt_value)) / (2 * a);

			solution_count = "two real solutions";
		}
	}

	cout << "This equation has " << solution_count;
	if (solution_count == "a single real solution") {
		cout << " x = " << solution1;
	}
	else if (solution_count == "two real solutions") {
		cout << " x = " << solution1 <<", " << solution2;
	}

	return 0;

}