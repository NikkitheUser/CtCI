#include <iostream>
#include <math.h>
#include <string>
using namespace std;
class Result{
public: 
int hits =0;
int almostHits=0;
void toString(){
  cout<< "("<< hits<<","<<almostHits<<")"<<endl;
}
  };
int code(char code){
  switch(code){
    case 'B':
    return 0;
    case 'G':
    return 1;
    case 'R':
    return 2;
    case 'Y':
    return 3;
    default:
    return -1;
  }
}
int MAX_Colors=4;

Result estimate(string guess, string solution){
  if(guess.length() != solution.length()){
    cout<<"null"<<endl;
  }
  Result res = new Result();
  int  frequencies[] = new int MAX_Colors;
  //now he hits will be checked and we can build the table for the frequency
  for(int i=0; i<guess.length();i++){
    if(guess.charAt(i) == solution.charAt(i)){
      res.hits++;
    }else{
      int coder =code(solution.charAt(i));
      frequencies[code]++;
    }
  }
  for(int i=0; i<guess.length(); i++){
    int code =code(guess.charAt(i));
    if(code>=0 && frequencies[code]>0&& guess.charAt(i) != solution.charAt(i)){
      res.almostHits++;
      frequencies[code]--;
    }
  }
  return res;
    }
int main() {
  string solution="YRGB";
  string guess;
cout<<"guess the code"<<endl;
  cin>>guess;

 estimate(guess, solution);
}
