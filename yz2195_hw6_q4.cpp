#include <iostream>
#include <cstdlib>
using namespace std;

const int REAL_PIN = 12345;

void generate_rand_map(int arr[], int arrSize);

bool validate_pin(int real_pin, int input, int arr[], int arrSize);

int main() {

	int map[10];
	int input;

	cout << "Please enter your PIN according to the following mapping:\n";
	cout << "PIN:\t0 1 2 3 4 5 6 7 8 9\n";
	cout << "NUM:\t";
	generate_rand_map(map, 10);
	cout << endl;
	cin >> input;

	if (validate_pin(REAL_PIN, input, map, 10)) {
		cout<<"Your PIN is correct";
	}
	else {
		cout<<"Your PIN is not correct";
	}

	return 0;
}

void generate_rand_map(int arr[], int arrSize) {
	
	for (int i = 0; i < arrSize; i++) {
		arr[i] = rand() % 10;
		cout << arr[i] << " ";
	}
}

bool validate_pin(int real_pin, int input, int arr[], int arrSize) {

	while (input != 0) {

		if ( input % 10 != arr[real_pin % 10] ){
			return false;
		}

		real_pin /= 10;
		input /= 10;
	}

	if (real_pin != 0) {
		return false;
	}
	
	return true;

}
