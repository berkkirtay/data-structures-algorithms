#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 100

struct mapArray{
  int integers[SIZE];
  char *strings[SIZE];
};
typedef struct mapArray mapArray;

mapArray *createMapArray(){
    mapArray *newMap = (mapArray *)malloc(sizeof(mapArray));
    int index;
    for(index = 0; index < SIZE; index++){
        newMap->strings[index] = (char *)malloc(sizeof(10));
    }
    return newMap;
}

void insertString(mapArray *newMapArray, int hashindex, char * str){
    newMapArray->strings[hashindex] = (char *)calloc(1, sizeof(strlen(str)));
    strcpy(newMapArray->strings[hashindex], str);
}
void insertNumber(mapArray *newMapArray, int hashindex, int number){
    newMapArray->integers[hashindex] = number;
}
char *getstr(mapArray *newMapArray, int hashindex){
    return newMapArray->strings[hashindex];
}
int getStrIndex(mapArray *newMapArray, char * str){
    int index;
    for(index = 0; index < SIZE; index++){
        if(strcmp(newMapArray->strings[index], str) == 0){
            return index;
            break;
        }
    }
    return -1;
}
int getNumber(mapArray *newMapArray, int index){
    return newMapArray->integers[index];
}
int getNumberIndex(mapArray *newMapArray, int number){
    int index;
    for(index = 0; index < SIZE; index++){
        if(newMapArray->integers[index] == number){
            return index;
            break;
        }
    }
    return -1;

}

int main(){
    mapArray *newMapArray = createMapArray();
    insertString(newMapArray, 10, "hash");
    insertString(newMapArray, 56, "array");
    insertString(newMapArray, 32, "test");
    insertString(newMapArray, 23, "233214214142");
    insertNumber(newMapArray, 43, 75802231);
        
    printf("%d - %s\n", getStrIndex(newMapArray, getstr(newMapArray, 10)), getstr(newMapArray, 10));
    printf("%d - %s\n", getStrIndex(newMapArray, "array"), getstr(newMapArray, 56));
    printf("%d - %s\n", getStrIndex(newMapArray, getstr(newMapArray, 32)), getstr(newMapArray, 32));
    printf("%d - %s\n", getStrIndex(newMapArray, getstr(newMapArray, 23)), getstr(newMapArray, 23));
    printf("%d - %d\n",getNumberIndex(newMapArray, getNumber(newMapArray, 43)), getNumber(newMapArray, 43));
    return 0;
}