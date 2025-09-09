//
// Created by prokash on 9/1/25.
//
#include <stdio.h>
#include "sometests.h"
#include "Q.h"

int avgOf2(int a, int b) {
    float x = a;
    float y = b;
    int ok = (int) ((x/2) + ( y/2) ); //
    printf("OK avgof2(%d,%d)= %d\n", a, b, ok );
    int notok = a/2 + b/2;
    printf("NotOK avgof2(%d,%d)= %d\n", a, b, notok );

}

