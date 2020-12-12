#include "queue.h"

int main(){
  createArbitraryNumbers(MAX);
  QHEAD = createQueue(QHEAD, 0 , MAX);
  traversal(QHEAD);
  return 0;
}

queue * createQueue(queue *currentNODE, int turn, int max){
  if(turn < max){
    currentNODE = (queue *)malloc(sizeof(*currentNODE));
    currentNODE->arbitrarynumber = arbitrarynumbers[turn];
    currentNODE->next = NULL;
    currentNODE->next = createQueue(currentNODE->next, turn + 1, max);
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
void traversal(queue* currentNODE){
  if(currentNODE == NULL){
    return;
  }
  printf("%d\n", currentNODE->arbitrarynumber);
  traversal(currentNODE->next);
}