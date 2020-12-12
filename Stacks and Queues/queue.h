#include <stdlib.h>
#include <stdio.h>

#define MAX 10000

struct queue{
  int arbitrarynumber;
  struct queue *next;
};
typedef struct queue queue;

//declerations
int arbitrarynumbers[MAX];
queue *QHEAD = NULL;

//prototypes
queue * createQueue(queue *currentNODE, int turn, int max);
void createArbitraryNumbers(int amount);
void traversal(queue* currentNODE); 