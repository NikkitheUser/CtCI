#include <iostream>
using namespace std;
#include <vector> 
//majority element 
//baiscally find out what number pops up the most
int majorityElement(vector<int>& nums) {
    if (nums.empty()) return -1;//if we see theres nothing in the vector

    int maj = nums[0];//this is where we keep the current majority number
    int count = 1;

    for (int i = 1; i < nums.size(); i++) {
        if (!count) {
            maj = nums[i];
            count++;
        }
        else if (nums[i] == maj) count++;
        else count--;

    }
    return maj;
}

int main()
{
    vector<int> t1 = { 1, 2, 5, 9, 5, 9, 5, 5, 5 };
    cout << majorityElement(t1);
}
