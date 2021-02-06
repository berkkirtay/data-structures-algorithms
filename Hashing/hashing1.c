#include <stdlib.h>
#include <stdio.h>
/* Test cases for the cost > 99 : 1303 with 13 rehashing
   for the cost > 50 : 1180 with 23 rehashing
   for the cost > 500 (when hasharray size is 1000) : 17050 with 34 rehashing
   We can decrease the cost with giving up on rehashing cost. And we can approximate O(1) time complexity.
*/ 
struct hashstrct{
  int hasharray[100];
  int cost;
  struct hashstrct *newhashstrct; // In case of rehashing, we will expand our structure.
};
typedef struct hashstrct hashstrct;
hashstrct *newHash = NULL;

void insertdata(int data, int m);

int main(){
  newHash =(hashstrct*)malloc(sizeof(*newHash));
  newHash->cost = 0;
  int rehashingAmount = 0;
  int totalCost = 0;
  int j;
  for(j = 0; j < 1000; j++){
      insertdata(j*(j/3 % 11), 97); //We chose 97 since it is the biggest prime number smaller than the size of hasharray.
      if(newHash->cost > 50){  
        rehashingAmount++;    
        totalCost += newHash->cost;
        hashstrct *temp = (hashstrct*)malloc(sizeof(*newHash));
        temp->cost = 0;
        newHash->newhashstrct = temp;
        newHash = newHash->newhashstrct;
      }
  }
  /*We can easily observe that whenever we increase data amount to insert, cost for 
   this operation increases dramatically. To avoid this, we will use rehashing. */
  printf("Cost for hashing %d datas : %d with %d rehashing\n", j, totalCost, rehashingAmount); 
  
  return 0;                                             
}

void insertdata(int data, int m){
    int hashValue = data % m;
    if(newHash->hasharray[hashValue] == 0){
      newHash->hasharray[hashValue] = data;
      newHash->cost++;
    }
    else{
      hashValue = (hashValue +(data % m+1 ))% m; // Basic double hashing
      newHash->hasharray[hashValue] = data;
      newHash->cost +=2;
    }
    printf("%d inserted with the hashing number : %d\n", newHash->hasharray[hashValue], hashValue);

}