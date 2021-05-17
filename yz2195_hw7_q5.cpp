#include <iostream>
#include <vector>
using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);

void test_function(int* pos_arr, string function_name, int outPosArrSize);

int main() {

	int array[] = {3, -1, -3, 0, 6, 4};
	int* arr = array;
	int arrSize = 6;
	int outPosArrSize;
	int** outPosArrPtr = nullptr;

	int* outPosArr = getPosNums1(arr, arrSize, outPosArrSize);

	test_function(outPosArr, "getPosNums1", outPosArrSize);

	outPosArr = getPosNums2(arr, arrSize, &outPosArrSize);

	test_function(outPosArr, "getPosNums2", outPosArrSize);

	getPosNums3(arr, arrSize, outPosArr, outPosArrSize);

	test_function(outPosArr, "getPosNums3", outPosArrSize);

	getPosNums4(arr, arrSize, &outPosArr, &outPosArrSize);

	test_function(outPosArr, "getPosNums4", outPosArrSize);

	return 0;

}

void test_function(int* pos_arr, string function_name, int outPosArrSize) {

	cout << function_name <<": " << endl << "[ ";

	for (int i = 0; i < outPosArrSize; i++) {
		cout << pos_arr[i];
		if (i < outPosArrSize - 1) {
			cout << ", ";
		}
	}

	cout << " ]" << endl;

	cout << "Array size: " << outPosArrSize << endl << endl;

	delete[] pos_arr;
	pos_arr = nullptr;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {

	vector<int> pos_arr_vector;
	outPosArrSize = 0;

	for (int i = 0; i < arrSize; i++) {
		if (arr[i] > 0) {
			pos_arr_vector.push_back(arr[i]);
			outPosArrSize++;
		}
	}

	int* pos_arr = new int[outPosArrSize];

	for (int i = 0; i < outPosArrSize; i++) {
		pos_arr[i] = pos_arr_vector[i];
	}

	return pos_arr;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr) {
	
	vector<int> pos_arr_vector;
	*outPosArrSizePtr = 0;

	for (int i = 0; i < arrSize; i++) {
		if (arr[i] > 0) {
			pos_arr_vector.push_back(arr[i]);
			*outPosArrSizePtr += 1;
		}
	}

	int* pos_arr = new int[*outPosArrSizePtr];

	for (int i = 0; i < *outPosArrSizePtr; i++) {
		pos_arr[i] = pos_arr_vector[i];
	}

	return pos_arr;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {

	vector<int> pos_arr_vector;
	outPosArrSize = 0;

	for (int i = 0; i < arrSize; i++) {
		if (arr[i] > 0) {
			pos_arr_vector.push_back(arr[i]);
			outPosArrSize++;
		}
	}

	int* pos_arr = new int[outPosArrSize];

	for (int i = 0; i < outPosArrSize; i++) {
		pos_arr[i] = pos_arr_vector[i];
	}

	outPosArr = pos_arr;

}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {

	vector<int> pos_arr_vector;
	*outPosArrSizePtr = 0;

	for (int i = 0; i < arrSize; i++) {
		if (arr[i] > 0) {
			pos_arr_vector.push_back(arr[i]);
			*outPosArrSizePtr += 1;
		}
	}

	int* pos_arr = new int[*outPosArrSizePtr];

	for (int i = 0; i < *outPosArrSizePtr; i++) {
		pos_arr[i] = pos_arr_vector[i];
	}

	*outPosArrPtr = pos_arr;

}