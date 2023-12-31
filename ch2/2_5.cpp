#include <iostream>
using namespace std;
struct Node {
  int data;
  Node * next;
  Node ( int d ) : data{ d }, next{ nullptr } { }
};

void insert( Node * & head, int data ) {
  Node * newNode = new Node(data);
  newNode->next = head;
  head = newNode;
}

void printList( Node * head ) {
  while ( head ) {
   cout << head->data << "-->";
    head = head->next;
  }
  cout << "nullptr" << endl;
}

Node * add_iterative( Node * list1, Node * list2 ) {
  if ( list1 == nullptr ) {
    return list2;
  }
  if ( list2 == nullptr ) {
    return list1;
  }

  // list3 will store result
  Node * list3 = nullptr;
  // for adding new nodes to tail of list3
  Node * list3Tail = nullptr;

  int value = 0, carry = 0;

  while( list1 || list2 ) {
    // add the values, if one of the list has already been traversed, add 0
    value = carry + (list1 ? list1->data : 0 ) + (list2 ? list2->data : 0);

    // get the new value and carry
    if ( value > 9 ) {
      carry = 1;
      value = value % 10;
    } else {
      carry = 0;
    }

    //new node
    Node * temp = new Node(value);

    //if this is the first node, populate the result, else add to the tail
    if ( list3 == nullptr ) {
      list3 = temp;
    } else {
      list3Tail->next = temp;
    }

    //make new tail
    list3Tail = temp;

    if (list1) {
      list1 = list1->next;
    }

    if (list2) {
      list2 = list2->next;
    }
  }

  if ( carry > 0 ) {
    list3Tail->next = new Node(carry);
  }
  return list3;
}

Node * add_recursive( Node * list1, Node * list2, int carry) {
  if ( list1 == nullptr && list2 == nullptr && carry == 0 ) {
    return nullptr;
  }
  int value = carry;
  if ( list1 ) {
    value += list1->data;
  }
  if ( list2 ) {
    value += list2->data;
  }

  Node * resultNode = new Node( value % 10 );

  resultNode->next = add_recursive( list1 ? (list1->next) : nullptr,
                                    list2 ? (list2->next) : nullptr,
                                    value > 9 ? 1 : 0 );
  return resultNode;
}

/**
 *  Follow up part:
 *  Lists are stored such that 1's digit is at the tail of list.
 *  617 ==> 6 --> 1 --> 7
 *  295 ==> 2 --> 9 --> 5
 */


void padList( Node * & list, int padding ) {
  for ( int i = 0; i < padding; ++i ) {
    insert(list, 0);
  }
}

int length( Node * head ) {
  int len = 0;
  while( head ) {
    len++;
    head = head->next;
  }
  return len;
}

Node * add_followup_helper( Node * list1, Node * list2, int & carry ) {
  if ( list1 == nullptr && list2 == nullptr && carry == 0 ) {
    return nullptr;
  }

  Node * result = add_followup_helper(list1 ? (list1->next) : nullptr,
                                      list2 ? (list2->next) : nullptr,
                                      carry);

  int value = carry + (list1 ? list1->data : 0 ) + (list2 ? list2->data : 0);
  insert( result, value % 10 );
  carry = ( value > 9 ) ? 1 : 0;
  return result;
}


Node * add_followup( Node * list1, Node * list2 ) {
  int len1 = length(list1);
  int len2 = length(list2);

  //pad the smaller list
  if ( len1 > len2 ) {
    padList( list2, len1 - len2 );
  } else {
    padList( list1, len2 - len1 );
  }
  int carry = 0;
  Node * list3 = add_followup_helper( list1, list2, carry);
  if ( carry ) {
    insert( list3, carry);
  }
  return list3;
}
 void deleteList( Node * & head ) {
   Node * nextNode;
   while(head) {
     nextNode = head->next;
     delete(head);
     head = nextNode;
   }
 }

int main()
{
  //making list 1 for number 617
  Node * list1 = nullptr;
  insert(list1, 6);
  insert(list1, 1);
  insert(list1, 7);
cout << "List1:  ";
  printList(list1);

  //making list2 for number 295
  Node * list2 = nullptr;
  insert(list2, 2);
  insert(list2, 9);
  insert(list2, 5);
  cout << "List2:  ";
  printList(list2);

  Node * list3 = add_iterative(list1, list2);
 cout << "Iterative Solution: \n";
cout << "List3:  ";
  printList(list3);

  Node * list4= add_recursive(list1, list2, 0);
cout << "Recursive Solution: \n";
cout << "List4:  ";
  printList(list4);

  deleteList(list1);
  deleteList(list2);
  deleteList(list3);
  deleteList(list4);

cout << "\n\nNow follow up case, lists are stored such that 1's digit is at the tail of list\n";
  //Node * listx = nullptr;
  insert(list1, 4);
  insert(list1, 3);
  insert(list1, 2);
  insert(list1, 9);
cout << "List1:  ";
  printList(list1);

  insert(list2, 9);
  insert(list2, 9);
  insert(list2, 8);
  cout << "List2:  ";
  printList(list2);

  list3 = add_followup(list1, list2);
  cout << "Adding two above lists\n";
  cout << "List3:  ";
  printList(list3);

  deleteList(list1);
  deleteList(list2);
  deleteList(list3);

  return 0;
}
