#include <iostream>
using namespace std;
void sortPeak(int array []){
  array[].sort();
  for(int i=1;i<array[].size();i+=2){
    swap(array[],i-1,i);
  }
}

void swap(int array[], int left, int right){
  int temp =array[left];
  array[left]=array[right];
  array[right]=temp;
}
int main() {
 cout << "Hello World!\n";
}
