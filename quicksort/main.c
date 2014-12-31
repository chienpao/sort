//
//  main.c
//  quicksort
//
//  Created by Chien-Pao Chueh on 12/30/14.
//  Copyright (c) 2014 Chien-Pao Chueh. All rights reserved.
//

#include <stdio.h>

void swap(int *, int *);
void exchangeSort(int, int *);
void selectionSort(int, int *);

int main(int argc, const char * argv[]) {
    int array[] = {1,2,3,44,23,9,4,2,3};
    int length = sizeof(array)/sizeof(int);
    exchangeSort(length, array);
    selectionSort(length, array);
    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void exchangeSort(int length, int *array){
    
    for (int i = 0; i< length-1; i++) {
        for (int k =i+1; k< length; k++) {
            if (array[i] > array[k]) {
                swap(&array[i], &array[k]);
            }
        }
    }
    
    printf("Exchange Sort:");
    for (int i = 0; i< length; i++) {
        printf("%d,", array[i]);
    }
    
}
void selectionSort(int length, int *array){
    
    for (int i = 0; i< length-1; i++) {
        int small = i;
        for (int k =i+1; k< length; k++) {
            if (array[i] > array[k]) {
                small = k;
            }
        }
        if(small !=i){
            swap(&array[i], &array[small]);
        }
    }
    
    printf("Selection Sort:");
    for (int i = 0; i< length; i++) {
        printf("%d,", array[i]);
    }
    
}