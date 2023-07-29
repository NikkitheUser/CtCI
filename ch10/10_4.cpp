#include <iostream>
#include <bit>
using namespace std;
int search(int list[], int value){
  int index=1;
  while(list[index] != -1 && list[index]<value){
    index *=2;
  }
  return binarySearch(list[],value,index/2,index);
}
int binarySearch(int list[],int value, int low, int high){
  int mid;
  while(low<= high){
    mid = (low +high)/2;
    int middle=list[mid];
  if(middle>value||middle==1){
    high=mid-1;
  }
    else if(middle <value){
    low=mid+1;
    }
    else{
      return mid;
    }
  }
  return -1;
}

int main() {
  cout<<"lets find something without looking up its size!";
  int array[]={2,3,23,2,2,1,4,5,4,};
  int value=23;
  cout<<search(array[],value);
}
