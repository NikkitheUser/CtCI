#include <iostream>
using namespace std;
//random set
// Write a method to randomly generate a set of m integers from an array of size n. 
//Each element must have equal probability of being chosen.
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

}
