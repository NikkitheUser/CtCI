#include <iostream>
using namespace std;
int main() {
  cout << "let us explain what ((n & (n-1)) ==0) does"<<endl;

  cout<<" in the context of bitwise functions, we can use this function"<<endl<<" the function is supposed to figure out if 'n' is either 0 or the exact power of 2"<<endl;

  cout<<" It returns 0 if n is a power of 2 (NB: only works for n > 0). So you can test for a power of 2 like this:"<<endl;

  cout<<endl<<"bool isPowerOfTwo(int n){"<<endl<<" return (n > 0) && ((n & (n - 1)) == 0);}"<<endl;
}
