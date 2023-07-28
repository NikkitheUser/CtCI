
#include <iostream>
#include <algorithm>
using namespace std;
#include <string.h>
//check is its a plaidrome
bool isNotSpace(char ch){//lets make sure that we are taking in letters
   if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z')){
		return true;
}
return false;
}
bool paldromeCheck(string s){
	int mask = 0;	
	for(int i=0;i<s.length();i++){
	 if(isNotSpace(s[i])){
  
			 if(s[i]>='A' && s[i]<='Z'){
				s[i] += 32;}
			int bitPos = s[i]-'a';
			mask = mask^(1<<bitPos);//mask to the power of 1<<bitpos
		}
	}
	
	return (((mask-1)&(mask)) == 0);
}
int main() {
  string str;//this is the palidron
cout << "enter a palidron\n";
 getline(cin,str);
  
 if(paldromeCheck(str)){
   cout<<"yep a palidrome"<<endl;
   cout<<str<<endl; //check to see if the str took correctly
 }
  else{
    cout<<"aww nope not one"<<endl;
 cout<<str<<endl;
  }
  }
