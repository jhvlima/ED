#ifndef STACK_H
#define STACK_H

// Node structure for the stack
typedef struct _Node Node;

// Stack structure
typedef struct _Stack Stack;

/**
 * @brief Pushes an element onto the stack.
 *
 * @param stack A pointer to the stack structure.
 * @param data The integer data to be pushed onto the stack.
 */
void push(Stack *stack, int data);

/**
 * @brief Pops an element from the stack.
 *
 * @param stack A pointer to the stack structure.
 * @return The integer data popped from the stack. Returns -1 if the stack is empty.
 */
int pop(Stack *stack);

/**
 * @brief Returns the top element of the stack without removing it.
 *
 * @param stack A pointer to the stack structure.
 * @return The integer data at the top of the stack. Returns -1 if the stack is empty.
 */
int peek(Stack *stack);

/**
 * @brief Checks if the stack is empty.
 *
 * @param stack A pointer to the stack structure.
 * @return 1 if the stack is empty, 0 otherwise.
 */
int isEmpty(Stack *stack);

#endif // STACK_H
