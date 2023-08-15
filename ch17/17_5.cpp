#include <iostream>
using namespace std;
//Letters and Numbers
//Given an array filled with letters and numbers, find the longest subarray with an equal number of letters and numbers


char findLongestSubarray(char array[]){
int deltas[]= computeDeltaArray(array);//we can compte the 'deltas' between count of numbers and letters
  int match[]= findLongestMatch(deltas);//this holds the pair of matching values

  return extract(array, match[0]+1,match[1]); //this returns the subarrays 
}
int computeDeltaArray(char array[]){
  int delta=0;
  for(int i=0;i<array.length(); i++){
    if(Character.isLetter(array[i])){
      delta++;
    }else if(Character.isDigit(array[i])){
      delta--;
    }
    deltas[i]=delta;
  }
  return deltas;
}

int findLongestMatch(int deltas[]){
  HashMap<Integer, Integer> map= new HashMap<Integer, Integer>();
  map.put(0,-1);
  int max[] =new int[2];
  for(int i=0;i<deltas.length;i++){
    if(!map.containsKey(deltas[i])){
      map.put(deltas[i],i);
    }else{
      int match=map.get(deltas[i]);
      int distance =i-match;
      int longest=max[1] -max[0];
      if(distance>longest){
        max[1]=i;
        max[0]=match;
      }
    }
  }
  return max;
}
int main() {
  std::cout << "Hello World!\n";
}
