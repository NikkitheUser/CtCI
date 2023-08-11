#include <iostream>
using namespace std;
int numberOf2s(int n){
  int count=0;
  while(n>0){
    if(n%10==2){
      count++;
    }
    n=n/10;
  }
  return count;
}

int numberOf2Range(int n){
  int count=0;
  for(int i=2;i<=n;i++){
    count+=numberOf2s(i);
  }
  return count;
}


int main() {
cout<<numberOf2Range(25)<<endl;
}
