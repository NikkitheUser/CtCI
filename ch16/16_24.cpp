#include <iostream>
using namespace std;
#include <vector>
vector<pair<int, int>> pairs_with_sum(vector<int> &nums, int sum) {
    vector<pair<int, int>> pairs;
    if (nums.size() < 1) {
        pairs.push_back(make_pair(INT_MAX, INT_MAX));
        return pairs;
    }

    sort(nums.begin(), nums.end());    

    // algorithm
    for (int i = 0; i < nums.size() - 1; i++) {
        for (int j = i+1; j < nums.size() - 1; j++) {
            int num1 = nums.at(i);
            int num2 = nums.at(j);
            if (num1 == num2) break;
            if (num1 + num2 == sum) {
                pairs.push_back(make_pair(num1, num2));
                break;
            }
            else if (num1 + num2 > sum) break;
            else if (num1 > sum) return pairs;
        }
    }
    return pairs;
}

int main()
{
    // 1,1,2,2,3,3,4,5,6,10
    vector<int> nums = {1,2,3,4,1,2,10,3,5,6};
    vector<pair<int, int>> pairs = pairs_with_sum(nums, 5);
    for (auto i : pairs) {
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;


}
