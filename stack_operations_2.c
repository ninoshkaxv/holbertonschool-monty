#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: A pointer to the stack.
 */
void nop(stack_t **stack)
{
    (void)stack; /* Avoid compiler warning for unused parameter */
}

/**
 * free_stack - Frees the stack.
 * @stack: A pointer to the stack.
 */
void free_stack(stack_t **stack)
{
    free_stack(stack);
}

