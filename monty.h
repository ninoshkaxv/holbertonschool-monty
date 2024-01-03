#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIMITERS " \n\t\r"

/* Define the structure for the stack */
typedef struct stack_s
{
    int n;
    struct stack_s *next;
} stack_t;

/* Function prototypes */
void parse_and_execute(stack_t **stack, char *line);
void execute_instruction(stack_t **stack, char *instruction, char *argument);
void push(stack_t **stack, char *argument);
void pall(stack_t *stack);
void pint(stack_t *stack);
void pop(stack_t **stack);
void swap(stack_t **stack);
void add(stack_t **stack);
void nop(stack_t **stack);
void free_stack(stack_t **stack);

#endif /* MONTY_H */
