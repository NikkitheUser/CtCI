#include <iostream>
#include <stack>
using namespace std;


class Queue{
private:
    stack<int> stack1, stack2;
public:
    void EnQueue(int data){//enter the queue
        stack1.push(data);
    }
    int DeQueue(){//leave the queue
        if(stack1.empty() && stack2.empty()){//in case its empty
            printf("Queue is empty!");
            getchar();
            exit(0);
        }
        if(stack2.empty()){
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        }
        int temp = stack2.top();
        stack2.pop();
        return temp;
    }
    int size(){
        return stack1.size() + stack2.size();
    }

};

int main(){
    Queue q;
    for(int i=0; i<10; i++){
        cout<<"EnQueue :"<<i<<'\n';
        q.EnQueue(i);
    }
    cout<<"DeQueue :"<<q.DeQueue()<<'\n';
    cout<<"DeQueue :"<<q.DeQueue()<<'\n';
    for(int i=10; i<20; i++){
        cout<<"EnQueue :"<<i<<'\n';
        q.EnQueue(i);
    }
    cout<<"DeQueue :"<<q.DeQueue()<<'\n';
    cout<<"DeQueue :"<<q.DeQueue()<<'\n';

}
