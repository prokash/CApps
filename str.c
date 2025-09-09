//
// Created by prokash on 9/2/25.
//

#include "str.h"

#include <stdio.h>

int str_len(char *s) {
    char *p = s;
    //printf("*p=%c\n", *p);
    while (*p++) {
       // printf("*p=%c\n", *p);
    };
    printf("p=%c, s=%p\n", *p, s);
    return p - s -1;
}

void str_cp_verbose(char *dest, char *src) {
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
}
void str_cp(char *dest, char *src) {
    while (*dest++ = *src++);

}
int str_cmp(char *s1, char *s2) {
    while (*s1++  == *s2++) {
        if (*(s1-1) == '\0') return 0;
    }
    return *s1 - *s2;
}
void str_test () {
    char s[6] = {'h','e', 'l', 'l', 'o','\0'}; //hello";
    char t[6] = {'w', 'o','r', 'l', 'd', '\0'}; //"world";

    printf("s=%s  t=%s\n", s, t);
    //-cp
    str_cp(s, t);
    printf("%s  %s\n", s, t);
    //- cmp
    int result = str_cmp(s,t);
    printf("str_cmp result=%d\n", result);
    //-len
    printf("len of s str %d\n", str_len(s));
}