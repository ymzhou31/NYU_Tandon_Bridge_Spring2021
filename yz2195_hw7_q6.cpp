#include <iostream>
#include <string>
#include <vector>
using namespace std;

void main1();

void main2();

const int INITAL_ARRAY_SIZE = 100;

int main() {

	main1();

	main2();

	return 0;

}

void main1() {

	cout << "Main program 1, no vector use:" << endl;
	cout << "Please enter a sequence of positive integers, each in a separate line. End your input by typing -1" << endl;

	bool keep_going = true;
	int input;
	int array_size = 0;
	int* array = new int[INITAL_ARRAY_SIZE];

	while (keep_going) {
		cin >> input;
		if (input == -1) {
			keep_going = false;
		}
		else {
			array_size++;
			
			if (array_size > INITAL_ARRAY_SIZE) {
				int* new_array = new int[INITAL_ARRAY_SIZE * 2];
				for (int i = 0; i < INITAL_ARRAY_SIZE; i++) {
					new_array[i] = array[i];
				}
				delete[] array;
				array = new_array;
			}

			array[array_size - 1] = input;

		}
	}

	int number;
	cout << "Please enter a number you want to search:" << endl;
	cin >> number;
	string locations;

	for (int i = 0; i < array_size; i++) {
		
		if (array[i] == number) {
			if (locations == "") {
				locations = locations + to_string(number) + " shows in lines " + to_string(i + 1);
			}
			else {
				locations = locations + ", " + to_string(i + 1);
			}
			
		}
	}

	cout << locations<<endl<<endl;

}

void main2() {

	cout << "Main program 2, using vector:" << endl;
	cout << "Please enter a sequence of positive integers, each in a separate line. End your input by typing -1" << endl;

	bool keep_going = true;
	int input;
	vector<int> array;

	while (keep_going) {
		cin >> input;
		if (input == -1) {
			keep_going = false;
		}
		else {
			array.push_back(input);
		}
	}

	int number;
	cout << "Please enter a number you want to search:" << endl;
	cin >> number;
	string locations;
	
	for (int i = 0; i < array.size(); i++) {
		
		if (array[i] == number) {
			if (locations == "") {
				locations = locations + to_string(number) + " shows in lines " + to_string(i + 1);
			}
			else {
				locations = locations + ", " + to_string(i + 1);
			}

		}
	}

	cout << locations<<endl<<endl;

}
