#include <iostream>
using namespace std;

bool isPalindrome(string str);

int main() {
	string str;
	cout << "Please enter a word: ";
	cin >> str;

	if (isPalindrome(str)) {
		cout << str << " is a palindrome";
	}
	else {
		cout << str << " is not a palindrome";
	}

	return 0;
}

bool isPalindrome(string str) {

	for (int i = 0, j = str.length() - 1; i < j; i++, j--) {
		if (str.at(i) != str.at(j)) {
			return false;
		}
	}

	return true;

}
