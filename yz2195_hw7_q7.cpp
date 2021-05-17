#include <iostream>
using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);

int main() {

	int* resArr;
	int resArrSize = 0;
	int n = 6;
	
	int arr[] = { 3, 1, 3, 0, 6, 4 };

	resArr = findMissing(arr, n, resArrSize);

	cout << "Original array:" << endl;

	for (int i = 0; i < n; i++) {
		if (i < n - 1) {
			cout << arr[i] << ", ";
		}
	}

	cout << endl << "Missing Numbers: ";

	for (int i = 0; i < resArrSize; i++) {
		if (i < resArrSize - 1) {
			cout << resArr[i] << ", ";
		}
		else {
			cout << resArr[i];
		}
	}

	cout << endl << "resArrSize = " << resArrSize;

	return 0;

}

int* findMissing(int arr[], int n, int& resArrSize) {

	int* range = new int[n + 1]();
	
	for (int i = 0; i < n; i++) {
		range[arr[i]] = -1;
	}

	for (int i = 0; i < n; i++) {
		if (range[i] > -1) {
			range[i] = i;
			resArrSize++;
		}
	}

	int* res_arr = new int[resArrSize];

	for (int i = 0, j = 0; i < n; i++) {
		if (range[i] > -1) {
			res_arr[j] = range[i];
			j++;
		}
	}

	delete[] range;

	return res_arr;

}