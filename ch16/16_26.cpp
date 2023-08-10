#include <iostream>
using namespace std;
#include <array>
#include <vector>

//calculator
//we are gonna have to introduce pemdas 
//parenthese, exponent, multiplication, division, addition and subtraction
//we cant just simply to a left to right scenario (dang it)
class Term{
  public:
  enum Operator{ADD, SUBTRACT, MULTIPLY, DIVIDE, BLANK};
Term(double v, Operator op){
  value=v;
  operator =op;
}
double getNumber(){
  return value;
}
Operator getOperator(){
  return operator;
}
void setnumber(double v){
  value =v;
}

private:
double value;
Operator operator = Operator.BLANK
};

double compute(string sequence){
  ArrayList<Term> terms= Term.parseTermSequence(sequence);
  if(terms==null) return Integer.MIN_VALUE;

  double result =0;
  Term processing =null;
  for(int i=0;i<terms.size();i++){
    Term current = terms.get(i);
    Term next=i+1<terms.size() ? terms.get(i+1):null;

    processing =collapseTerm(processing, current);
    if(next==null || next.getOperator() == Operator.ADD || next.getOperator() == Operator.SUBTRACT){
      result=applyOp(result, processing.getOperator(), processing.getNumber());
      processing=null;
    }
  }
  return results;
}

Term collapseTerm(Term primary, Term secondary){
  if(primary ==null)return secondary;
  if(secondary==null)return primary;

  double value=applyOp(primary.getNumber(), secondary.getOperator(),secondary.getNumber());
  primary.setNumber(value);
  return primary;
}

double applyOp(double left, Operator op, double right){
  if(op==OPerator.ADD)return left+right;
  else if(op==Operator.SUBTRACT) return left - right;
  else if(op==Operator.MULTIPLY)return left*right;
  else if(op==Operator.DIVIDE)return left/right;
  else return right;
}

int main() {
cout<<"give me an equation please"<<endl;
  string equation;
  cin>>equation;
  cout<<compute(equation);
}
