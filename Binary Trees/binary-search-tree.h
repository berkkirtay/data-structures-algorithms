#include <stdlib.h>
#include <stdio.h>

#define MAX 10000

struct BST{
  int arbitrarynumber;
  struct BST * rightChild;
  struct BST * leftChild;
};
typedef struct BST BST;

//declarations
int arbitrarynumbers[MAX]; // First we create an arbitrary numbers array just before creating a binary tree with them.
BST *BSTHEAD = NULL;

//prototypes
BST * createBinarySearchTree(BST* currentNODE, int turn, int max);
void createArbitraryNumbers(int amount);
void traversal(BST* currentNODE); 