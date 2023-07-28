#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
  //is the two strings a permutation
  string word1;
  string word2;
  cout<< "give first word "<<endl;
  cin>> word1;
  cout<<"give me second word "<<endl;
  cin>>word2;
  if(word1.length()!=word2.length()){
    cout<<"cant be a permutation! the lengths are not the same"<<endl;
    return 0;
  }
string list1 [word1.length()];
  string list2 [word2.length()];
for(int i=0; i<word2.length();i++){
 list1[i]=word1[i];
   list2[i]=word2[i];
  }
  int N = sizeof(list1)/sizeof(list1[0]);
sort(list1,list1+N);
  sort(list2,list2+N);

for(int i=0; i<word2.length();i++){
 if(list1[i]!=list2[i]){
   cout<<"not a permutation!"<<endl;
   return 0;
 }
  }
  cout<<word1<<" is a permutation of "<<word2<<endl;
}
