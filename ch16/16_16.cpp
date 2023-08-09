#include <iostream>
using namespace std;
#include <vector>;
pair<int, int> sub_sort(vector<int> &nums) {

    pair<int, int> n_m = { make_pair(0, nums.size() - 1) };
    if (nums.size() < 2) {
        cout << "Is sorted" << endl;
        return n_m;
    }

    bool notstop = true;
    for (int i = 0; i < nums.size() && notstop; i++) {
        for (int j = i+1; j < nums.size() && notstop; j++) {
            //cout << nums.at(i) << "<" << nums.at(j) << endl;
            if (nums.at(i) >= nums.at(j)) {
                n_m.first = i;
                notstop = false;
            }
        }
    }

    notstop = true;
    for (int i = nums.size() - 1; i >=0 && notstop; i--) {
        for (int j = i - 1; j >= 0 && notstop; j--) {
            //cout << nums.at(i) << "<" << nums.at(j) << endl;
            if (nums.at(i) <= nums.at(j)) {
                n_m.second = i;
                notstop = false;
            }
        }
    }

    return n_m;
}

int main()
{
    vector<int> nums = { 1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19 };
    cout << sub_sort(nums).first << " ";
    cout << sub_sort(nums).second << endl;

    nums = { 1,2,3,4,5 };
    cout << sub_sort(nums).first << " ";
    cout << sub_sort(nums).second << endl;
}
