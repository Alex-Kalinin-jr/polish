#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void enqueue(struct queue *train, int id, double num, int precedence) {
    struct list *tmp = (struct list *)malloc(sizeof(struct list));
    tmp -> next = NULL;
    tmp -> node.code = id;
    tmp -> node.number = num;
    tmp -> node.priority = precedence;

    if (train -> head == NULL) {
        train -> head = tmp;

    } else {
        train -> tail -> next = tmp;
    }

    train -> tail = tmp;
}

void enqueue_list(struct queue *train, struct list *tmp) {
    if (train -> head == NULL) {
        train -> head = tmp;

    } else {
        train -> tail -> next = tmp;
    }

    train -> tail = tmp;
}

struct list *dequeue (struct queue *train) {
    struct list *ret = train -> head;
    if (train -> head == train -> tail) {
        train -> head = NULL;
        train -> tail = NULL;
    } else {
        train -> head = train -> head -> next;
    }
    ret -> next = NULL;
    return ret;
}

struct list *pop (struct queue *train) {
    struct list *ret = train -> tail;
    struct list *tmp = train -> head;
    if (train -> head == train -> tail) {
        train -> head = NULL;
        train -> tail = NULL;
    } else {
        while (tmp -> next -> next != NULL) {
            tmp = tmp -> next;
        }
        tmp -> next = NULL;
        train -> tail = tmp;
    }

    ret -> next = NULL;
    return ret;
}


// void destroy_queue(struct queue *train) {
//     while (train -> next) {
//         struct queue *tmp = train;
//         while (tmp -> next) {
//             tmp = tmp -> next;
//         }
//         free(tmp);
//     }
//     free(train -> head);
// }