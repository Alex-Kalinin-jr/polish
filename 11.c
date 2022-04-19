#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
            struct queue newList = {NULL, NULL};
            double step = 2 * PI / 20;
            for (double y = 0; y <= 2*PI; y += step) {
                copy_queue(&polish, &newList);
                double res;
                int indicator = eval (&newList, y, &res);
                if (indicator == 1) {
                    puts("wrong expression");
                } else {
                    printf("the result of expression in point x = %lf: %lf\n", y, res);
                }

            }
        }

        destroy_queue(&polish);
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
        if (pr[0] == 's' && pr[1] == 'i' && pr[2] == 'n') {
            enqueue(my, SIN, 0, HIGHT);
            pr += 2;
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


int eval (struct queue *train, double x, double *result) {
    int res = 0;
    struct queue stack = {NULL, NULL};
    struct list *num1;
    while (train -> head != NULL) {
        struct list *elem = dequeue(train);
        if (elem -> node.code == 13) {
            enqueue_list(&stack, elem);
        } else if (elem -> node.code ==14) {
            elem -> node.number = x;
            enqueue_list(&stack, elem);
        } else {
            switch (elem -> node.code) {
                case PLUS: {
                    num1 = pop(&stack);
                    stack.tail -> node.number += num1 -> node.number;
                    free(num1);
                    free(elem);
                    break;
                }
                case MINUS: {
                    num1 = pop(&stack);
                    stack.tail -> node.number -= num1 -> node.number;
                    free(num1);
                    free(elem);
                    break;
                }
                case MULT: {
                    num1 = pop(&stack);
                    stack.tail -> node.number *= num1 -> node.number;
                    free(num1);
                    free(elem);
                    break;
                }
                case DIV: {
                    num1 = pop(&stack);
                    stack.tail -> node.number /= num1 -> node.number;
                    free(num1);
                    free(elem);
                    break;
                }
                case SIN: {
                    stack.tail -> node.number = sin(stack.tail -> node.number);
                    free(elem);
                    break;
                }
                case COS: {
                    stack.tail -> node.number = cos(stack.tail -> node.number);
                    free(elem);
                    break;
                }
                case TAN: {
                    stack.tail -> node.number = tan(stack.tail -> node.number);
                    free(elem);
                    break;
                }
                case CTG: {
                    stack.tail -> node.number = 1 / tan(stack.tail -> node.number);
                    free(elem);
                    break;
                }
                case SQRT: {
                    double k = stack.tail -> node.number;
                    stack.tail -> node.number = sqrt(k);
                    free(elem);
                    break;
                }
                case LN: {
                    stack.tail -> node.number = log(stack.tail -> node.number);
                    free(elem);
                    break;
                }
            }
        }
    }
    if (stack.tail != stack.head) {
        res = 1;
    } else {
        *result = stack.head -> node.number;
    }
    num1 = dequeue(&stack);
    free(num1);
    return res;
}



            // printf("last: %d\n", polish.tail -> node.code);
            // printf("sec: %d\n", polish.head -> next -> node.code);
            // printf("first: %d\n", polish.head -> node.code);