#include <iostream>
#include <string>
using namespace std;

string parse_text(string input);

string evaluate_word(string word);

int main() {

	string input;

	cout << "Please enter a line of text:\n";
	getline(cin, input);
	cout << parse_text(input);

	return 0;

}

string parse_text(string input) {

	string word;
	string parsed_text;

	for (int i = 0; i < input.length(); i++) {
		if (input.at(i) == ' ') {
			parsed_text += evaluate_word(word) + " ";
			word = "";
		}
		else {
			word += input.at(i);
		}
	}

	if (word != "") {
		parsed_text += evaluate_word(word);
	}

	return parsed_text;
}

string evaluate_word(string word) {
	for (int i = 0; i < word.length(); i++) {
		if (word.at(i) < '0' || word.at(i) > '9') {
			return word;
		}
	}

	for (int i = 0; i < word.length(); i++) {
		word.at(i) = 'x';
	}

	return word;
}