#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    Stack stack;
    stack.top = NULL;

    printf("Pushing elements 10, 20, 30 onto the stack...\n");
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element is %d\n", peek(&stack));

    printf("Popped element is %d\n", pop(&stack));
    printf("Top element is now %d\n", peek(&stack));

    printf("Popping all elements:\n");
    while (!isEmpty(&stack))
    {
        printf("Popped element is %d\n", pop(&stack));
    }

    return 0;
}
