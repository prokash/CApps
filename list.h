//
// Created by prokash on 9/2/25.
//

#ifndef CAPPS_LIST_H
#define CAPPS_LIST_H
typedef int item;

typedef struct  _sl {
    item data;
    struct _sl *next;
}sl;

void sl_test();


typedef struct _dl {
    item data;
    struct _dl *next;
    struct _dl *prev;
}dl;

void dl_test();
#endif //CAPPS_LIST_H