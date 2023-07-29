#include <iostream>
int** my2DAlloc(int rows, int cols){
  int** rowptr;
  int i;
  rowptr=(int**) malloc(rows * sizeof(int*));
  for(int i=0; i<rows;i++){
    rowptr[i]=(int*)malloc(cols * sizeof(int));
  }
  return rowptr;
}
int main() {
  std::cout << my2DAlloc( 6, 8);
 
}
