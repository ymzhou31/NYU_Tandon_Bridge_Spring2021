#include <iostream>
using namespace std;

int jump_it(int arr[], int arrSize);

int main() {

	int arr[] = { 0, 3, 80, 6, 57, 10};

	cout << "The cost of this game is: "<<jump_it(arr, 6);

}

int jump_it(int arr[], int arrSize) {
	
	int cost = 0;

	if (arrSize <= 1) {
		return 0;
	}
	if (arrSize == 2) {
		return arr[1];
	}
	else {
		if (arr[arrSize - 1] <= arr[arrSize - 2]) {
			cost += arr[arrSize - 1];
		}
		else {
			cost += arr[arrSize - 2];
		}

		cost += jump_it(arr, arrSize - 2);
		return cost;
	}

}