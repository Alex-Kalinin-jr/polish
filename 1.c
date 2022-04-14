#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "structures.h"

void enqueue(struct queue *qu, int code, float number, int priority) {
    struct list *tmp = (struct list *) malloc(sizeof(struct list));
    tmp->next = NULL;
    tmp->item.code = code;
    tmp->item.number = number;
    tmp->item.priority = priority;

    if (qu->tail != NULL)
        qu->tail->next = tmp;
    qu->tail = tmp;
    if (qu->head == NULL)
        qu->head = tmp;
}

struct item dequeue(struct queue *qu) {
    struct item result = {0, 0, 0};
    if (qu->head != NULL) {
        result.code = qu->head->item.code;
        result.number = qu->head->item.number;
        result.priority = qu->head->item.priority;

        struct list *tmp = qu->head;
        qu->head = tmp->next;
        free(tmp);
    }
    return result;
}

struct item pop(struct list **stack) {
    struct item result = {0, 0, 0};
    if (*stack !=NULL) {
        struct list *tmp = *stack;
        result.code = tmp->item.code;
        result.number = tmp->item.number;
        result.priority = tmp -> item.priority;
        *stack = tmp->next;
        free(tmp);
    }
    return result;
}