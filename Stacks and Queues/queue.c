#include "queue.h"

int main(){
  createArbitraryNumbers(MAX);
  QHEAD = createQueue(QHEAD, 0 , MAX);
  traversal(QHEAD);
  printf("/**********************************************/\n");
  initializeQUEUE2();
  int i,err;
  for(i = 0; i < MAX+100; i++){
    err = enqueue(arbitrarynumbers[i]);
    if(err == -1){
      err = 0;
      break;
    }
    printf("%d\n", err);
  }
  for(i = 0; i < MAX+100; i++){
    err = dequeue();
    if(err == -1){
      break;
    }
    printf("%d\n", err);
  }  
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
  int j,i;
  for(j = 0; j < amount; j++){
    i = amount - j;
    arbitrarynumbers[j] = (j*j)% amount;
  }
}
void traversal(queue* currentNODE){
  if(currentNODE == NULL){
    return;
  }
  printf("%d\n", currentNODE->arbitrarynumber);
  traversal(currentNODE->next);
}

void initializeQUEUE2(){
  QHEAD2 = (queue2 *)malloc(sizeof(*QHEAD2));
  QHEAD2->rearptr = QHEAD2->frontptr = -1;
}
int enqueue(int data){
  if(QHEAD2->rearptr == MAX-1){
    printf("Queue is full!");
    return -1;
  }
  QHEAD2->queue1[++QHEAD2->rearptr] = data;

}
int dequeue(){
  if(QHEAD2->frontptr == QHEAD2->rearptr){
    printf("Queue is empty!");
    return -1;
  }
  return QHEAD2->queue1[++QHEAD2->frontptr];
}