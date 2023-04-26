/**
 * File processing, 2020
 * AVL.cpp
 * implementation of AVL tree
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define Left 0
#define Right 1
using namespace std;

/**
 * Node represents a single node in AVL tree.
 */
typedef struct Node {
  int         key, bf;
  struct Node *left, *right;
} Node;

typedef Node *Tree;

/**
 * getNode returns a new node.
 * @return a new node
 */
Node *getNode() {
  /* write your code here */
  Node* nd = (Node *)malloc(sizeof(Node));
  nd->key = 0;
  nd->bf = 0;
  nd->left = NULL;
  nd->right= NULL;
  return nd;
}

int height(Tree T){
  int h = 0;
  if (!T){return 0;}
  int leftH = height(T->left);
  int rightH = height(T->right);
  return 1 + (leftH > rightH ? leftH : rightH);
}

/**
 * updateBF updates balancing factors of nodes in T
 * and finds the unbalanced node nearest to y.
 * @param T: an AVL tree
 * @param y: the inserted/deleted node
 * @param x: the unbalanced node nearest to y
 * @param P: parent node of x
 */
void updateBF(Tree *T, Node *y, Node **x, Node **P) {
  Node* c = *T; // current
  Node* q = NULL;
  while (c != NULL){
    c->bf = height(c->left) - height(c->right);
    if(c->bf >1 ||c->bf < -1){
      *P = q;
      *x = c;
    }
    q = c;
    if(y == NULL){
      return;
    }else if (y->key < c->key){
      c = c->left;
    }else if(y->key > c->key) {
      c = c->right;
    }else{
      return;
    }
    
    
  }
  

}

/**
 * rotateLL implements LL rotation in subtree rooted with x.
 * @param T: an AVL tree
 * @param x: root node of subtree
 * @param P: parent node of x
 */
void rotateLL(Tree *T, Node *x, Node *P) {
  /* write your code here */
  Node *xl = x->left;
  if(P->left != x && P->right != x){
  }else if(P->left == x){
    P->left = xl;
    
  }else if(P->right == x){
    P->right = xl;
  }
  if(xl->right != NULL){
    x->left = xl->right;
  }else{
    x->left = NULL;
  }
  xl->right = x;
}

/**
 * rotateRR implements RR rotation in subtree rooted with x.
 * @param T: an AVL tree
 * @param x: root node of subtree
 * @param P: parent node of x
 */
void rotateRR(Tree *T, Node *x, Node *P) {
  /* write your code here */
  Node *xr = x->right;
  if(P->left != x && P->right != x){
  }else if(P->left == x){
    P->left = xr;
    
  }else if(P->right == x){
    P->right = xr;
  }
  if(xr->left != NULL){
    x->right= xr->left;
  }else{
    x->right = NULL;
  }
  xr->left = x;
}

/**
 * rotateLR implements LR rotation in subtree rooted with x.
 * @param T: an AVL tree
 * @param x: root node of subtree
 * @param P: parent node of x
 */
void rotateLR(Tree *T, Node *x, Node *P) {
/* write your code here */
Node *xl = x->left;
Node *xlr = xl->right;
if(P->left != x && P->right != x){
}else if(P->left == x){
P->left = xlr;
}else if(P->right == x){
P->right = xlr;
}
if(xlr->right != NULL && xlr->left != NULL){
x->left = xlr->right;
xl->right = xlr->left;
xlr->right = x;
xlr->left = xl;
}else if(xlr->left == NULL){
xl->right = xlr->left;
xlr->left = xl;
xlr->right = x;
x->left = NULL;

}else if(xlr->right == NULL){
x->left = xlr->right;
xlr->left = xl;
xlr->right = x;
xl->right = NULL;
}else{
xlr->right = x;
xlr->left = xl;
xl->right = NULL;
x->left = NULL;

}
}



/**
 * rotateRL implements RL rotation in subtree rooted with x.
 * @param T: an AVL tree
 * @param x: root node of subtree
 * @param P: parent node of x
 */
