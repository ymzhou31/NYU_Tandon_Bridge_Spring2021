#include <iostream>
#include <string>
using namespace std;

void input_analysis(string input);

void print_analysis(int word_count, char*letter_map, int* letter_count);

int main() {

	string input;
	cout << "Please enter a line of text"<<endl;
	getline(cin, input);

	input_analysis(input);

}

void input_analysis(string input) {

	int word_count = 0;
	string word;
	char* letter_map = new char[26]();
	int* letter_count = new int[26]();
	char a = 'a';

	for (int i = 0; i < 26; i++) {
		letter_map[i] = a;
		a++;
	}

	for (int i = 0; i < input.length(); i++) {
		if (input[i] == ' ' || input[i] == '.' || input[i] == ',') {
			if (word != "") {
				word_count++;
			}
			word = "";
		}
		else {
			if (input[i] >= 'A' && input[i] <= 'Z') {
				letter_count[input[i] - 'A']++;
				word += letter_count[input[i] - 'A']++;
			}
			if (input[i] >= 'a' && input[i] <= 'z') {
				letter_count[input[i] - 'a']++;
				word += letter_count[input[i] - 'a'];
			}
		}

	}

	if (word != "") {
		word_count++;
	}

	print_analysis(word_count, letter_map, letter_count);

}

void print_analysis(int word_count, char* letter_map, int* letter_count) {

	cout << word_count << "\twords"<<endl;

	for (int i = 0; i < 26; i++) {
		if (letter_count[i] > 0) {
			cout << letter_map[i] << "\t";
			cout << letter_count[i] << endl;
		}
	}
}