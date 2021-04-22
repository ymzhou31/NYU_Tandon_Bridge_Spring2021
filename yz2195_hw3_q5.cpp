#include <iostream>
using namespace std;

const float KILO_IN_POUNDS = 0.453592;
const float METERS_IN_INCH = 0.0254;

int main() {
	float BMI, weight, height;
	string status;

	cout << "Please enter weight (in pounds): ";
	cin >> weight;
	cout << "Please enter height (in inches): ";
	cin >> height;

	if (height == 0) {
		cout << "Invalid height input";
	}
	else {
		BMI = (weight * KILO_IN_POUNDS) / ((height * METERS_IN_INCH)* (height * METERS_IN_INCH));
		if (BMI < 18.5) {
			status = "Underweight";
		}
		else if (BMI < 25) {
			status = "Normal";
		}
		else if (BMI < 30) {
			status = "Overweight";
		}
		else {
			status = "Obese";
		}
		
		cout << "The weight status is: " << status;
	}

	return 0;
}