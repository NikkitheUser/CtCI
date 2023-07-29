#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool anagram_check(string s1,string s2){ // checks if two strings are anagrams of each other

    if (s1.size() != s2.size()) return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

void group_anagrams(string arr[], int size){
    int cur_index = 0; 
    while (cur_index < size) {
        // in each loop we start with the element at cur_index and move all the anagrams to the right of it
        for (int i = cur_index + 1; i < size; i++) {
            if (anagram_check(arr[cur_index], arr[i])) {
                cur_index++;
                string temp = arr[i];
                arr[i] = arr[cur_index];
                arr[cur_index] = temp;
            }
        }
        cur_index++;
    }

}


int main(){
    // As an example, we can use:
    string s[6] = {"abcd", "asleep", "notananagram", "cdba", "please", "dcba"};
    // print array before
    cout << "Array before: ";
    for (int i = 0; i < 6; i++) {
        cout << s[i] << " ";
    }

    group_anagrams(s, 6);

    // print array after
    cout << "Array after: "<<endl;
    for (int i = 0; i < 6; i++) {
      cout << s[i] << " ";
    }

    return 0;
}
