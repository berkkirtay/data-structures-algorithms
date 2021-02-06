#include "stack.h"

int main(){
  createArbitraryNumbers(MAX);
  SHEAD = (stack *)malloc(sizeof(*SHEAD));  
  SHEAD->arbitrarynumber = 90000009;  // That indicates head of the stack.
  SHEAD->next = NULL;
  SHEAD = createstack(0 , MAX);
  traversal(SHEAD);

  return 0;
}

stack * createstack(int turn, int max){
  if(turn < max){
    stack * tempNODE = (stack *)malloc(sizeof(*tempNODE));
    tempNODE->arbitrarynumber = arbitrarynumbers[turn];
    tempNODE->next = SHEAD;
    SHEAD = tempNODE;
    SHEAD = createstack(turn + 1, max);
  }
  return SHEAD;
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
stack* pop(){
  stack *tempNode = SHEAD;
  if(tempNode == NULL){
    return NULL;
  }
  SHEAD = SHEAD->next;
  return tempNode;
}
void traversal(){
  stack* currentNODE = pop();
  if(currentNODE == NULL){
    return;
  }
  printf("%d\n", currentNODE->arbitrarynumber);
  traversal(currentNODE->next);
}
