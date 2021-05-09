#include <iostream>
using namespace std;

const int MAX_ARRAY_SIZE = 20;

int minInArray(int arr[], int arrSize);

int main() {

	int input, min;
	int arr[MAX_ARRAY_SIZE];

	cout << "Please enter "<<MAX_ARRAY_SIZE<<" integers separated by a space:\n";
	for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
		cin >> input;
		arr[i] = input;
	}

	min = minInArray(arr, MAX_ARRAY_SIZE);

	cout << "The minimum value is " << min << " and it is located in the following indices: ";

	for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
		if (arr[i] == min) {
			cout << i << " ";
		}
	}

	return 0;
}

int minInArray(int arr[], int arrSize) {

	int min = arr[0];

	for (int i = 0; i < arrSize; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}

	return min;

}



