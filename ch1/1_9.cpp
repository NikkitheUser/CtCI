//string rotation, give the function two strings, the orginal word and the same that is roated. ie. waterbottle -> aterbottlew
#include<string>
#include<iostream>
using namespace std;

bool isRotation(string str1, string str2){
	str1 = str1+str1;
	size_t pos = str1.find(str2);//size_t is an unsigned integer type large enough to represent the size of any object in C++, including array types. (size as in how much memory it occupies in bytes).
	return pos!=(string::npos);//we use this to find the string in the string
}

int main(void){
  
	string word1,word2;
	cout<<"give me a word"<<endl;
  getline(cin,word1);
	cout<<"give me another one please"<<endl;
  getline(cin,word2);
	if(isRotation(word1,word2))
		cout<<word2<<" is a rotation of "<<word1<<endl; //if bool is true, then the strings are rotations
	else
		cout<<word2<<" is not a rotation of "<<word1<<endl;//if false, the strings are not rotations
	return 0;
}
