#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <math.h>
#include <assert.h>
#include <filesystem>
class Word_Distance
{
public:
    Word_Distance(const string file_path) {
        read_file(file_path);
        init_matrix();
        find_min_distances();
    }

    int find_min_distance(const string &word1, const string &word2)
    {
        if (word_matrix.find(word1) == word_matrix.end()
            && word_matrix.find(word2) == word_matrix.end()) {
            cout << "word(s) not found" << endl;
            return -1;
        }
        return word_matrix[word1][word2];
    }

private:
    unordered_map<string, vector<int>> word_occ;
    unordered_map<string, unordered_map<string, int>> word_matrix;

    const void read_file(const string file_path) {
        ifstream file;
        file.open(file_path);
        if (file.is_open()) {
            string word;
            int index = 0;
            while (file >> word) {
                if (word_occ.find(word) == word_occ.end()) {
                    word_occ.insert({ word, vector<int>() });
                }
                word_occ[word].push_back(index);
                index++;
            }
        }
    }

    void init_matrix() {
        for (auto &m : word_occ) {
            word_matrix.insert({ m.first, unordered_map <string, int>() });
        }
        for (auto &w : word_matrix) {
            for (auto &w2 : word_matrix) {
                word_matrix[w.first].insert({ w2.first, 0 });
            }
        }
    }

    void find_min_distances() {
        vector<string> comb_pair;
        comb_pair.reserve(word_occ.size());

        for (auto &w : word_occ) {
            comb_pair.push_back(w.first);
        }

        // do as little computations as possible
        for (int i = 0; i < comb_pair.size(); i++) {
            for (int j = i + 1; j < comb_pair.size(); j++) {
                int sol = _find_min_distance(comb_pair[i], comb_pair[j]);
                word_matrix[comb_pair[i]][comb_pair[j]] = sol;
                word_matrix[comb_pair[j]][comb_pair[i]] = sol;
            }
        }
    }

    int _find_min_distance(const string &word1, const string &word2) {
        // l1 and l2 are assumed sorted
        vector<int> l1 = word_occ[word1];
        vector<int> l2 = word_occ[word2];

        int min_pair_dist = INT_MAX;
        int iter1 = 0, iter2 = 0;
        while (iter1 < l1.size() || iter2 < l2.size()) {
            int cur_diff = abs(l1[iter1] - l2[iter2]);
            min_pair_dist = min(min_pair_dist, cur_diff);

            if (l1[iter1] < l2[iter2] && iter1 < l1.size() - 1)
                iter1++;
            else if (l1[iter1] >= l2[iter2] && iter2 < l2.size() - 1)
                iter2++;
            else break; // guarenteed to maintain minimum value
        }

        return min_pair_dist;
    }
};

int main()
{
    const string filepath = "../infile/rand.txt";
    Word_Distance wd(filepath);
    assert(wd.find_min_distance("the", "the") == 0);
    assert(wd.find_min_distance("ten", "years") == 1);
    assert(wd.find_min_distance("sisters", "enhanced") == 2);
    assert(wd.find_min_distance("sisters", "each") == 3);
    assert(wd.find_min_distance("race", "established") == 5);
    assert(wd.find_min_distance("established", "race") == 5);
}
