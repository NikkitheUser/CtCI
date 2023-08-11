#include <iostream>
#include <bitset>
#include <stdint.h>
using namespace std;

int findInt(ArrayList<BitInteger> array){
  return findInt(array,0);
}

int findInt(ArrayList<BitInteger> input, int column){
  if(column<0){
    return 0;
  }
  ArrayList<BitInteger> oneBits=new ArrayList<BitInteger>(input.size()/2);
  ArrayList<BitInteger> zeroBits=new ArrayList<BitInteger>(input.size()/2);

  for(BitInteger t: input){
    if(t.fetch(column)==0){
      zeroBits.add(t);
    }
    else{
      oneBits.add(t);
    }
  }
  if(zeroBits.size()<=oneBits.size()){
    int v= findInt(zeroBits, column -1);
    return(v<<1)|0;
  }
  else{
    int v= findInt(oneBits, column -1);
    return (v<<1)|1;
  }
}
int main() {
  int array[]={1,2,3,5,6,7};
 cout <<findInt(array);
}
