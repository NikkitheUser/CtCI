#include <iostream>
#include <algorithm>    // binary_search, sort
#include <vector>       // vector
using namespace std;

bool myfunction (int i,int j) {
  return (i<j); }

int main () {
  int myints[] = {1,2,3,4,5,4,3,2,1};
  vector<int> v(myints,myints+9);                         

  sort (v.begin(), v.end());

  cout << "looking for a 3... ";
  if (binary_search (v.begin(), v.end(), 3)){
    cout << "found!\n"; }
  else{ 
    cout << "not found.\n";
    
  
}
 
  sort (v.begin(), v.end(), myfunction);

  cout << "looking for a 6... ";
  if (binary_search (v.begin(), v.end(), 6, myfunction)){
    cout << "found!\n";
  }
    else{
    
     cout << "not found.\n";}

}
 
