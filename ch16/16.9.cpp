#include <iostream>
using namespace std;
//make a function that can add,sub,mult and div with only using add

//here we will flip positive numbers into negative numbers to make subtraction possible under addition rules
int negative(int a){
  int neg=0;
  int newSign= a<0? 1:-1;
  while(a!=0){
    neg+= newSign;
    a+= newSign;
  }
  return neg;
}

int subtract(int a,int b){
  return a + negative(b);
}

int multi(int a, int b){
  int multi=0;
  for(int i=0; i<a;i++){
    multi+=b;
  }
  return multi;
}
int divi(int a, int b){
  if (b==0){
    cout<<"sorry cant do that!"<<endl;
    return 0;
  }
  int absa=abs(a);
  int absb=abs(b);

  int product =0;
  int x=0;
  while(product+absb <= absa){
    product+= absb;
    x++;
  }
  if((a<0 && b<0) || (a>0 && b>0)){
    return x;
  } else{
    return negative(x);
  }
}
int main() {
  int num1;
  int num2;
cout<<"give me two numbers to add, divide, subtract and multiply"<<endl;
 cin>>num1;
  cout<<"please give me a second number"<<endl;
  cin>>num2;

  cout<<"if we add those numbers we get: "<<num1+num2<<endl;
  cout<<"if we subtract those numbers we get: "<<subtract(num1,num2)<<endl;
   cout<<"if we multiply those numbers we get: "<<multi(num1,num2)<<endl;
  cout<<"if we divide those numbers we get: "<<divi(num1,num2)<<endl;
}
