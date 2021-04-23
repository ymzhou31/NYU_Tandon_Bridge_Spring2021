#include <iostream>
#include <string>
using namespace std;

const int M = 1000, D = 500, C = 100, L = 50, X = 10, V = 5, I = 1;

int main() {

	int num, temp;
	string output = "";

	cout << "Enter decimal number:";
	cin >> num;
	
	temp = num;

	while (temp >= M) {
		temp -= M;
		output.append("M");
	}

	if (temp >= D) {
		temp -= D;
		output.append("D");
	}
	
	while (temp >= C) {
		temp -= C;
		output.append("C");
	}

	if (temp >= L) {
		temp -= L;
		output.append("L");
	}

	while (temp >= X) {
		temp -= X;
		output.append("X");
	}

	if (temp >= V) {
		temp -= V;
		output.append("V");
	}

	while (temp >= I) {
		temp -= I;
		output.append("I");
	}

	cout << num << " is " << output;
}