#include <iostream>
#include <vector>
#include <unordered_set>
#include <assert.h>
using namespace std;
//sparse similarity
//The similarity of two documents (each with distinct words) is defined to be the size of the intersection 
//divided by the size of the union. For example, if the documents consist of integers, the similarity of {1, 5, 3} and {1, 7, 2, 3} is e. 4, 
//because the intersection has size 2 and the union has size 5. We have a long list of documents 
//(with distinct values and each with an associated ID) where the similarity is believed to be "sparse:'That is,
//any two arbitrarily selected documents are very likely to have similarity O. Design an algorithm that returns a list of pairs of 
//document IDs and the associated similarity. Print only the pairs with similarity greater than O. Empty documents should not be 
//printed at all. For simplicity, you may assume each document is represented as an array of distinct integers.

//we just unload the combos, calculate intersections
//took a while to understand 
//some of these ideas had to be taken from elsewhere
//Understood how to find this in normal calculations
//took a few hours(and a lot of youtube videos) to do calculations in C++
unordered_set<int> calc_union(const vector<int> &one, const vector<int> &two) {
    unordered_set<int> unioned;
    unioned.reserve(max(one.size(), two.size()));
    for (int i : one) unioned.insert(i);
    for (int i : two) unioned.insert(i);
    return unioned;
}

unordered_set<int> calc_inters(const vector<int> &one, const vector<int> &two) {

    unordered_set<int> inters, set2;
    inters.reserve(max(one.size(), two.size()));
    set2.reserve(two.size());

    for (int i : two) set2.insert(i);

    for (int i : one) 
        if (set2.find(i) != set2.end()) 
            inters.insert(i);

    return inters;
}

long long factorial(int n) {
    long long prod = 1;
    for (int i = 2; i <= n; i++) {
        prod *= i;
    }
    return prod;
}

int combination(int n, int chose) {
    //nCr = n! / r! (n - r)!
    assert(n >= chose);
    return factorial(n) / (factorial(chose) * factorial(n - chose));
}

vector<pair<pair<int, int>, double>> calc_doc_sim(const vector<pair<int, vector<int>>> &doc_data) {

    vector<pair<pair<int, int>, double>> pair_wise_similiarity;
    pair_wise_similiarity.reserve(combination(doc_data.size(), 2));

    double similiarity = 0;
    for (int i = 0; i < doc_data.size(); i++) {
        for (int j = i + 1; j < doc_data.size(); j++) {
            double union_size = calc_union(doc_data.at(i).second, doc_data.at(j).second).size();
            double inters_size = calc_inters(doc_data.at(i).second, doc_data.at(j).second).size();

            if (union_size != 0)
                similiarity = inters_size / union_size;
            else similiarity = 0;

            pair_wise_similiarity.push_back({ { doc_data.at(i).first, doc_data.at(j).first }, similiarity });
        }
    }

    return pair_wise_similiarity;
}

int main()
{
    vector<pair<int,vector<int>>> document_data = {
        { 13, {14, 15, 100, 9, 3} },
        { 16, {32, 1, 9, 3, 5} },
        { 19, {15, 29, 2, 6, 8, 7}},
        { 24, {7, 10}}
    };

    vector<pair<pair<int, int>, double>> doc_sim = calc_doc_sim(document_data);
    for (auto i : doc_sim) {
        if (i.second != 0)
            cout << i.first.first << ", " << i.first.second << ": " << i.second << endl;
    }

}
