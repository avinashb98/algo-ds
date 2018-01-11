#include<iostream>
using namespace std;

struct Node {
  int data;
  Node *nxt;
};

Node *temp = NULL;
Node *fst = NULL;
Node *ptr = NULL;

void create(int data) {

  temp = new Node();
  temp -> data = data;
  if(fst == NULL) {
    fst = temp;
    fst -> nxt = NULL;
  }

  if(ptr == NULL) {
    ptr = fst;
  } else {
    ptr -> nxt = temp;
    ptr = temp;
    ptr -> nxt = NULL;
  }
}

void remove(int pos) {
  struct Node *del_ptr = fst;
  struct Node *temp_del;
  for(int i = 1; i < pos - 1; i++) {
    del_ptr = del_ptr -> nxt;
  }
  temp_del = del_ptr -> nxt;
  temp = temp_del -> nxt;
  del_ptr -> nxt = temp;
}

void insert(int pos, int data) {
  ptr = fst;
  for(int i = 1; i < pos - 1; i++) {
    ptr = ptr -> nxt;
  }

  temp = new Node();
  temp -> data = data;
  temp -> nxt = ptr -> nxt;
  ptr -> nxt = temp;
}

void reverseList(struct Node *p) {
  if(p -> nxt == NULL) {
    fst = p;
    return;
  }
  reverseList(p -> nxt);
  struct Node *q = p -> nxt;
  q -> nxt = p;
  p -> nxt = NULL;
}

void reversePrintList(struct Node *p) {
  if(p  == NULL) {
    return;
  }
  reversePrintList(p -> nxt);
  cout << p -> data << endl;
}

void printList() {
  for(struct Node *i = fst; i != NULL; i = i -> nxt) {
    cout << i -> data << endl;
  }
}

int main() {
  create(1);
  create(2);
  create(3);
  create(4);
  reversePrintList(fst);
  reverseList(fst);
  reversePrintList(fst);
  return 0;
}
