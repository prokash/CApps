//
// Created by prokash on 9/2/25.
//

#include "arr.h"

#include <stddef.h>
#include <limits.h>
#include <stdio.h>

int second_largest(int *arr, int size) {
    if ( arr == NULL) return INT_MIN;

    int max = INT_MIN, second_max = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            second_max = max;
            max = arr[i];
        }else if (arr[i] > second_max && arr[i] != max) {
            second_max = arr[i];
        }
    }
    return second_max;
}

int third_largest(int *arr, int size) {
    if ( arr == NULL) return INT_MIN;
    //-> get the second max first
    //-> do the second max, but ignore anything greater than second max
    //->simpler approach follows from geeksforgeeks

}
// C++ program to find the third largest
// element in an array.
#include <stdio.h>

int thirdLargest(int *arr, int size) {
    int n = size;

    // Find the first maximum element.
    int first = INT_MIN;
    for (int i=0; i<n; i++) {
        if (arr[i] > first) first = arr[i];
    }

    // Find the second max element.
    int second = INT_MIN;
    for (int i=0; i<n; i++) {
        if (arr[i] > second && arr[i] < first) {
            second = arr[i];
        }
    }

    // Find the third largest element.
    int third = INT_MIN;
    for (int i=0; i<n; i++) {
        if (arr[i] > third && arr[i] < second) {
            third = arr[i];
        }
    }

    // Return the third largest element
    return third;
}

int array_main() {
    int arr[] = {1, 14, 2, 16, 10, 20};

    printf(" thirdLargest %d\n" , thirdLargest(arr, 6));

    return 0;
}