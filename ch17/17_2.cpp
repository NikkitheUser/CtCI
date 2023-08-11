#include <iostream>
using namespace std;
#include <random>
#include <array>
//lets make a "perfect" 52 card shuffle
//we can use an array

int shuffleArrayRecursively(int cards[], int i){
  if(i==0){
    return cards[];
  }
  shuffleArrayRecursively(cards,i-1);
  random rand=new random();
  int k = rand.nextInt(i+1);

  int temp =cards[k];
  cards[k]=cards[i];
  cards[i]=temp;
  return cards[];
}
void shuffleArrayIterative(int cards[]){
  random rand= new random();
  for(int i=0;i<cards.length; i++){
    int k= rand.nextInt(i+1);
    int temp=cards[k];
    cards[k]=cards[i];
    cards[i]=temp;
  }
}
int main() {
 srand(time(nullptr));
    array<int, 52> cards;
    for (int i = 0; i < cards.size(); i++) {
        cards[i] = i;
    }
shuffleArrayRecursively(cards[],15);
    for (auto i : cards) {
        cout << i << " ";
    }
    cout << endl;
}
