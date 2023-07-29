#include <iostream>
/*
X clearly needs to be an integer. Should we round X up or down?
• If we round X up to 14, then we would go up by 14, then 13, then 12, and so on. The last increment would be 4, and it would happen on floor 99. If Egg 1 broke on any of the prior floors, we know we've balanced the eggs such that the number of drops of Egg 1 and Egg 2 always sum to the same thing: 14. If Egg 1 hasn't broken by floor 99, then we just need one more drop to determine if it will break at floor 100. Either way, the number of drops is no more than 14.
• If we round X down to 13, then we would go up by 13, then 12, then 11, and so on. The last increment will be 1 and it will happen at floor 91 . This is after 13 drops. Floors 92 through 100 have not been covered yet. We can't cover those floors in just one drop (which would be necessary to merely tie the round up case.
Therefore, we should round X up to 14. That is, we go to floor 14, then 27, then 39, .... This takes 14 steps in
the worse case.
*/
int main() {
  std::cout << "Hello World!\n";
}