void rotateRL(Tree *T, Node *x, Node *P) {
  /* write your code here */
  Node *xr = x->right;
  Node *xrl = xr->left;
  if(P->left != x && P->right != x){
  }else if(P->left == x){
    P->left = xrl;
    
  }else if(P->right == x){
    P->right = xrl;
  }
  if(xrl->left != NULL && xrl->right != NULL){
      x->right = xrl->left;
      xr->left = xrl->right;
      xrl->left = x;
      xrl->right = xr;
    }else if(xrl->left == NULL){
      xr->left = xrl->right;
      xrl->left = x;
      xrl->right = xr;
      x->right = NULL;

    }else if(xrl->right == NULL){
      x->right = xrl->left;
      xrl->left = x;
      xrl->right = xr;
      xr->left = NULL;
    }else{
      xrl->left = x;
      xrl->right = xr;
      x->right = NULL;
      xr->left = NULL;

    }
  
}

/**
 * insertBST inserts newKey into T
 * and returns the inserted node.
 * @param T: a binary search tree
 * @param newKey: a key to insert
 * @return the inserted node
 */
Node *insertBST(Tree *T, int newKey) {
    /* write your code here */
  Node* p = *T;
  Node* q = NULL;
  while (p != NULL){
    if (newKey == p->key){
      return p;
    }
    q = p;
    if (newKey < p->key){
      p = p->left;
    }
    else {
      p = p->right;
    }
  }
  Node* newNode = getNode();
  newNode->key = newKey;

  if (q == NULL){
    *T = newNode;
    return *T;
  }
  else{
    if (newKey < q->key){
      q->left = newNode;
      return q->left;
    }
    else{
      q->right =newNode;
      return q->right;
    }
  }
}

/**
 * insertAVL inserts newKey into T.
 * @param T: an AVL tree
 * @param newKey: a key to insert
 */
void insertAVL(Tree *T, int newKey) {
  /**
   * print "NO" if not rotates
   * print "LL" if rotates LL
   * print "RR" if rotates RR
   * print "LR" if rotates LR
   * print "RL" if rotates RL
   */
  /* write your code here */
  /*
  삽입과 삭제는 모두 BST의 삽입과 삭제를 먼저 실행한 후,
  새로 삽입된 노드부터 루트 까지의 BF (balancing factor)를 계산하고,
  문제가 발생했을 때 rotation (LL, RR, LR, RL)을 실행, BF (balancing factor)를 다시 계산
  */
  Node *x = NULL;
  Node *P = NULL;
  Node *newNode = insertBST(T,newKey);
  updateBF(T, newNode, &x, &P);
  if(x== NULL || x->bf == 0){
    cout<<"NO";

  }else if(x->bf >1){
    if((x->left)->bf >0){
      cout<<"LL";
      rotateLL(T,x,P);
      
    }else{
      cout<<"LR";
      rotateLR(T,x,P);
      
    }

  }else if(x->bf <-1){
    if((x->right)->bf <0){
      cout<<"RR";
      rotateRR(T,x,P);
      
    }else{
      cout<<"RL";
      rotateRL(T,x,P);
      
    }

  }
  updateBF(T, newNode, &x, &P);
}

Node* maxNode(Tree T){
  if (T->right == NULL){
    return T;
  }
  else{
    maxNode(T->right);
  }
}

Node* minNode(Tree T){
  if (T->left == NULL){
    return T;
  }
  
  else{
    minNode(T->left);
  }
}

int noNodes(Tree T){
  int count = 0;
  if (T!=NULL){
    count = 1 + noNodes(T->left) + noNodes(T->right);
  }
  return count;
}


/**
 * deleteBST deletes deleteKey from T
 * and returns the parent node of the deleted node.
 * @param T: a binary search tree
 * @param deleteKey: a key to delete
 * @return the parent node of the deleted node
 */
