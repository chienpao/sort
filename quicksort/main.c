//
//  main.c
//  quicksort
//
//  Created by Chien-Pao Chueh on 12/30/14.
//  Copyright (c) 2014 Chien-Pao Chueh. All rights reserved.
//

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, const char * argv[]) {
    int array[] = {1,2,3,44,23,9,4,2,3};
    int length = sizeof(array)/sizeof(int);
    for (int i = 0; i< length-1; i++) {
        for (int k =i+1; k< length; k++) {
            if (array[i] > array[k]) {
                swap(&array[i], &array[k]);
            }
        }
    }

    for (int i = 0; i< length; i++) {
        printf("%d\n", array[i]);
    }
    
    return 0;
}

