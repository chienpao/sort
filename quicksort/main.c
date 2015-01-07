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
void insertionSort(int , int *);
void quickSort(int *, int, int);

int main(int argc, const char * argv[]) {
    int array[] = {10,2,3,44,23,9,4,2,3};
    int length = sizeof(array)/sizeof(int);
    //exchangeSort(length, array);
    //selectionSort(length, array);
    //insertionSort(length, array);
    
    int left = 0;
    int right = 0;
    right = length;
    //printf("%d\n", length);
    //printf("%d\n", right);
    quickSort(array, left, right);
    
    printf("Sort Result:");
    for (int i = 0; i< length; i++) {
        printf("%d,", array[i]);
    }
    
    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *array, int left, int right){
    int i = left;
    int j = right;
    int pivot = array[left];
    
    while (1) {
        do{++i;} while(array[i]<=pivot && i <=right);
        do{--j;} while(array[j]>pivot);
        if(i>=j)break;
        swap(&array[i], &array[j]);
    }
    swap(&array[left], &array[j]);
    return j;
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
void insertionSort(int length, int *array){
    int i, k;
    //大的往右邊搬
    for (i = 1; i< length; i++) {
        int temp = array[i];
        for (k = i-1 ; k >=0 && array[k] > temp; --k) {
            array[k+1] = array[k];
        }
        array[k+1] = temp;
    }
    
    printf("Insertion Sort:");
    for (int i = 0; i< length; i++) {
        printf("%d,", array[i]);
    }
    
}
void quickSort(int *array, int left, int right){
    int temp = 0;
    if(left < right){
        temp = partition(array, left, right);
        quickSort(array, left, temp-1);
        quickSort(array, temp+1, right);
    }
}