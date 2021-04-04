#include <stdlib.h>
#include <stdio.h>
#include <time.h>


//prototypes
void swap(int defaultarray[100], int i, int j);
// O(n^2) sorting algorithms
void selectionsort(int defaultarray[100]); 
void insertionsort(int defaultarray[100]);
void bubblesort(int defaultarray[100]);
// O(nlogn) sorting algorithms
void startMergeSort(int size);
void mergesort(int *defaultarray, int size);
void mergeArrays(int *defaultarray, int *defaultarray2, int *mergedarray, int size1, int size2);
void quicksort(int defaultarray[100]);

int main(){
    startMergeSort(8);
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
void startMergeSort(int size){
    printf("----------------------------------Merge Sort----------------------------------\n");
     srand(time(NULL));
    int defaultarray[size];
    int i;
    for(i = 0; i < size; i++){
        defaultarray[i] = random() % 100;
        printf("%d\n", defaultarray[i]);
    }
    mergesort(defaultarray, 8);
    for(i = 0; i < size; i++){
    printf("%d. -> %d\n", i, defaultarray[i]);
    }
}
void mergeArrays(int *defaultarray1, int *defaultarray2, int *mergedarray, int size1, int size2){ 
    int i = 0, j = 0;
    while(i < size1 && j < size2){
        if(defaultarray1[i] < defaultarray2[j]){
            mergedarray[i + j] = defaultarray1[i];
            i++;
        }
        else{
            mergedarray[i + j] = defaultarray2[j];
            j++;
        } 
    }
    while(i < size1){
        mergedarray[i + j] = defaultarray1[i];
        i++;
    }
    while(j < size2){
        mergedarray[i + j] = defaultarray2[j];
        j++;
    }    
}
void mergesort(int *defaultarray, int size){
    if(size > 1){
      int i = 0;
      int tempArr1[size/2];
      int tempArr2[size/2];
      while(i < size / 2){
          tempArr1[i] = defaultarray[i];
          i++;
      }
      int j = 0;
      while(j < size - i){
          tempArr2[j] = defaultarray[i + j];
          j++;
      }
      mergesort(tempArr1, i);
      mergesort(tempArr2, j);
      mergeArrays(tempArr1, tempArr2, defaultarray, i, j);
    }
    else{
      return;
    }
}


