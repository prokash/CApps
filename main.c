#include <stdio.h>
#include <assert.h>
#include "sometests.h"
#include "Q.h"
//-- Pointrs on C book pp 195
//- depends on what we passed -- Warnning shold show up
//- should be array[] , let the compiler handle the size
//- also we should calculate the size of the array like
//- int sz = sizeof(A) / sizeof(A[0]

//- to avoid warning disable this function
#define DISABLE_CODE
#ifdef DISABLE_CODE
int find_max(int array[10]) {
    int i;
    int max = array[0];
    for (i = 1; i < 10; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}
#endif

int correct_find_max(int array[], int len) {
    int i;
    // check for null pointer
    if (array == NULL) { printf("Array is null"); return -1;}
    assert ( len > 0);
    int max = array[0];
    for (i = 1; i < len ; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}
//- fibonnaci counter
int fibcounter ;

long fib(int n) {
    fibcounter++;
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int main_fib() {

    for ( int i = 0; i < 10; i++) {
        fib(i);
        printf("Fibonacci counter[%d]: %d\n", i, fibcounter);
        fibcounter = 0;
    }
}
int main_faulty_max () {

    printf("Hello, Faulty World!\n");
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int Array[5] = {1,2,3,4,5};
    //printf("Max: %d\n", find_max(Array));
    int len = sizeof(Array) / sizeof(Array[0]);
    printf("Max: %d\n", correct_find_max(Array, len));
}
int sometests_main(void) {
     Q_test() ;
    printf("Hello, Faulty World!\n");
    main_fib();
    main_faulty_max();

    avgOf2(7,7);
    return 0;
}

int main() {

    sometests_main();
    return 0;
};