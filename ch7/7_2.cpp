#include <iostream>
//call center
using namespace std;
class Employee {
public:
string role;
string name;
bool avail;
Employee (string role, string name, bool avail){
  role = " ";
      name = "";
      avail = true;
}
};
bool getAvail(){
  
}
void dispatchCall(){
for(int i=0; i<Employee.respondent;i++){
  if(){//if there is an avaliable responder, cout<<"responder:name will help"
cout<<" will help you now"<<endl;
    avail=false;
 break;
  }
  else{
    continue;
  }
}
  cout<<" no one is available at this time"<<endl;
}
int main() {
  Employee employee1 ("respondent","sarah",true);
Employee employee2 ("manager","lola",true);
  Employee employee3 ("director","tom",true);
  cout << "lets get you some help!"<<endl;

  dispatchCall();
}
