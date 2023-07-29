#include <iostream>
/*
sychronized methods

first question:
only if they have the same instaces on objects. if they do, then yes, they can execute at the same time. otherwise they cannot

second question:
yes they can. since method a is sycronized but method b is not. then they can execute with no issue

*/
int main() {
  std::cout << "Hello World!\n";
}
