#include <iostream>
using namespace std;

void reverseArray(int arr[], int arrSize);

void removeOdd(int arr[], int& arrSize);

void splitParity(int arr[], int arrSize);

void printArray(int arr[], int arrSize) {
	int i;

	for (i = 0; i < arrSize; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl << "array size: " << arrSize << endl;

}

void reverseArray(int arr[], int arrSize) {

	int temp;

	for (int i = 0, j = arrSize - 1; i < j; i++, j--) {
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

}

void removeOdd(int arr[], int& arrSize) {

	int temp;
	int new_size = arrSize;

	for (int i = 0, j = 0; j < arrSize;) {
		
		if (arr[j] % 2 > 0) {
			j++;
			new_size--;
		}
		else {
			if (arr[i] % 2 > 0) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				j++;
			}
			else {
				i++;
			}
		}
		if (j <= i) {
			j++;
		}
	}

	arrSize = new_size;

}

void splitParity(int arr[], int arrSize) {
	
	int temp;

	for (int i = 0, j = arrSize - 1; i < j;) {

		if (arr[i] % 2 > 0) {
			i++;
		}
		if (arr[j] % 2 == 0) {
			j--;
		}
		if (arr[i] % 2 == 0 && arr[j] % 2 > 0) {

			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;

		}
		
	}


}