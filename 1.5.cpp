#include <iostream>
using namespace std;
#include <limits>

#include <vector>

#include <fstream>

string sizeCheck(string str1, string str2){
  if(str1.length()==str2.length()-1||str1.length()==str2.length()+1||str1.length()==str2.length()){
  cout<<"the size looks okay"<<endl;
}
  else{
    cout<<"uh oh! this is more than 2 edits!"<<endl;
    return 0;
  }
  return "yay";
}

int editTwo(string str1, string str2){
  int count=0; //count the edits, if it hits 2 we STOP
  int lengths=max(str1.length(),str2.length());
  for(int i=0; i<lengths;i++){
if(str1[i]==str2[i]){
continue;  
}
    else{
      count++;
    }}
    if(count<2){
      return 1;
    }
    return 2;
  }


int main() {
  string word1;
  string word2;
  cout << "give me a word"<<endl;
  cin>>word1;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout<<"handover the other word"<<endl;
  getline(cin,word2);
  sizeCheck(word1,word2);

  if(editTwo(word1,word2)==1){
    cout<<"yes that works!"<<endl;
  }
  else{
    cout<<"uh oh! you need more than one edit!"<<endl;
    return 0;
  }
}
