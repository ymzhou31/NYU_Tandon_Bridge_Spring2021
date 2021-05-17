#include <iostream>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);

int main() {

	int arrSize = 6;
	int arr[] = {5, 2, 11, 7, 6, 4};

	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	oddsKeepEvensFlip(arr, arrSize);

	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << " ";
	}

	return 0;

}

void oddsKeepEvensFlip(int arr[], int arrSize) {
	int* pointer = arr;
	int temp;
	for (int i = 0, j = 1, k = arrSize - 1; i < k;) {
		if (j == arrSize - 1) {
			temp = arr[i];
			arr[i] = arr[k];
			arr[k] = temp;
			i++, k--;
		}
		else {
			if (arr[i] % 2 == 0 && arr[j] % 2 > 0) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				i++, j++;
			}

			if (arr[i] % 2 > 0) {
				i++;
			}
			if (arr[j] % 2 == 0) {
				j++;
			}
		}
	}

}
