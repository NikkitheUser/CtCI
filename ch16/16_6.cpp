#include <bits/stdc++.h>
using namespace std;
 
// function to calculate Small
// result between two arrays
int findSmallestDifference(int A[], int B[], int m, int n) {
    int minDiff = INT_MAX; // Initialize with maximum integer value
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int diff = abs(A[i] - B[j]); // Calculate absolute difference
            if (diff < minDiff) {
                minDiff = diff; // Update smallest difference found so far
            }
        }
    }
    return minDiff;
}
 
int main()
{
    int array1[] = {1, 3, 15, 11, 2};
    int array2[] = {23, 127, 235, 19, 8};
 
 
    // Calculate size of Both arrays
    int m = sizeof(array1) / sizeof(array1[0]);
    int n = sizeof(array2) / sizeof(array2[0]);
 
    // Call function to print
    // smallest result
    cout << findSmallestDifference(array1,array2, m, n);
 
    return 0;
}
