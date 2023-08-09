#include <iostream>
#include <vector>
using namespace std;
int max_cont_sum(vector<int> &nums) {
   if (nums.empty()) return 0;
    int sum, cur_max_potential, actual_max;
    sum = 0;
    cur_max_potential = actual_max = nums.at(0);

    for (auto &i : nums) {
        sum += i;
        if(sum < 0){
        sum = 0;
        }
        else{
            cur_max_potential = sum;
        }
        if(cur_max_potential > actual_max){
        actual_max = cur_max_potential;
        }
    }

return actual_max;
}


int main() {
    vector<int> nums = { 2, -8, 3, -2, 4, -10 };
    cout << max_cont_sum({ nums }) << endl;

    nums = { 2 ,3, -8, -1, 2, 4, -2, 3 };
    cout << max_cont_sum({ nums }) << endl;

    nums = { -10,-100,3,4,-6,-5,10 };
    cout << max_cont_sum({ nums }) << endl;

    nums = { -10,-100,3,4,-6,-5 };
    cout << max_cont_sum({ nums }) << endl;

    nums = { 1,-100,3,4,-6,-1, 2 };
    cout << max_cont_sum({ nums }) << endl;
}
