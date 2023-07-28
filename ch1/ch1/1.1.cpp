 #include <iostream>
#include <limits.h>

using namespace std;
bool isUniqueChars(string str) {
    if (str.length() >128) return false;
    bool char_set[] =new bool[128];
for (int i=0; i<str.length(); i++) {
      int val = str.at(i);
      if(char_set[val]){//found the char in string
        return false;
      }
      char_set[val]=true;
}
    return true;
  }
int main() {
  /* this is nicoles first try
 //make a function that checks if a string has ALL unique text
string word;//this is our string
  
  cout<<"enter a string ";//so we know we can enter our desired string
  cin>>word;
  cout<<"you have chosen "<<word<<endl; //we check to see if it takes the string

  int count= word.length();
  cout<<"the word "<<word<< " has a length of "<<count<<endl;//we see how long the word is

  for(int i=0; i<count; i++){//we check each letter side by side with the rest of its self
    for(int j=i+1; j<count;j++){
 if (word[i]==word[j]){//if a letter is not unique, it tells us and returns 0, ending the function
cout<<"not unique"<<endl;
  return 0;
 }
 else if(word[i]!=word[j] )//if a word is not the same, we call it out
   {
   cout<<word[i]<<" is not "<< word[j]<<endl;
   }
 }}
      cout<<" it is all unique"<<endl;//this gets called if every word is unique 
  */

  // this is the book version
 string str;
  cout<<"give me a string"<<endl;
  cin>> str;
  cout<<isUniqueChars(str);
}
