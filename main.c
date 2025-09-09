#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "sometests.h"
#include "Q.h"
#include "str.h"
#include "list.h"
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

//    avgOf2(7,7);
    return 0;
}

int __atoi(char* s) {
    assert(s !=NULL);
    int result = 0;
    printf ("s=%s\n", s);
    for (int i=0; s[i] >='0' && s[i] <= '9'; i++){
        result = result * 10 + (s[i] - '0');
    }
    printf("result = %d\n", result);
    return result;
}

int revserse_int( int n) {
    printf(" reverse_int n = %d\n", n);
    int r = 0;
    while (n) {
        r = r*10 + n%10;
        n = n / 10;
    }
    printf(" reverse_int r = %d\n", r);
    return r;
}
//- int -> char*
/*
*Why it works: An int is typically 32 bits (max value ~2 billion,
*10 digits) or 64 bits (max value ~18 quintillion, 19 digits).
*Multiplying the byte size by 3 provides a safe upper bound
*for the number of decimal digits.

The "+ 2": One extra byte for the possible negative sign (-) and
*/

char * __itoa( int n)
{
    printf("__itoa n= %d\n", n);
    bool minus = false;
    bool right_0 = false;
    if ( n < 0) minus = true;
    if (minus) n = -n;
    if ( n % 10 == 0) right_0 = true;
    /* reverse n */
    n = revserse_int(n); /* zero on the right side will be lost */
    printf(" __itoa reversed n=%d\n", n);

    char buffer[sizeof(int) * 3 + 2];
    int idx = 0;
    if (minus) buffer[idx++] = '-';
    while (n) {
        buffer[idx++] =  n%10 + '0';
        n = n / 10 ;
    }
    if (right_0) buffer[idx++] = '0';
    buffer[idx]= '\0';

    printf("__itoa buffer=%s\n", buffer);

}
int main() {

    __atoi("987654320");

    //
    __itoa(987654320);
    __itoa(-987654320);

    str_test();

  ///  sl_test();
    //sometests_main();

    dl_test();
    return 0;
};