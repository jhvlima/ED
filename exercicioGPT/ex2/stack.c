#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the stack
struct _Node
{
    char *data;
    Node *next;
};

// Stack structure
struct _Stack
{
    Node *top;
};

/**
 * @brief Creates a new stack.
 * 
 * @return A pointer to the newly created stack.
 */
Stack* createStack()
{
    Stack *s = calloc(1, sizeof(Stack));
    s->top = NULL;
    return s;
}

/**
 * @brief Pushes an element onto the stack.
 * 
 * @param stack A pointer to the stack structure.
 * @param data The string data to be pushed onto the stack.
 */
void push(Stack *stack, char *data)
{
    Node *no = calloc(1, sizeof(Node));
    no->data = data;
    no->next = stack->top;
    stack->top = no;
}

/**
 * @brief Pops an element from the stack.
 * 
 * @param stack A pointer to the stack structure.
 * @return The string data popped from the stack. Returns NULL if the stack is empty.
 */
char* pop(Stack* stack)
{
    Node *topo = stack->top;
    if (!isEmpty(stack))
    {
        stack->top = stack->top->next;
        char *string = topo->data;
        free(topo);
        return string;
    }
    return NULL;
}

/**
 * @brief Checks if the stack is empty.
 * 
 * @param stack A pointer to the stack structure.
 * @return 1 if the stack is empty, 0 otherwise.
 */
int isEmpty(Stack* stack)
{
    if (stack->top)
    {
        return 0;
    }
    return 1;
}

/**
 * @brief Destroys the stack and frees all allocated memory.
 * 
 * @param stack A pointer to the stack structure.
 */
void destroyStack(Stack* stack)
{
    while (!isEmpty(stack))
    {
        free(pop(stack));
    }
    free(stack);
}