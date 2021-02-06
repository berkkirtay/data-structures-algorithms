#include <stdlib.h>
#include <stdio.h>

#define MAX 10000

struct stack{
  int arbitrarynumber;
  struct stack *next;
};
typedef struct stack stack;

//declerations
int arbitrarynumbers[MAX];
stack *SHEAD = NULL;

//prototypes
stack * createstack(int turn, int max);
stack* pop();
void createArbitraryNumbers(int amount);
void traversal(); 
