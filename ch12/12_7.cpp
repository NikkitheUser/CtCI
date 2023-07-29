#include <iostream>
/*
virtial base class, why doe we declare destructors as virtual

if we do not declare a destructor as virutal, we end up running into issues

for example, (if a=x)->the destructor is called. (if a!=x) the destructor wont be called.
however if the destructor is NOT virtual, we may see the destructor be called, despite a!=x

*/
int main() {
  std::cout << "Hello World!\n";
}
