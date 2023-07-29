#include <iostream>
/*
how do virtual functions work in c++?

a virtual function works differntly than other functions. it can be called within a base class, and be overwritten by a derived class as well. this also means that virtual functions can not be static due to this relationship.
However, it does make it easy to give it a freidn fucntion of a different class.
a virtual function can be a virtual destructor, but it cant be a constructor.
*/
int main() {
  std::cout << "Hello World!\n";
}
