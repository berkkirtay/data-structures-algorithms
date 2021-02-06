#include <stdlib.h>
#include <stdio.h>

#define MAX 10000

struct queue{  // Alternative queue, pretty much a linked-list
  int arbitrarynumber;
  struct queue *next;
};
typedef struct queue queue;

struct queue2{  // Standart queue
  int rearptr;
  int frontptr;
  int queue1[MAX];
};
typedef struct queue2 queue2;

//declerations
int arbitrarynumbers[MAX];
queue *QHEAD = NULL;
queue2 *QHEAD2 = NULL;

//prototypes
queue * createQueue(queue *currentNODE, int turn, int max);
void createArbitraryNumbers(int amount);
void traversal(queue* currentNODE); 
void initializeQUEUE2();
int enqueue(int data);
int dequeue();