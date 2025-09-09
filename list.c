//
// Created by prokash on 9/2/25.
//

#include "list.h"

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

sl *sl_new(item data) {
    sl *s = malloc(sizeof(sl));
    assert(s !=NULL);
    s->data = data;
    s->next = NULL;
    return s;
}

void sl_free(sl *s) {
    free(s);
}

void sl_print(sl *s) {
    printf("%d\n", s->data);
}

//=>at the end, head not changed
void sl_append(sl *s, item data) {
    sl *t = s;
    while (t->next != NULL) {
        t = t->next;
    }
    t->next = sl_new(data);

}
void sl_print_all(sl *s) {
    sl *t = s;
    printf("print all elm of list:\n");
    while (t != NULL) {
        sl_print(t);
        t = t->next;
    }
}
void sl_destroy(sl *s) {
    sl *t = s;
    while (t != NULL) {
        printf("data %d\n", t->data);
        sl *next = t->next;
        sl_free(t);
        t = next;
    }
}


sl* push(sl *s, item data) {
    sl *t = sl_new(data);
    t->next = s; //-> puh it on the head of the list
    return t;
}

//-> pop from the head of the list
sl* pop(sl *s) {
    sl *t = s;
    if (t == NULL) {
        return NULL;
    }
    sl *next = t->next;
    sl_free(t);
    return next;
}
//-> recursive (data is given )
void sl_delete(sl *s, item data) {
    sl *t = s;
    if (t == NULL) {
        return;
    }
    //Can not use pop
    if (t->data == data) {
        s = pop(s);
        return;
    }
    sl_delete(t->next, data);
}
//-> given a node pointer
void sl_delete_node(sl *s, sl *node) {
    if (s == NULL) {
        return;
    }
    if (s == node) {
        s = pop(s);
        return;
    }
    sl_delete_node(s->next, node);
}

void middle (sl *s) {
    assert(s && s->next);
    sl* slow = s;
    sl* fast = s->next;
    while (slow && fast) {
        slow = slow->next;
        if (fast->next)
            fast = fast->next->next;
        else break;
    }
    printf("Middle of s = %d\n", slow->data);
}

void sl_test() {
    sl *s = sl_new(1);
    sl_append(s, 2);
    sl_append(s, 3);
    sl_append(s, 4);
    sl_append(s, 5);
    sl_print_all(s);

    middle(s);

   //- need work sl_delete(s, 4);
    sl_print_all(s);
    middle(s);
    sl_destroy(s);
}

//-----------------------------------------------
//--------------- dl starts ---------------------
//---------------------------------------------

dl *dl_new(item data) {
    dl *node = malloc(sizeof(dl));
    assert(node !=NULL);
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void dl_free(dl *node) {
    free(node);
}

void dl_print(dl *node) {
    if (node->prev ) printf("prev = %d  ", node->prev->data);
    printf("%d\n", node->data);
}

//=>at the end, head not changed
void dl_append(dl *node, item data) {
    dl *t = node;
    while (t->next != NULL) {
        t = t->next;
    }
    // <t->next is null => t is end of list
    t->next = dl_new(data);
    t->next->prev = t;

}
void dl_print_all(dl *s) {
    dl *t = s;
    printf("print all elm of dl list:\n");
    while (t != NULL) {
        dl_print(t);
        t = t->next;
    }
}
void dl_destroy(dl *node) {
    dl *t = node;
    while (t != NULL) {
        printf("data %d\n", t->data);
        dl *next = t->next;
        dl_free(t);
        t = next;
    }
}


dl* dl_push(dl *node, item data) {
    dl *t = dl_new(data);
    t->next = node; //-> push it on the head of the list
    return t;
}

void dl_init(dl *h) {
    assert(h);
    h = dl_new(1);
    dl_append(h, 2);
    dl_append(h, 3);
    dl_append(h, 4);
    dl_append(h, 5);
    dl_print_all(h);

}

void dl_test() {
    dl *h;
    dl_init(h);
}