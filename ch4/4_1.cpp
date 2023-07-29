#include <iostream>
#include <iomanip>
using namespace std;
struct node{
    int data;
    node *right, *left;
};

void createBst(node* &root, int arr[], int start, int end){
    if(start>end)
        return;
    if(root==NULL){
        node *ptr = new node;
        int ind = start + (end-start)/2;
        ptr->data = arr[ind];
        ptr->left = NULL;
        ptr->right = NULL;
        root = ptr;
        createBst(root->left, arr, start, ind-1);
        createBst(root->right, arr, ind+1, end);
    }
}

void findRoute(node* p,int indent=0)
{
    if(p != NULL) {
        if(p->right) {
           cout<<p->data<<" is on the right"<<endl;
        }
        if (indent) {
            cout << "nothing here"<<endl;
        }
        if(p->left) {
          
            cout <<p->data<<" is on the left"<<endl;
        }
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    node* root;
    root = NULL;
    createBst(root, arr, 0, 8);
    findRoute(root);
}
