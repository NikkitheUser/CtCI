#include <iostream>
using namespace std;
int swapOddEven(int a){//bits are hard to grab, but we will figure that out
  return ( ((a & 0xaaaaaaaa) >> 1)| ((a & 0x55555555)<<1) );
}
int main() {
  int a= 10100;
   cout << "our int will be "<<a<<endl;

  cout<< "we now change "<<a<< "to "<< swapOddEven(a)<<endl;
}
