#include <iostream>
#include <string>
#include <vector>
using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);

int main() {

	string sentence;
	int outWordsArrSize;

	cout << "Please enter your sentence:" << endl;
	getline(cin, sentence);

	string* words_array = createWordsArray(sentence, outWordsArrSize);

	cout << "[";
	for (int i = 0; i < outWordsArrSize; i++) {
		cout << words_array[i];
		if (i < outWordsArrSize - 1) {
			cout << ", ";
		}
	}
	cout << "]" << endl;

	cout << "Word count: " << outWordsArrSize;

	return 0;
}

string* createWordsArray(string sentence, int& outWordsArrSize) {

	string word;

	outWordsArrSize = 0;

	vector<string> words_vector;

	for (int i = 0; i < sentence.length(); i++) {

		if ((sentence[i] >= 'A' && sentence[i] <= 'Z') || (sentence[i] >= 'a' && sentence[i] <= 'z')) {
			word += sentence[i];
		}
		else {
			words_vector.push_back(word);
			outWordsArrSize++;
			word = "";
		}

	}

	if (word != "") {
		outWordsArrSize++;
		words_vector.push_back(word);
		word = "";
	}

	string* words = new string[outWordsArrSize];

	for (int i = 0; i < outWordsArrSize; i++) {
		words[i] = words_vector[i];
	}

	return words;

}