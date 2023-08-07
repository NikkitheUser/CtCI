#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
class cellPhone_word {
public:
    cellPhone_word(string dictionaryPath) {
        // preprocess file
        ifstream file;
        if (file.good()) {
            file.open(dictionaryPath, fstream::in);
        }

        // assuming dictionary is well formatted.

        string word;
        while (file >> word) {
            // first concatenate the digits that form the word
            string digit_s = "";
            for (auto &i : word) {
                digit_s += char_to_digit.find(i)->second;
            }

            // map to hash map
            // if word exists, then add to vector
            auto &find = main_map.find(digit_s);
            if (find == main_map.end()) {
                // not found, create a new vect
                vector<string> *newVec = new vector<string>;
                newVec->push_back(word);
                main_map.insert({ { digit_s }, { newVec } });
            }
            // found so just insert word to key
            else {
                find->second->push_back(word);
            }
        }
    }

    vector<string>* getWords(string key) {
        return main_map.find(key)->second;
    }

private:
    // need to use string, since words can be extremely long
    unordered_map<string, vector<string>*> main_map;

    const map<const char, const char> char_to_digit =
    {
        { { 'a' },{ '2' } }, { { 'b' },{ '2' } }, { { 'c' },{ '2' } },
        { { 'd' },{ '3' } }, { { 'e' },{ '3' } }, { { 'f' },{ '3' } },
        { { 'g' },{ '4' } }, { { 'h' },{ '4' } }, { { 'i' },{ '4' } },
        { { 'j' },{ '5' } }, { { 'k' },{ '5' } }, { { 'l' },{ '5' } },
        { { 'm' },{ '6' } }, { { 'n' },{ '6' } }, { { 'o' },{ '6' } },
        { { 'p' },{ '7' } }, { { 'q' },{ '7' } }, { { 'r' },{ '7' } },
        { { 's' },{ '7' } }, { { 't' },{ '8' } }, { { 'u' },{ '8' } },
        { { 'v' },{ '8' } }, { { 'w' },{ '9' } }, { { 'x' },{ '9' } },
        { { 'y' },{ '9' } }, { { 'z' },{ '9' } }
    };

};

int main()
{
    const string filepath = "C:/Users/Gamer/Desktop/C++ Daily/words.txt";
    cellPhone_word test(filepath);

    vector<string>* strings = test.getWords("8733");
    for (auto &s : *strings) cout << s << " ";
    cout << endl;
}
