#include <iostream>
#include <cmath>
using namespace std;

int main() {

	//implementation using for loop
	cout << "section a"<<endl;
	int length;
	double geometric_mean;
	
	cout << "Please enter the length of the sequence:";
	cin >> length;
	cout << "Please enter your sequence:" << endl;

	int input;
	int sequence = 1;

	for (int i = 0; i < length; i += 1) {
		cin >> input;
		sequence *= input;
	}

	geometric_mean = pow((double)sequence, 1 / (double)input);

	cout << "The geometric mean is: " << geometric_mean << endl<<endl;

	
	//implementation using while loop
	cout << "section b" << endl;
	cout << "Please enter a non-empty sequence of positive integers each on in a separate line. End your sequence by typing -1:" << endl;
	
	input = 1;
	sequence = 1;
	double i = 0;

	while (input != -1) {
		cin >> input;
		if (input > 0) {
			sequence *= input;
			i += 1;
		}
	}
	
	geometric_mean = pow((double)sequence, 1/i);
	cout << "The geometric mean is: " << geometric_mean << endl;

	return 0;
}