#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

	int lowerbound = 1, upperbound = 100;
	int guess;

	srand(time(0));
	int number = (rand() % 100) + 1;

	cout << "I thought of a number between 1 and 100! Try to guess it."<<endl;
	
	for (int i = 5; i > 0; i -= 1) {
		cout << "Range: [" << lowerbound << ", " << upperbound << "], Number of guesses left: " << i <<endl;
		cout << "Your guess: ";
		cin >> guess;

		if (guess == number) {
			cout << "Congrats! You guessed my number in " << 6 - i << " guesses" << endl;
			break;
		}

		else if (guess < number) {
			cout << "Wrong! My number is bigger."<<endl;
			lowerbound = guess + 1;
		}

		else {
			cout << "Wrong! My number is smaller." << endl;
			upperbound = guess - 1;
		}

		if (i == 1) {
			cout << "Out of guesses! My number is " << number << endl;
		}
	}

	return 0;

}