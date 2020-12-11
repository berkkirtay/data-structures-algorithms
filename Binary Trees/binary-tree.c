#include "binary-tree.h"

int main(){
  createArbitraryNumbers(MAX);
  BTHEAD = createBinaryTree(BTHEAD, 0 , MAX);
  traversal(BTHEAD);
  return 0;
}
BT * createBinaryTree(BT* currentNODE, int turn, int max){  // Creating a binary tree recursively
  if(turn < max){
    currentNODE = (BT *)malloc(sizeof(*currentNODE));
    currentNODE->arbitrarynumber = arbitrarynumbers[turn];
    currentNODE->leftChild = currentNODE->rightChild = NULL;
    currentNODE->leftChild = createBinaryTree(currentNODE->rightChild, 2*turn + 1, max);
    currentNODE->rightChild = createBinaryTree(currentNODE->leftChild, 2*turn + 2, max);
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
void traversal(BT* currentNODE){  // Preorder traversal
  if(currentNODE == NULL){
      return;
  }
  printf("%d\n",currentNODE->arbitrarynumber);
  traversal(currentNODE->leftChild);
  traversal(currentNODE->rightChild);
}