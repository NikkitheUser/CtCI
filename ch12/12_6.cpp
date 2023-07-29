#include <iostream>
/*
what does Volatile mean in C?

the phrase volatile informs us that the value of a variable can be changed from the outside, without any changes done to the code.
How can this be done? it could be alterted through the operating system. since this value could change, the compiler will have to reload  the origial value through its memory
*/
int main() {
  std::cout << "Hello World!\n";
}
