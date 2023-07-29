#include<iostream>
#include<string>
#include<vector>
#include<random>
//object oriented design make a deck of cards
using namespace std;
class Card {
public:
    Card() {}
    ~Card() {}
    unsigned value=0;
    string suit="";
    string name="";
    string rank="";
};

class Deck {
public:
    Deck() {}
    void makeDeck();
    vector<Card> cards;
    vector<Card> suit;
    Card card;
};
int main() {
  //explain blackjack

  //FIRST LEARN HOW BLACKJACK WORKS
}
