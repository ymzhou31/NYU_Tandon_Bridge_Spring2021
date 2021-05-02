#include <iostream>
using namespace std;

void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs);

bool isPerfect(int num);

void printDivisors(int num);

int main() {

	int num;

	cout << "Please enter a positive integer >=2: ";
	cin >> num;

	printDivisors(num);
	
}


void printDivisors(int num) {
	
	int count1, sum1, count2, sum2;

	cout << "Perfect numbers:\n";
	for (int i = 2; i <= num; i++) {
		if (isPerfect(i)) {
			cout << i << " ";
		}
	}
	cout << endl;

	cout << "Amicable pairs:\n";
	for(int j = 2; j <= num; j++){
		analyzeDivisors(j, count1, sum1);
		analyzeDivisors(sum1, count2, sum2);

		if ((sum1 > j) && (sum2 == j)){
			cout <<"(" <<j << ", "<<sum1<<") ";
		}
	}
}


void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs) {

	int count_divs = 0, sum_divs = 0;

	for (int i = 1; i <= sqrt(num); i++) {
		if (num % i == 0) {
			if (i == 1) {
				sum_divs += i;
				count_divs++;
			}
			else {
				sum_divs = sum_divs + i + num / i;
				count_divs += 2;
			}
			

		}
	}
	
	outCountDivs = count_divs;
	outSumDivs = sum_divs;

}

bool isPerfect(int num) {
	int outCountDivs;
	int outSumDivs;

	analyzeDivisors(num, outCountDivs, outSumDivs);

	return (outSumDivs == num);

}