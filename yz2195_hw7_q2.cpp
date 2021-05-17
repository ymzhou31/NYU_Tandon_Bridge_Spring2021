#include <iostream>
#include <string>
using namespace std;

int* parse_line(string input);
bool compare_parsed_strings(int* input1, int* input2);


int main() {
	string input1;
	string input2;
	
	cout << "Please input your first string:\n";
	getline(cin, input1);
	cout << "Please input second string:\n";
	getline(cin, input2);

	bool strings_equal;
	
	strings_equal = compare_parsed_strings(parse_line(input1), parse_line(input2));

	if (strings_equal) {
		cout << "Two strings are anagrams";
	}
	else {
		cout << "Two strings are not anagrams";
	}

	return 0;
}

int* parse_line(string input) {
	
	int* letter_count = new int[26]();

	for (int i = 0; i < input.length(); i++) {
		if (input[i] >= 'A' && input[i] <= 'Z') {
			letter_count[input[i] - 'A']++;
		}
		else if (input[i] >= 'a' && input[i] <= 'z') {
			letter_count[input[i] - 'a']++;
		}
	}
		return letter_count;
}

bool compare_parsed_strings(int* input1, int* input2) {
	for (int i = 0; i < 26; i++) {
		if (input1[i] != input2[i]) {
			return false;
		}
	}
	return true;
}