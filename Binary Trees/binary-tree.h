#include <stdlib.h>
#include <stdio.h>

#define MAX 10000

struct BT{
  int arbitrarynumber;
  struct BT * rightChild;
  struct BT * leftChild;
};
typedef struct BT BT;

//declarations
int arbitrarynumbers[MAX]; // First we create an arbitrary numbers array just before creating a binary tree with them.
BT *BTHEAD = NULL;

//prototypes
BT * createBinaryTree(BT* currentNODE, int turn, int max);
void createArbitraryNumbers(int amount);
void traversal(BT* currentNODE); 