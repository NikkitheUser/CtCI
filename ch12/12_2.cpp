#include <iostream>
using namespace std;

void reverse(char *str){
  char* end =str;
  char tmp;
  if(str){
    while(*end){
      ++end;
    }
    --end;
    while(str<end){
      tmp=*str;
      *str++=*end;
      *end--=tmp;
    }
  }
}
int main() {
 cout<<"the word of the day is 'pain'"<<endl;
char pain[]="pain";
 reverse(pain);
  cout<<pain<<endl;
}
