#include <iostream>
using namespace std;
//add without plus
//since we are unable to use the addition operator, we will be manipulating bits instead
int add(int a, int b){
  if (b==0) return a;
  int sum=a^b;
  int carry=(a&b)<<1;
  return add(sum,carry);

}
int main() {
  int num1,num2;
  cout<<"give me a number to add"<<endl;
  cin>>num1;
  cout<<"please give me one more number"<<endl;
  cin>>num2;
  cout<<add(num1,num2)<<endl;
}