Node *deleteBST(Tree *T, int deleteKey) {
  /* write your code here */
  Node *p = *T;
  Node *q = NULL;

  while (p != NULL){
    if (deleteKey == p->key){
      break;
    }
    q = p;
    if (deleteKey < p->key){
      p = p->left;
    }
    else {
      p = p->right;
    }
  }

  if (p == NULL){
      return q;
  }
  else if (p->left == NULL && p->right == NULL){
    if (q==NULL){
      *T = NULL;
    }
    else if (q->left == p){
      q->left = NULL;
    }
    else {
      q->right = NULL;
    }
  
  free(p);
  return q;
  
  }
  else if (p->left == NULL || p->right == NULL){
    if (p->right != NULL){
      if (q == NULL){
        *T = (*T)->right;
        }
      else if (q->left == p) {
        q->left = p->right;
      }
      else {
        q->right = p->right;
      }
    }
    else {
      if (q==NULL){
        *T = (*T)->left;
      }
      else if (q->left == p){
        q->left = p->left;
      }
      else{
        q->right = p->left;
      }
    }
    free(p);
    return q;
  }
  else {
    Node* r = getNode();
    int flag;

    if (height(p->left) < height(p->right)){
      r = minNode(p->right);
      flag = Right;
    }
    else if (height(p->left) > height(p->right)){
      r = maxNode(p->left);
      flag =Left;
    }
    else {
      if (noNodes(p->left) < noNodes(p->right)){
        r = minNode(p->right);
        flag = Right;
      }
      else{
        r = maxNode(p->left);
        flag = Left;
      }
    }
    p->key = r->key;
    if (flag == Left){deleteBST(&(p->left),r->key);}
    else{deleteBST(&(p->right), r->key);
    }
  }
}

/**
 * deleteAVL deletes deleteKey from T.
 * @param T: an AVL tree
 * @param deleteKey: a key to delete
 */
void deleteAVL(Tree *T, int deleteKey) {
  /**
   * print "NO" if not rotates
   * print "LL" if rotates LL
   * print "RR" if rotates RR
   * print "LR" if rotates LR
   * print "RL" if rotates RL
   */
  /* write your code here */
  Node *x = NULL;
  Node *P = NULL;
  Node *newNode = deleteBST(T,deleteKey);
  updateBF(T, newNode, &x, &P);
  if(x== NULL || x->bf == 0){
    cout<<"NO";

  }else if(x->bf >1){
    if((x->left)->bf >0){
      cout<<"LL";
      rotateLL(T,x,P);
      
    }else{
      cout<<"LR";
      rotateLR(T,x,P);
      
    }

  }else if(x->bf <-1){
    if((x->right)->bf <0){
      cout<<"RR";
      rotateRR(T,x,P);
      
    }else{
      cout<<"RL";
      rotateRL(T,x,P);
      
    }

  }
  updateBF(T, newNode, &x, &P);
}

/**
 * inorderAVL implements inorder traversal in T.
 * @param T: an AVL tree
 */
void inorderAVL(Tree T) {
  /* write your code here */
  if (T!=NULL){
  inorderAVL(T->left);
  cout << T->key << " ";
  inorderAVL(T->right);
  }
}



int main() {
  /* Do not modify the code below */

  const int testcase[] = { 40, 11, 77, 33, 20, 90, 99, 70, 88, 80, 66, 10, 22, 30, 44, 55, 50, 60, 25, 49 };

  Tree T = NULL;

  // insertion
  for (int i=0; i<20; i++) { printf("%d ", testcase[i]); insertAVL(&T, testcase[i]); printf(" : "); inorderAVL(T); printf("\n"); }

  // deletion
  for (int i=0; i<20; i++) { printf("%d ", testcase[i]); deleteAVL(&T, testcase[i]); printf(" : "); inorderAVL(T); printf("\n"); }
  T = NULL;

  // reinsertion
  for (int i=0; i<20; i++) { printf("%d ", testcase[i]); insertAVL(&T, testcase[i]); printf(" : "); inorderAVL(T); printf("\n"); }

  // redeletion
  for (int i=19; 0<=i; i--) { printf("%d ", testcase[i]); deleteAVL(&T, testcase[i]); printf(" : "); inorderAVL(T); printf("\n"); }
  
}
