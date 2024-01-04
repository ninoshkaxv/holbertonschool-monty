#include "monty.h"

/**
 * f_pop - Removes the top element of the stack.
 * @stack: A pointer to the stack.
 */
void f_pop(stack_t **stack, unsigned int line_number)
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
 * f_swap - Swaps the top two elements of the stack.
 * @stack: A pointer to the stack.
 */
void f_swap(stack_t **stack, unsigned int line_number)
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
 * f_add - Adds the top two elements of the stack.
 * @stack: A pointer to the stack.
 */
void f_add(stack_t **stack, unsigned int line_number)
{
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;
    f_pop(stack, line_number);
}
