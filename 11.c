#include <stdio.h>
#include <stdlib.h>
#include "my.h"


int main() {
    int checker1 = 0;
    int checker2 = 0;
    char expression[50];
    struct queue my = {NULL, NULL};
    if (scanf("%[^\n]s", expression) != 1) {
        printf("N/A");
    } else {
        parse(expression, &my);
        struct queue polish = {NULL, NULL};
        struct queue stack = {NULL, NULL};
        while (my.head != NULL) {
            struct list *elem = dequeue(&my);
            if (elem -> node.code == 14 || elem -> node.code == 13) {
                enqueue_list(&polish, elem);
            } else  if (elem -> node.code == LEFTBR) {
                checker1++;
                enqueue_list(&stack, elem);
            } else if (elem -> node.code == RIGHTBR) {
                checker2++;
                while (stack.tail -> node.code != LEFTBR) {
                    struct list *tmp2 = pop(&stack);
                    enqueue_list(&polish, tmp2);
                }
                struct list *tmpLeftbr = pop(&stack);
                free(tmpLeftbr);
                free(elem);
            } else {
                while (stack.tail != NULL &&
                    (elem -> node.priority <= stack.tail -> node.priority)) {
                    struct list *tmp = pop(&stack);
                    enqueue_list(&polish, tmp);
                }
                enqueue_list(&stack, elem);
            }
        }
        while (stack.head != NULL) {
            struct list *tmp = pop(&stack);
            enqueue_list(&polish, tmp);
        }

        if (checker1 != checker2) {
            puts("wrong expression");
        } else {
            printf("last: %d\n", polish.tail -> node.code);
            printf("first: %d\n", polish.head -> node.code);
        }

    }


    return 0;
}

void parse(char *string, struct queue *my) {
    char *pr = string;
    while (*pr) {
        if (*pr == 'x')
            enqueue(my, VAR, 0, 0);
        if (*pr == '+')
            enqueue(my, PLUS, 0, LOW);
        if (*pr == '-')
            enqueue(my, MINUS, 0, LOW);
        if (*pr == '*')
            enqueue(my, MULT, 0, MEDIUM);
        if (*pr == '/')
            enqueue(my, DIV, 0, MEDIUM);
        if (*pr == '(')
            enqueue(my, LEFTBR, 0, 0);
        if (*pr == ')')
            enqueue(my, RIGHTBR, 0, 0);
        if (pr[0] == 's') {
            enqueue(my, SIN, 0, HIGHT);
        }
        if (pr[0] == 'c' && pr[1] == 'o' && pr[2] == 's') {
            enqueue(my, COS, 0, HIGHT);
            pr += 2;
        }
        if (pr[0] == 't' && pr[1] == 'a' && pr[2] == 'n') {
            enqueue(my, TAN, 0, HIGHT);
            pr += 2;
        }
        if (pr[0] == 'c' && pr[1] == 't' && pr[2] == 'g') {
            enqueue(my, CTG, 0, HIGHT);
            pr += 2;
        }
        if (pr[0] == 's' && pr[1] == 'q' && pr[2] == 'r' && pr[3] == 't') {
            enqueue(my, SQRT, 0, HIGHT);
            pr += 3;
        }
        if (pr[0] == 'l' && pr[1] == 'n') {
            enqueue(my, LN, 0, HIGHT);
            pr += 1;
        }

        if ((*pr > 47 && *pr < 58) || (*pr = '-' && *(pr - 1) == '(')) {
            enqueue(my, NUM, strtod(pr, &pr), 0);
            pr--;
        }

        pr += 1;
    }
}



