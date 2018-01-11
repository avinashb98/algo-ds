#include<iostream>
#include<cmath>
#include<queue>
#include<bits/stdc++.h>

using namespace std;
struct Node {
  int data;
  Node *left, *right;
};

Node *root = NULL;

Node *createNode(int data) {
  Node *temp = new Node();
  temp -> data = data;
  temp -> left = NULL;
  temp -> right = NULL;
  return temp;
}

void insert(Node *ptr, int data) {

  if(ptr == NULL) {
    root = createNode(data);
    return;
  }

  if(data > ptr -> data) {
    if(ptr -> right == NULL){
      ptr -> right = createNode(data);
      return;
    }
    insert(ptr -> right, data);
  }

  if(data <= ptr -> data) {
    if(ptr -> left == NULL){
      ptr -> left = createNode(data);
      return;
    }
    insert(ptr -> left, data);
  }
}

void breadthFirst(Node *ptr) {
  if(ptr == NULL)
    return;
  queue <Node *> q;
  q.push(ptr);
  while(!q.empty()) {
    Node *current = q.front();
    cout << current -> data << " ";
    if(current -> left != NULL) q.push(current -> left);
    if(current -> right != NULL) q.push(current -> right);
    q.pop();
  }
}

void inOrder(Node *ptr) {
  if(ptr -> left != NULL) {
    inOrder(ptr -> left);
  }
  cout << ptr -> data << endl;
  if(ptr -> right != NULL) {
    inOrder(ptr -> right);
  }
}

void preOrder(Node *ptr) {
  cout << ptr -> data << endl;
  if(ptr -> left != NULL) {
    preOrder(ptr -> left);
  }
  if(ptr -> right != NULL) {
    preOrder(ptr -> right);
  }
}

void postOrder(Node *ptr) {
  if(ptr -> left != NULL) {
    postOrder(ptr -> left);
  }
  if(ptr -> right != NULL) {
    postOrder(ptr -> right);
  }
  cout << ptr -> data << endl;
}

int findMin(Node *ptr) {
  if(ptr -> left == NULL)
    return ptr -> data;
  else findMin(ptr -> left);
}

int findMax(Node *ptr) {
  if(ptr -> right == NULL)
    return ptr -> data;
  else findMax(ptr -> right);
}

int findHeight(Node *ptr) {
  if(ptr == NULL) {
    return 0;
  }
  return max(
    findHeight(ptr -> left),
    findHeight(ptr -> right)
  ) + 1;
}

Node *search(Node *ptr, int key) {
  if(ptr -> data == key) return ptr;
  else {
    if(ptr -> left != NULL && key <= ptr -> data) {
      search(ptr -> left, key);
    } else {
      if(ptr -> right != NULL) search(ptr -> right, key);
    }
  }
}

int isBSTutil(Node *ptr, int min, int max) {
  if(ptr == NULL) return 1;
  if(ptr -> data < min || ptr -> data > max)
    return 0;
  return isBSTutil(ptr -> left, min, ptr -> data)
      && isBSTutil(ptr -> right, ptr -> data, max);
}

int isBST(Node *ptr) {
  return isBSTutil(ptr, INT_MIN, INT_MAX);
}

int main() {
  insert(root, 23);
  insert(root, 4);
  insert(root, 45);
  insert(root, 12);
  insert(root, 5);
  insert(root, 2);
  insert(root, 3);
  insert(root, 6);
  insert(root, 13);
  insert(root, 17);
  inOrder(root);
  return 0;
}
