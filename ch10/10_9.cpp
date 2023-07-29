#include <iostream>
using namespace std;
bool findValue(int matrix[4][2], int value){
  int row=0;
  int col=matrix[0].length() -1;
  while(row <matrix.length()&&col>=0){
    if(matrix[row][col]==value){
    return true;
    }
  else if(matrix[row][col]>value){
    col--;
  }
  else{
    row++;
  }
  }
return false;
}
int main() {
  cout<<"array time"<<endl;
  int arr[4][2] = {
{1234, 56},
{1212, 33},
{1434, 80},
{1312, 78}
} ;
  cout<<findValue(arr, 33);
}
