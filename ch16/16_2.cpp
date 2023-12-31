#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <cctype>
#include <algorithm>
using namespace std;

int countWordFreq(const string & fileName, const string &word)
{
	cout << "file path is: " << fileName << endl;
	ifstream ifn(fileName);
	static map<string, int> wordFreq;
	string tword;
	transform(word.begin(), word.end(), tword.begin(), ::tolower);

	if (!wordFreq.empty()) {
		cout << "wordFreq is not empty" << endl;
		cout << wordFreq[word] << endl;
		return wordFreq[word];
	}

	string line;
	while (getline(ifn, line)) {
		if(line.empty()) { continue; }
		stringstream ss(line);
		string w;
		while(ss >> w) {
			transform(w.begin(), w.end(), w.begin(), ::tolower);
			wordFreq[w]++;
		}
	}

	return wordFreq[word];
}

int main()
{
	string fileName;

	cout << "type the book file (full path): " << endl;
	cin >> fileName;
	cout << countWordFreq(fileName, "aa") << endl;


	return 0;
}
