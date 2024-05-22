#ifndef STACK_H
#define STACK_H

// Node structure for the stack
typedef struct _Node Node;

// Stack structure
typedef struct _Stack Stack;

/**
 * @brief Creates a new stack.
 * 
 * @return A pointer to the newly created stack.
 */
Stack* createStack();

/**
 * @brief Destroys the stack and frees all allocated memory.
 * 
 * @param stack A pointer to the stack structure.
 */
void destroyStack(Stack* stack);

/**
 * @brief Pushes an element onto the stack.
 *
 * @param stack A pointer to the stack structure.
 * @param data The string data to be pushed onto the stack.
 */
void push(Stack *stack, char *data);

/**
 * @brief Pops an element from the stack.
 *
 * @param stack A pointer to the stack structure.
 * @return The string data popped from the stack. Returns NULL if the stack is empty.
 */
char *pop(Stack *stack);

/**
 * @brief Checks if the stack is empty.
 *
 * @param stack A pointer to the stack structure.
 * @return 1 if the stack is empty, 0 otherwise.
 */
int isEmpty(Stack *stack);

#endif // STACK_H
