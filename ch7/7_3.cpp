#include <iostream>
//jukebox
using namespace std;
class jukeBox{
public:
string genre;//rock,pop,country
string song;//the name of the song
string band;//also singer
jukeBox(string g, string s, string b){
 genre=g;
  song=s;
  band=b;
}

};
int main() {
  jukeBox song1("punk","soup is good food","Dead Kennedys");
  jukeBox song2("country","Jolene","Dolly");
  jukeBox song3("pop","running up that hill","katie hill(forgot the name)");
 cout << "what would you like to listen to?";
  
}
