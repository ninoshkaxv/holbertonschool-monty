#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: A pointer to the stack.
 * @argument: The argument to push onto the stack.
 */
void push(stack_t **stack, char *argument)
{
    stack_t *new_node;

    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = atoi(argument);
    new_node->next = *stack;
    *stack = new_node;
}

/**
 * pall - Prints all the values on the stack, starting from the top.
 * @stack: A pointer to the stack.
 */
void pall(stack_t *stack)
{
    while (stack)
    {
        printf("%d\n", stack->n);
        stack = stack->next;
    }
}

/**
 * pint - Prints the value at the top of the stack.
 * @stack: A pointer to the stack.
 */
void pint(stack_t *stack)
{
    if (stack)
        printf("%d\n", stack->n);
    else
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
}

/**
 * free_stack - Frees the stack.
 * @stack: A pointer to the stack.
 */
void free_stack(stack_t **stack)
{
    stack_t *temp;

    while (*stack)
    {
        temp = (*stack)->next;
        free(*stack);
        *stack = temp;
    }
}
