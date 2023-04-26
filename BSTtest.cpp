#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define Left 0
#define Right 1

using namespace std;

int ans = 0;
typedef struct Node {
  int key;
  struct Node* left;
  struct Node* right;
} Node;

typedef struct Node *Tree;

Node* getNode(){
  Node* nd = (Node *)malloc(sizeof(Node));
  nd->key = 111;
  nd->left = NULL;
  nd->right= NULL;
  return nd;
}

void inorderBST(Tree T){
  if(T != NULL){
  inorderBST(T->left);
  cout << T->key << " ";
  inorderBST(T->right);
}
}


void insertBST(Tree *T, int newKey) {
    // getNode() 사용해서 구현
  Node* p = *T; // current
  // Node* p = root;
  Node* q = NULL; //parent
  while (p != NULL){
    // step 1: newKey의 삽입 위치 q를 찾음.
    if (newKey == p->key){
      return;
    }
    q = p;// q는 p의 부모 노드를 지시
    // if (newKey < (*p).key){
    if (newKey < p->key){
      p = p->left;
    }
    else {
      p = p->right;
    }
  }
  // // step 2: newKey를 갖는 노드를 만듬.

  Node* newNode = getNode();
  newNode->key = newKey;

  if (q == NULL){
    ans = 1;
    *T = newNode;
  }
  else{
    if (newKey < q->key){
      ans = 2;
      q->left = newNode;
    }
    else{
      ans = 3;
      q->right =newNode;
    }
  }
}

int height(Tree T){
  int h = 0;
  if (T != NULL){
    h = 1 + max(height(T->left), height(T->right));
  }//양쪽 서브트리를 비교해 더 큰 값에 1을 더해줌.
  //노드가 없다면 0 반환
  //leaf node에서 위로 갈 수록 1씩 값이 더해짐.
  return h;
}

int noNodes(Tree T){
  int count = 0;
  if (T!=NULL){
    count = 1 + noNodes(T->left) + noNodes(T->right);
  }
  return count;

}
// Tree = Node*  이걸로 호출할 수 있었다.
Node* maxNode(Tree T){
  if (T->right == NULL){
    return T;
  }
  //왼쪽 서브트리만 남아있다면 nd가 최대값
  else{
    maxNode(T->right);
  }//오른쪽 서브트리가 더이상 없을 때까지 진행.
}

Node* minNode(Tree T){
  if (T->left == NULL){//오른쪽 서브트리만 남아있다면 nd가 최소값
    return T;
  }else{
    minNode(T->left);
  }//왼쪽 서브트리가 더이상 없을 때까지 진행.
}

void deleteBST(Tree* T, int deleteKey){
  Node *p = *T;
  Node *q = NULL;
  // cout << deleteKey << " 를 삭제합니다." <<endl;

  while (p != NULL){
    // step 1: newKey의 삽입 위치 q를 찾음.
    if (deleteKey == p->key){
      break;
    }
    q = p;// q는 p의 부모 노드를 지시
    if (deleteKey < p->key){
      p = p->left;
    }
    else {
      p = p->right;
    }
  }


  if (p->left == NULL && p->right == NULL){
    //case of leaf
    if (q==NULL){
      //case of root
      // root = NULL;
      T = NULL;
    }
    else if (q->left == p){
      q->left = NULL;
    }
    else {
      q->right = NULL;
    }
  free(p);
  }
  else if (p->left == NULL || p->right == NULL){
    //case of degree 1
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
      // p의 left에 있음
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
  }
  else {
    //case of degree 2
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
    if (flag == Left){ // 왼쪽 서브트리에서 다시 삭제
      deleteBST(&p->left,r->key);
    }
    else{ // 오른쪽 서브트리에서 다시 삭제
      deleteBST(&p->right, r->key);
    }
  }  // 삭제할 원소가 없음
} //end of deleteNode


int main(){
  //
  // BST T;

  Tree T = NULL;
  int a[20] = {25,500,33,49,17,404,29,105,39,66,305,
  44,19,441,390,12,81,50,100,999};
  for (int i=0;i<20;i++){
    insertBST(&T, a[i]); inorderBST(T); cout<<endl;
  }


  for (int i=0; i<20; i++){
    deleteBST(&T, a[i]); inorderBST(T);cout<<endl;

  }

  T = NULL;

  for (int i=0;i<20;i++){
    insertBST(&T, a[i]); inorderBST(T);cout<<endl;
  }

  for (int i=19; i>=0; i--){
    deleteBST(&T, a[i]); inorderBST(T);cout<<endl;
  }
}
