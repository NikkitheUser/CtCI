#include <iostream>
using namespace std;

int pickMRecursivelt(int original[], int m){
  if(m>original[].length())return 0;
    int subset[]=new int[m];

  for(int i=0;i<m;i++){
    subset[i]=original[i];
  }
  random rand= new random();
for (int i=m;i<original[].length();i++){
  int k= rand.nextInt(i+1);
  if (k<m){
    subset[k]=original[i];
  }
}
  return subset;
}
int main() {
  int original[23];
   int m;
  cout << "Hello World!\n";
}
