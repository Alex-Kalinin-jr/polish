#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int main() {
    char expression[50];
    struct queue my = {NULL, NULL};


    if (scanf("%s", expression) != 1) {
        printf("N/A");
    } else {
        parse(expression, &my);


    }


    return 0;
}

void parse(char *string, struct queue *my) {
    char *pr = string;
    while (*pr) {
        if (*pr == '+') {
            enqueue(my, PLUS, 0, LOW);
        }
        if ((pr[0] > 47 && pr[1] < 58) || (pr[0] = '-' && *(pr - 1) == '('))
            enqueue(my, NUM, strtod(pr, &pr), 0);
        if (*pr == '-' && !(*(pr + 1) > 48 && *(pr + 1) < 58))
            enqueue(my, MINUS, 0, LOW);
        if (*pr == '*')
            enqueue(my, MULT, 0, MEDIUM);
        if (*pr == '/')
            enqueue(my, DIV, 0, MEDIUM);
        if (*pr == '(')
            enqueue(my, LEFTBR, 0, 0);
        if (*pr == ')')
            enqueue(my, RIGHTBR, 0, 0);
        if (pr[0] == 'S' && pr[1] == 'I' && pr[2] == 'N')
            enqueue(my, SIN, 0, HIGHT);
        if (pr[0] == 'C' && pr[1] == 'O' && pr[2] == 'S')
            enqueue(my, COS, 0, HIGHT);
        if (pr[0] == 'T' && pr[1] == 'A' && pr[2] == 'N')
            enqueue(my, TAN, 0, HIGHT);
        if (pr[0] == 'C' && pr[1] == 'T' && pr[2] == 'G')
            enqueue(my, CTG, 0, HIGHT);
        if (pr[0] == 'S' && pr[1] == 'Q' && pr[2] == 'R' && pr[3] == 'T')
            enqueue(my, SQRT, 0, HIGHT);
        if (pr[0] == 'L' && pr[1] == 'N')
            enqueue(my, LN, 0, HIGHT);
        if (pr[0] == 'x')
            enqueue(my, VAR, 0, 0);
        pr++;
    }
}


    // struct queue my = {NULL, NULL};
    // enqueue(&my, 0, 23, 1);
    // enqueue(&my, 0, 24, 1);
    // enqueue(&my, 0, 25, 1);
    // enqueue(&my, 0, 26, 1);

    // printf("%f", my.head -> node.number);
    // printf("%f", my.tail -> node.number);

    // struct list *a = deque(&my);
    // printf("\n%f\n", a -> node.number);
    // printf("%f", my.head -> node.number);
    // printf("%f", my.tail -> node.number);