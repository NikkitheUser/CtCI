#include <iostream>
using namespace std;
/*
mistake:
find the isssue with
unsigned int i;
for(i= 100; i>=0;--1)
printf ("%d/n",1);

  
  this will loop forever
  unsigned will always be >=0, meaning the loop will never close
  */
int main() {
  std::cout << "Hello World!\n";
}
