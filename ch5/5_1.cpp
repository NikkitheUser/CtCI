#include <iostream>
using namespace std;
#include <cstdint>
#include <bit>

int32_t insertion(int32_t N, int32_t M, int i, int j)
{
    int w = j - i;
    if (w <= 0)
        return N;

    int32_t maskN = (~0 << (j + 1)) | ((1 << i) - 1);
    return (N & maskN) | (M << i);
}
bool getBit(int num, int i){
  return ((num & (1<<i)) !=0);
}
int main()
{
    auto result = insertion(0b10000000000, 0b10011, 2, 6);
  for (int i=0; i<11;i++){
     cout << getBit(result,i);
  }
   
}
