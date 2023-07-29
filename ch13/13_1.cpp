#include <iostream>
/*
Private Constructor:
 if we keep a constructor private we first off would have to access it as if its a private class, and not a public one. 
 class A can use the A constructor, but class B is unable to call the class A constructor. but if A has an inner class, lets call it G, then G can access Constructor A
*/
int main() {
  std::cout << "Hello World!\n";
}
