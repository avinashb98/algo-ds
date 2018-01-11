#include<iostream>
using namespace std;

struct Node {
  int data;
  struct Node *nxt;
  struct Node *prev;
};

struct Node *fst = NULL;
struct Node *ptr = NULL;
struct Node *temp = NULL;

void create(int data) {
  temp = new Node();
  temp -> data = data;
  if(fst == NULL) {
    fst = temp;
    fst -> nxt = NULL;
    fst -> prev = NULL;
  }

  if(ptr == NULL) {
    ptr = fst;
  } else {
    ptr -> nxt = temp;
    temp -> prev = ptr;
    ptr = temp;
    ptr -> nxt = NULL;
  }
}

int main() {

  return 0;
}
