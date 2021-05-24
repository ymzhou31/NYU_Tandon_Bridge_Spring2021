#include <iostream>
using namespace std;

int sumOfSquares(int arr[], int arrSize);

bool isSorted(int arr[], int arrSize);

int main() {

	int arr[] = {-1,  2, 3, 10 };

	cout << sumOfSquares(arr, 4) << endl;

	if (isSorted(arr, 4)) {
		cout << "The array is sorted";
	}
	else {
		cout << "The array is not sorted";
	}

	return 0;
}


//Part A
int sumOfSquares(int arr[], int arrSize) {
	
	int sum = 0;
	int square = 0;
	
	if (arrSize == 0) {
		return sum;
	}
	sum += sumOfSquares(arr, arrSize - 1);
	square = arr[arrSize - 1] * arr[arrSize - 1];
	sum += square;
	return sum;

}

//Part B
bool isSorted(int arr[], int arrSize) {

	if (arrSize == 0) {
		return true;
	}

	if (arr[arrSize - 1] >= arr[arrSize - 2]) {
		return isSorted(arr, arrSize - 1);
	}
	return false;
	
}

