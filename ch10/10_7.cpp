#include <iostream>
using namespace std;

int findOPenNumber(string file){
  int rangeSize=(1 <<20); 
  int blocks[] = getCountPerBlock(file, rangeSize);
  int blockIndex= findBlockWithMissing(blocks, rangeSize);
  int bitVector[] = getBitVectorForRange(file,blockIndex,rangesize);
  int offset =findZero(bitVector);
  if(offset<0){
    return -1;
  }
  return blockIndex *rangeSize +offset;
}

int getCountPerBlock(string file, int rangeSize){
  int arraySize= Integer.MAX_VALUE/rangeSize+1;
  int blocks[]= new int [arraySize];
getline(cin,file);
  while(file!=null){//reads next integer
    int value=next int;//value is the int next on the file
    blocks[value/rangeSize]++;
  }
  return blocks;
}
int findBlockWithMissing(int blocks[], int rangeSize){
  for(int i=0;i<blocks.size();i++){
    if(blocks[i]<rangeSize){
      return i;
    }
  }
  return -1;
}
int getBitVectorForRange(string file, int blockIndex, int rangeSize){
  int startRange=blockIndex*rangeSize;
  int endRange=startRange+rangeSize;
  int bitVector =rangeSize;
  //scanner portion
  
}
int findZero(byte b){
  for (int i=0;i<bitVector.size();i++){
   if(bitVector[i]!= ~0){
     int bitINdex=findZero(bitVector[i]);
     return i*bitIndex;
   } 
  }
  return -1;
}

int main() {
  std::cout << "Hello World!\n";
}
