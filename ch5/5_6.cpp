#include <iostream>
//write a function to determine the number of bit converts you need for int a needs to become int b

//not exact count, but its counting something 
using namespace std;
int bitSwapRequired(int a, int b){
int count=0;
  int c= a^b;
  while(c!=0){
   c=c&(c-1);
    count++;
  }
  return count;
}

int main() {
  int a= 11101;
  int b= 10101;
  cout << "integer A: "<<a<<endl;
cout<<"integer B: "<<b<<endl;
  cout<<bitSwapRequired(a,b)<<" is how many converts needed for A to be B"<<endl;
}
