#include <iostream>
using namespace std;
//sparse search
int search(string list[12], string value){
  int index=1;
  while(list[index] != -1 && list[index]<value){
    index *=2;
  }
  return binarySearch(list[12],value,index/2,index);
}
int binarySearch(string list[12],string value, int low, int high){
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
  string array[12]={"at","","","","ball","","","car","","","dad",""};
  cout << "we have an array, lets find what index 'ball' is"<<endl;
  string value="ball";
  cout<<search(array[12],value)<<endl;
}
