#include "binary-search-tree.h"

int main(){
  createArbitraryNumbers(MAX);
  int j = 0;
  while(MAX > j){
    BSTHEAD = createBinarySearchTree(BSTHEAD, 0 , MAX);
    j++;
  }
  traversal(BSTHEAD);
  return 0;
}
BST * createBinarySearchTree(BST* currentNODE, int turn, int max){  // Creating a binary tree recursively
  if(currentNODE == NULL){
    currentNODE = (BST *)malloc(sizeof(*currentNODE));
    currentNODE->arbitrarynumber = arbitrarynumbers[turn];
    currentNODE->leftChild = currentNODE->rightChild = NULL;
    }
  else{
    if(currentNODE->arbitrarynumber > arbitrarynumbers[turn]){
    currentNODE->leftChild = createBinarySearchTree(currentNODE->leftChild, turn + 1, max);
    }
    else{
      currentNODE->rightChild = createBinarySearchTree(currentNODE->rightChild, turn + 1, max);
    }
  }
  return currentNODE;
}
void createArbitraryNumbers(int amount){
  int j, i;
  int newarbitraryValue = 0;
  for(j = 0; j < amount; j++){
    for(i = 1; i < j; i++){
      newarbitraryValue += j % i ;
    }
    arbitrarynumbers[j] = newarbitraryValue;
    newarbitraryValue = 0;
  }
}
void traversal(BST* currentNODE){  // Preorder traversal
  if(currentNODE == NULL){
      return;
  }
  printf("%d\n",currentNODE->arbitrarynumber);
  traversal(currentNODE->leftChild);
  traversal(currentNODE->rightChild);
}