#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const string REAL_PIN = "12345";

void generate_rand_map(char arr[], int arrSize);

bool validate_pin(string real_pin, string input, char arr[], int arrSize);

int main() {

	char map[10];
	string input;
	srand(time(0));

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

void generate_rand_map(char arr[], int arrSize) {
	
	for (int i = 0; i < arrSize; i++) {
		arr[i] = '0' + rand() % 10;
		cout << arr[i] << " ";
	}
}

bool validate_pin(string real_pin, string input, char arr[], int arrSize) {

	if (real_pin.length() != input.length()) {
		return false;
	}

	for (int i = 0; i < input.length(); i++) {

		if ( input.at(i) != arr[(real_pin.at(i) - '0')]){
			return false;
		}

	}

	return true;

}
