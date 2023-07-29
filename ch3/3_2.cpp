#include <iostream>
#include <stack>
using namespace std;
//develop a way to find the min in a stack
int main() {
  cout << "lets find the smallest number in a stack!";
stack <int> finder;//we look for the value here
  stack<int> looked;//these are our looked through values;
  int min=190;// this is our min int
  finder.push(23);
  finder.push(55);
  finder.push(19);
  finder.push(29);
  cout<<"we have 4 values in our stack"<<endl;

  for(int i=0;i<finder.size();i++){
    if(finder.top()<min){
      min=finder.top();
    }
    looked.push(finder.top());
    finder.pop();
  }
  cout<<min;
}
