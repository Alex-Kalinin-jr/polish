#ifndef SRC_STRUCTURES_H_
#define SRC_STRUCTURES_H_

#define LOW 1
#define MEDIUM 2
#define HIGHT 3

enum input_type {EMPTY_STACK, PLUS, MINUS, MULT, DIV,
                LEFTBR, RIGHTBR, SIN, COS, TAN, CTG, SQRT,
                LN, NUM, VAR
                }input;

struct item {
    int code;
    double number;
    int priority;
};

struct list {
    struct item node;
    struct list *next;
};

struct queue {
    struct list *head;
    struct list *tail;
};

void enqueue(struct queue *train, int id, double num, int precedence);
void enqueue_list(struct queue *train, struct list *tmp);
struct list *dequeue (struct queue *train);
struct list *pop (struct queue *train);


void parse(char *string, struct queue *my);

#endif  // SRC_STRUCTURES_H_