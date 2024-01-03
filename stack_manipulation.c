#include "monty.h"
#include <ctype.h>


/**
 * f_push - Pushes an element onto the stack.
 * @stack: A pointer to the stack.
 * @argument: The argument to push onto the stack.
 */
void f_push(stack_t **stack, char *argument)
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
 * f_pall - Prints all the values on the stack, starting from the top.
 * @stack: A pointer to the stack.
 */
void f_pall(stack_t *stack)
{
    while (stack)
    {
        printf("%d\n", stack->n);
        stack = stack->next;
    }
}

/**
 * f_pint - Function to perform pint operation.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the Monty bytecode file.
 */
void f_pint(stack_t **stack, unsigned int line_number)
{
    if (*stack)
        printf("%d\n", (*stack)->n);
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

/**
 * is_numeric - Checks if a string is a numeric value.
 * @str: The string to check.
 * Return: 1 if numeric, 0 otherwise.
 */
int is_numeric(const char *str)
{
    if (str == NULL || *str == '\0')
        return 0;

    while (*str)
    {
        if (!isdigit(*str))
            return 0;
        str++;
    }

    return 1;
}

/**
 * parse_and_execute - Parse and execute Monty bytecode instructions.
 * @stack: Double pointer to the beginning of the stack.
 * @line: String containing the Monty bytecode instruction.
 */
void parse_and_execute(stack_t **stack, char *line)
{
    unsigned int line_number = 0;
	char *instruction, *argument;
    #define DELIMITERS " \t\n"

    instruction = strtok(line, DELIMITERS);
    if (!instruction)
        return;

    argument = strtok(NULL, DELIMITERS);

    if (strcmp(instruction, "push") == 0)
    {
        if (!argument || !is_numeric(argument))
        {
           fprintf(stderr, "L%u: usage: push integer\n", line_number);
		   exit(EXIT_FAILURE);
        }
        f_push(stack, argument);
    }
    else if (strcmp(instruction, "pall") == 0)
    {
        f_pall(*stack);
    }
    // Add more cases for other instructions...

    #undef DELIMITERS
}
