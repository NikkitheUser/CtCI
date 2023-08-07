#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
#include <algorithm> 
#include <numeric>
#include <cstdlib>
pair<int, int> swapSum(vector<int> &A, vector<int> &B) {
    pair<int, int> sol;

    if (A.empty() || B.empty())
        return sol = make_pair(INT_MAX, INT_MAX);

    // find sums
    double sumA = accumulate(A.begin(), A.end(), 0);
    double sumB = accumulate(B.begin(), B.end(), 0);

    cout << sumA << endl;
    cout << sumB << endl;

    //sort
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (auto i : A) cout << i << " ";
    cout << endl;
    for (auto i : B) cout << i << " ";
    cout << endl;

    double formulaA = (sumA - sumB) / 2;
    double formulaB = -1 * formulaA;
    // since we are operating with integers, a non-integer
    // formula implies it is not possible
    if (int(formulaA) != int(formulaA)) 
        return sol = make_pair(INT_MAX, INT_MAX);

    for (int iterA = 0; iterA < A.size(); iterA++) {
        for (int iterB = 0; iterB < B.size(); iterB++) {
            int elementA = A.at(iterA);
            int elementB = B.at(iterB);

            // if we exceed the minimum for what we are looking for
            if (elementB > formulaB + elementA) {
                break;
            }

            else if (formulaA + elementB == elementA) {
                return sol = make_pair(iterA, iterB);
            }
        }
    }
    return sol = make_pair(INT_MAX, INT_MAX);
}

int main() {
    vector<int> one = {4,1,2,1,1,2};
    vector<int> two = { 3,3,3,6 };
    pair<int, int> sol = swapSum(one, two);
    cout << sol.first << " ";
    cout << sol.second << endl;
    pause();

    one = { 1,3,4,5,2,12,3,2,1,2,3 };
    two = { 1,3,4,5,2,2,7,1,2,3 };
    sol = swapSum(one, two);
    cout << sol.first << " ";
    cout << sol.second << endl;
    pause();

    one = { 2,3,2,5,2,12,23,2,6,1,1 };
    two = { 1,3,4,5,2,3,7,1,2,30 };
    sol = swapSum(one, two);
    cout << sol.first << " ";
    cout << sol.second << endl;
    pause();

    one = { 4,3,2,5,2,12,2,2,6,1,1 };
    two = { 1,3,4,5,6,3,7,8,5,2 };
    sol = swapSum(one, two);
    cout << sol.first << " ";
    cout << sol.second << endl;
    pause();
}
