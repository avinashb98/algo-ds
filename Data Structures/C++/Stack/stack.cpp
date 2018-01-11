#include<iostream>

using namespace std;

struct Node {
  int data;
  Node *nxt;
};

Node *top = NULL;

void push(int n) {
  Node *temp = new Node();
  temp -> data = n;
  temp -> nxt = top;
  top = temp;
}

int pop() {
  if(top == NULL)
    return 0;
  Node *temp = top;
  top = temp -> nxt;
  int data = temp -> data;
  delete temp;
  return data;
}

void printList() {
  for(struct Node *i = top; i != NULL; i = i -> nxt) {
    cout << i -> data << endl;
  }
}

int main() {
  push(1);
  push(5);
  push(3);
  push(2);
  printList();
  pop();
  printList();
  return 0;
}
