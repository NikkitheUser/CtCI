#include <bits/stdc++.h>
using namespace std;
 
int countTrailingZeroes(int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++) {
        int j = i;
        while (j % 5 == 0) {
            count++;
            j /= 5;
        }
    }
    return count;
}
 
int main()
{
    int n = 100;
    cout << countTrailingZeroes(n) << endl;
    return 0;
}
