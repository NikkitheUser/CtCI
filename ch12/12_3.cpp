#include <iostream>
/*
hash table vs STL Map

how is a hash table implemented?
a hash table is implemtned with arrays of linked lists.  each node in the linked lis holds two pieces of data: a value and the key

if the inputs too small, what do we do for the hash table?
then we use a STL map or we can implement a binary tree instead.

the difference betweeen stl and hash table?
as mentioned before, hashtables stores values by calling its key. they are not in a sorted order

a STL map however puts the vaules and its keyes into a binary search tree.
*/
int main() {
  std::cout << "Hello World!\n";
}
