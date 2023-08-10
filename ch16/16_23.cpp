#include <iostream>
using namespace std;
#include<cstdlib>
//rand7 from rand5: make a method rand7() given rand5(). that is, given a method that generates a random integer between 0 and 4(inclusive), write a method that generates a random integer between 0 & 6 (inclusive)
int main() {
 int choice=0; 
  while(choice>-1){
    cout<<"do you want a num between 0-4 or 0-6? "<<endl<<"'1'for 0-4, '2' for 0-6, '3' for nothing "<<endl;
cin>>choice;
    if(choice==1){
     int random = rand() % 5;
      cout<<random<<endl;
    }
    else if(choice==2){
      int random = rand() % 7;
       cout<<random<<endl;
    }
    else if(choice==3){
      return 0;
    }
    else{
      continue;
    }
  }
}
