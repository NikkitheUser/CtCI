#include <iostream>
/*
so we can do this in a brute force way
we can check each row if theres 3 in a row
  if its x... keep going, another x keep going... a o, skip to next row

  then we do columns
  then we check the diagonals (corners and mid)
*/
using namespace std;

string rowTest(string array[3]){
for(int i=0;i<3;i++){
  
  if(array[0]=="o"){
    if(array[1]=="o"){
      if(array[2]=="o"){
        return "tic tac toe! o wins!";
      }
    }
  }
    if(array[0]=="x"){
    if(array[1]=="x"){
      if(array[2]=="x"){
        return "tic tac toe! x wins!";
      }
    }
  }
  else{
    return "uh oh";
  }
}
  return "no";
}

string colTest(string array1[3],string array2[3],string array3[3]){
  //lets start with col one 
  for(int i=0;i<3;i++){
    if(array1[i]==array2[i]&&array1[i]==array3[i]){
      cout<< "horray the winner is "<< array1[i]<<" with column "<< i<<endl;
      return "good job";
    }
    else{
      continue;
    }
  }
  return "no columns here";
}


string diagTest(string array1[3],string array2[3],string array3[3]){
  if(array1[0]==array2[1]&&array1[0]==array3[2]){
     cout<< "horray the winner is "<< array1[0]<<endl;
      return "good job";
  }
  else if(array1[3]==array2[1]&&array1[3]==array3[0]){
     cout<< "horray the winner is "<< array1[0]<<endl;
      return "good job";
  }
  return "no diags here";
}
int main() {
  string row1[3]={"x","o","x"};
  string row2[3]={"x","x","o"};
  string row3[3]={"x","x","x"};
  cout << "lets find the tac toe!\n";
for(int i=0;i<3;i++){
  cout<<row1[i]<<" "; 
}
  cout<<endl;
  for(int i=0;i<3;i++){
  cout<<row2[i]<<" "; 
}
  cout<<endl;
  for(int i=0;i<3;i++){
  cout<<row3[i]<<" "; 
}
  cout<<endl;

  cout<<"lets find a row"<<endl;
  cout<<rowTest(row1)<<endl;
  cout<<rowTest(row2)<<endl;
  cout<<rowTest(row3)<<endl;

  cout<<"lets find a colm"<<endl;
  cout<<colTest(row1, row2, row3);
  cout<<diagTest(row1, row2, row3);
}
