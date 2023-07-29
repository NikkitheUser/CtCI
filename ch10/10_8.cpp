#include <iostream>
#include <bitset>
#include <limits.h>
using namespace std;
void checkDups(int array[]){
 bitset<8> find= new bitset<32000>;
  for(int i=0;i<array.size();i++){
    int num=array[i];
    int num1=num -1;
    if(find.get(num1)){
      cout<<(num);
    }
    else{
      find.set(num1);
    }
  }
}

class bitset{

public: 
bitset(int size){
  bitset=new int[(size>>5)+1];
}
bool get(int pos){
  int wordNumber= (pos>>5);
  int bitNUmber=(pos & 0x1F);
  return (bitset[wordNumber] & (1<< bitNUmber)) !=0;
}
void set(int pos){
  int wordNumber=(pos>>5);
  int bitNumber=(pos&0x1F);
  bitset[wordNumber]|=1 <<bitNumber;
}
};
int main() {
cout << "Hello World!\n";
}
