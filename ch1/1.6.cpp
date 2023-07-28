#include <iostream>
using namespace std;


void compressed(string str){

  string compress[str.length()];
  int count=0;
  for(int i=0;i<str.length();i++){
    if(str[i]==str[i+1]){
      count++;
    }
    else if(str[i]!=str[i+1]){
        compress[i]=str[i];
      string stri = to_string(count);
      compress[i+1]=stri;
      count=0;
    }
  }
  for(int i=0;i<str.length();i++){
 cout<<compress[i]<<endl;
  }
}
int main() {
  string word;
  
cout << "give me a funny word\n";
getline (cin,word);
compressed(word);
}
