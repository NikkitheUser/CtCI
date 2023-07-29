#include <iostream>
#include <stack>
using namespace std;
//how to add an array to a stack

int main() {
  
int myArray[4]={1,5,3,2};
  stack<int> stack;
    for(int i=0; i<4;i++){
      stack.push(myArray[i]);
    }
  for(int i=0; i<4;i++){
    cout<<stack.top()<<endl;
      stack.pop();
    }
}
