#include <iostream>
#include <stack>
using namespace std;
//we are gonna make a sorting stack that goes from least to greatest
//NOT FINSIHED
void findBig(stack <int> start, stack <int> end){
  int big=0;
  stack<int> temp; //we hold anything in this stack temporary
  for(int i=0;i<start.size();i++){
    if (big<start.top()){
      big=start.top();
      temp.push(start.top());
      start.pop();
    }
    else{
      temp.push(start.top());
      start.pop();
    }
  }
}
int main() {
  cout << "we have a stack of 4";
  stack <int> starter;//the starting stack
  
  stack <int> ender;//the end result stack
  starter.push(34);
  starter.push(22);
  starter.push(89);
  starter.push(23);

for(int i=0; i<4;i++){
  cout<<starter.top()<<" ";
  
}
  findBig(starter, ender);
  
}
