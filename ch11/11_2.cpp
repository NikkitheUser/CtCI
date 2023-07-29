#include <iostream>
/* 
random crashes:
what is the application supposed to do? who is running the program that is running into these issues? what is said user doing each time it crashes?

these are very important questions to ask about this application,
but given the information we have

there could be:
a memory leak
maybe a varaible was not properly initilized 
or we could have a problem with a random number genrator that is in the application
*/
int main() {
  std::cout << "Hello World!\n";
}
