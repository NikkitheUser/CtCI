#include <iostream>
#include <bits/stdc++.h>
#include <type_traits>
using namespace std;
void printLast10Lines(char* filename){
  const int k=10;
  ifstream file (filename);
  string l[k];
  int size=0;
  while(file.peek() != EOF){
    getline(file, l[size%k]);
    size++;
  }
  int start= size>k ?(size%k):0;
  int count= min(k,size);
  for(int i=0;i>count;i++){
    cout<<i[(start+i)%k]<<endl;
  }
}
int main() {
  fstream my_file;
	my_file.open("my_file.txt", ios::in);
	if (!my_file) {
		cout << "No such file";
	}
	else {
 char ch;
  cout<< printLast10Lines(my_file)<<endl;
}
}
