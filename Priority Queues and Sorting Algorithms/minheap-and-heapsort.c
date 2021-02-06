#include <stdlib.h>
#include <stdio.h>

  //        ** n = 1;    - Let's assume we inserted a data into heap. That data will be placed at 8th location.
  //       /  \          - And we will directly compare it with its parent data and decide if it's in the proper
  //      *    *   2, 3  - location in the heap or not (min-max heap property). Also as we can observe, 
  //     / \  / \        - time complexity is O(logn) for insertion operation.
  //    *   **   *  4, 5, 6, 7 
struct heapstrct{
  int minheap[1000];
  int heapptr;
  int cost;
};
typedef struct heapstrct heapstrct;

heapstrct * minheap = NULL;

void insertToheap(int data);
int dequeueMin();
void swap(heapstrct *heap, int ptr);

int main(){
    minheap = (heapstrct*)malloc(sizeof(*minheap));
    minheap->cost = 0;
    minheap->heapptr = 0;
    int j;
    for(j = 1; j < 10; j++){
      insertToheap(rand() % 100);
    }
    for(j = 1; j < 10; j++){
      printf("%d - %d. element\n", minheap->minheap[j], j);
    }
    printf("----------------------------\n");
    for(j=1 ; j < 10; j++){  // Minimum Heap sort
    int temp = dequeueMin();
     printf("Min %d. => %d\n", j, temp);
    }

  return 0;    
}

void insertToheap(int data){
  minheap->heapptr++;
  if(minheap->minheap[1] == 0){
    minheap->minheap[minheap->heapptr] = data;
  }
  else{
    int tempptr = minheap->heapptr;
    minheap->minheap[minheap->heapptr] = data;                     
    while(minheap->minheap[tempptr] <= minheap->minheap[tempptr/2]){ 
      swap(minheap, tempptr);                                          
      tempptr /= 2;                                              
    } 
  }
}

int dequeueMin(){
  if(minheap->minheap[1] == 0){
    return -1;  // That will show us if heap is empty or not.
  }
  int min = minheap->minheap[1];
  minheap->minheap[1] = minheap->minheap[minheap->heapptr];
  minheap->minheap[minheap->heapptr--] = 0;
  int tempptr = 1;
   
  while(minheap->minheap[tempptr*2] < minheap->minheap[tempptr] || minheap->minheap[tempptr*2+1] < minheap->minheap[tempptr]){  
    if(minheap->heapptr <= tempptr) break;
    if(tempptr*2 >= minheap->heapptr){
      break;  
    }
    if(minheap->minheap[tempptr*2+1] < minheap->minheap[tempptr*2]){
      swap(minheap, tempptr*2+1);   
    }
    else{
      swap(minheap, tempptr*2);   
    }                       
    tempptr *= 2;      
  } 
  return min;
}
void swap(heapstrct *heap, int ptr){
  int tempValue = heap->minheap[ptr];
  heap->minheap[ptr] = minheap->minheap[ptr/2];
  heap->minheap[ptr/2] = tempValue;
}