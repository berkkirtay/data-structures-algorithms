#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int mergedarray[200];
//prototypes
void swap(int defaultarray[100], int i, int j);
// O(n^2) sorting algorithms
void selectionsort(int defaultarray[100]); 
void insertionsort(int defaultarray[100]);
void bubblesort(int defaultarray[100]);
// O(nlogn) sorting algorithms
void mergesort(int defaultarray[100], int defaultarray2[100]);
void quicksort(int defaultarray[100]);

int main(){
    int defaultarray[100];
    int defaultarray2[100];
    srand(time(NULL));
    int i;
    for(i = 0; i < 100; i++){
        defaultarray[i] = random() % 10000;
        printf("%d\n", defaultarray[i]);
    }
    sleep(2);
    for(i = 0; i < 100; i++){
        defaultarray2[i] = random() % 1000 + 4;
        printf("%d\n", defaultarray2[i]);
    }

    insertionsort(defaultarray);
    insertionsort(defaultarray2);
    mergesort(defaultarray, defaultarray2);

    for(i = 0; i < 200; i++){
    printf("%d\n", mergedarray[i]);}

    return 0;

}
void swap(int defaultarray[100], int i, int j){
    int temp = defaultarray[i];
    defaultarray[i] = defaultarray[j];
    defaultarray[j] = temp;
}

void selectionsort(int defaultarray[100]){
    printf("----------------------------------Selection Sort----------------------------------\n");
    int i,j;
    for(i = 0; i < 100; i++){
        int min = 1000000;
        int minelement;
        for(j = i; j < 100; j++){
            if(min > defaultarray[j]){
                min = defaultarray[j];
                minelement = j;
            }
        }
        swap(defaultarray, i, minelement); // minimum element is found and stored at minelement.
    }
}
void insertionsort(int defaultarray[100]){
    printf("----------------------------------Insertion Sort----------------------------------\n");
    int i,j;
    for(i = 0; i < 100; i++){
        for(j = 0; j < 100; j++){
            if(defaultarray[i] < defaultarray[j]){
              swap(defaultarray, i, j);
            }
        }
    }
}
void bubblesort(int defaultarray[100]){
    printf("----------------------------------Bubble Sort----------------------------------\n");
    int i,j;
    for(i = 0; i < 100; i++){    
        for(j = 0; j < 100 - i; j++){
            if(defaultarray[j] > defaultarray[j + 1]){
                swap(defaultarray, j, j + 1);
            }
        }
    }
}

void mergesort(int *defaultarray, int *defaultarray2){ // I will continue from here..
    int i = 0, j = 0;
    while(i + j < 199){
        if(defaultarray[i] < defaultarray2[j] && i<100){
            mergedarray[j + i] = defaultarray[i++];
        }
        else if(j < 100){
            mergedarray[j + i] = defaultarray2[j++];
        }
    }
}


