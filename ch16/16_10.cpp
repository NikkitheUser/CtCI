#include <iostream>
using namespace std;
class Person{
public:
int birth;
int death;
Person(int birthYear, int deathYear){
  birth =birthYear;
  death =deathYear;
}

int maxAliveYear(Person people[], int min, int max){
  int maxAlive = 0;
  int maxAliveYear= min;
  for (int year = min; year<= max; year++ ){
    int alive=0;
    for(Person person: people){
      if(person.birth <= year && year<= person.death){
        alive++;
      }
    }
    if(alive > maxAlive){
      maxAlive =alive;
      maxAliveYear= year;
    }
  }
  return maxAliveYear;
}
};
int main() {
  int min=3;
  int max=6;
  int person1[]={2000,2012};

  
 cout<<maxAliveYear(person1[],min,max)<<endl;
}
