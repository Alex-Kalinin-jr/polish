# EVALUATING EXPRESSION USING REVERSED POLISH NOTATION

## Description
This program parses expression from stdin and evaluates it in interval (-2pi; 2pi) using reverse polish notation.

## Implementation
- The program recieves a string with variable from input(stdin);
- The string is parsed into linked list (queue) of blocks;
- Linked list is converted into another linked list. Reordering of blocks takes place during the process. Reordering happens in accordance with     Reverse Polish Notation (RPN) by using of Dejkstra algoritm.
- Then evaluation of expression proceeds by using of RPN rules for several points.

## Notes
- program distinushes the next actions: +, -, *, /, sin, cos, tan, ctg, sqrt, ln
- variable should be written as 'x':
> sin(x), sinx, sin x, 35*(cos(tan(sqrt(x+2)))) etc..
**Attention!** program does not distinguish unary minus. I was lazy.
- in the case of incorrect symbols programm just pass them:
> sindhfg(x) ------> sin(x)
- in the case of wrong expression the program will inform about this:
> sin(x ------> "wrong expression"
> 34 +* x ------> "wrong expression"
- for the sake of portability such amenities as clearscreen were not implemented.
- leaks were checked using Valgrind.

## Take care
This is a dummy project presented just to show skills of using stacks, queues, general C-language skills and my code style. It is not for practical usage.





