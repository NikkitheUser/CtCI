#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
/* Function to swap values at two pointers */
void swap(char *x, char *y){
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/* functions takes the String, then the index of the string then the ending index of
the string */
void permute(char *a, int l, int r){
   int i;
   if (l == r){
     printf("%s\n", a);
   }
   else {
       for (i = l; i <= r; i++){
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i)); //backtrack
}}
}
int main(){
    char str[] = "ABCDE";
    int n = strlen(str);
    permute(str, 0, n-1);
      return 0;
}
