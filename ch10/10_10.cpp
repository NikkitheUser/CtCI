#include <iostream>
#include<type_traits>
using namespace std;

class RankNode{
public:
int left_Size=0;
RankNode left, right;
int data=0;
RankNode(int d){
  data =d;
}
void insert(int d){
  if(d<=data){
    if(left!=null){
      left.insert(d);
    }
    else{
      right = new RankNode;
    }
}
  int getRank(int d){
    if(d==data){
      return left_size;
    }
    else if(d<data){
      if(left==null){
        return -1;
      }
      else{
        return left_size+1+right_rank;
      }
    }
    }
  }
};

RankNode root= null;
void track(int number){
  if(root==null){
    root=new RankNode(number);
  }
  else{
    root.insert(number);
  }
}

int getRankOfNumber(int number){
  return root.getRank(number);
}


int main() {
  cout << "Hello World!\n";
}
