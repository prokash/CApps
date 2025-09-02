//
// Created by prokash on 9/2/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Q.h"

static int Qsize, head, tail;
static int *Q = NULL;
void Qinit( int MaxSize) {

    Qsize = MaxSize + 1;
    Q = malloc((MaxSize+1) * sizeof(int)); // allocate one more than requested size
    assert(Q != NULL);
    head = Qsize; tail = 0;

}
//check
int Qempty() {
    return (head % Qsize == tail);
}
//check
int Qfull() {
    printf("head=%d tail=%d\n", head, tail);
    return (tail+1  == head  );
}

void Qput(int item) {
    Q[tail] = item;
    tail = (tail + 1) % Qsize;
}
int Qget() {
    int item = Q[head%Qsize];
    head = (head + 1) % Qsize;
    return item;
}

void Qdestroy() {
    free(Q);
}

void Qprint() {
    for (int i = 0; i < Qsize; i++) {
        printf("%d ", Q[i]);
    }
    printf("\n");
}

void Q_test() {
    Qinit(10);
    Qput(1);
    Qput(2);
    Qput(3);
    Qput(4);
    Qput(5);
    Qput(6);
    Qput(7);
    Qput(8);
    Qput(9);
    Qput(10);

    Qprint();
    assert(Qempty() == 0);  // should not be empty
    assert(Qfull() == 1);   // should  be full



    assert(Qget() == 1);
    assert(Qget() == 2);
    assert(Qget() == 3);
    assert(Qget() == 4);
    assert(Qget() == 5);
    assert(Qget() == 6);
    assert(Qget() == 7);
    assert(Qget() == 8);
    assert(Qget() == 9);
    assert(Qget() == 10);
    assert(Qempty() == 1);  // should be empty
    Qprint();
    Qdestroy();
}