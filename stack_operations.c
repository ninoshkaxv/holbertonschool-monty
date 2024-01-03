#include "monty.h"

/**
 * pop - Removes the top element of the stack.
 * @stack: A pointer to the stack.
 */
void pop(stack_t **stack)
{
    stack_t *temp;

    if (!*stack)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->next;
    free(*stack);
    *stack = temp;
}

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: A pointer to the stack.
 */
void swap(stack_t **stack)
{
    int temp;

    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}

/**
 * add - Adds the top two elements of the stack.
 * @stack: A pointer to the stack.
 */
void add(stack_t **stack)
{
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;
    pop(stack);
}

