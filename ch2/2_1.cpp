#include <iostream>

using namespace std;

struct node {
	int data;
	struct node * next;
};

node *head = NULL;

// returning the pointer to the element 
// whose data is less than or equal to input data
struct node *searchNode(int n) {
	if(head == NULL) return head;
	node *cur = head;
	node *prev = head;
	while(cur) {
		if(cur->data == n) return cur;
		if(cur->data > n) return prev;
		prev = cur;
		cur = cur->next;
	}
}

// returning the pointer to the element 
// whose data is equal to input data
struct node *searchNode2(int n) {
	if(head == NULL) return head;
	node *cur = head;
	node *prev = head;
	while(cur) {
		if(cur->data == n) return cur;
		prev = cur;
		cur = cur->next;
	}
	return cur;
}
void addNode(int n) {
	node *newNode = new node;
	newNode->data = n;
	newNode->next = NULL;

	if(head == NULL) {
		head = newNode;
		return;
	}
	node *cur = head;
	while(cur) {
		if(cur->next == NULL) {
			cur->next = newNode;
			return;
		}
		cur = cur->next;
	}
}



void deleteNode(int n) {
	node *ptr = searchNode(n);
	if(ptr == NULL) 
		cout << "No node with data = " << n << endl;
	if(ptr == head) {
		head = ptr->next;
		return;
	}
	node *cur = head;
	node *prev = head;

	while(cur) {
		if(cur == ptr) {
			prev->next = cur->next;
			return;
		}
		prev = cur;
		cur = cur->next;
	}
}

void display() {
	struct node *list = head;
	while(list) {
		cout << list->data <<" ";
		list = list->next;
	}
	cout << endl;
}
int countNode(node* head)
{
    int count = 0;
 
    while (head->next != NULL) {
 
        // Starting from the next node
        node *ptr = head->next;
        while (ptr != NULL) {
 
            // If some duplicate node is found
            if (head->data == ptr->data) {
                deleteNode(ptr->data);
            }
            ptr = ptr->next;
        }
 
        head = head->next;
    }
 
    // Return the count of duplicate nodes
    return count;
}
int main()
{
	addNode(10);
	addNode(20);
	addNode(40);
	addNode(50);
addNode(40);
display();
  cout<<"let us remove the duplicate"<<endl;
  countNode(head);
  display();
	
	return 0;
}
