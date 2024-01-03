#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the structure for the stack */
typedef struct stack_s
{
    int n;
    struct stack_s *next;
} stack_t;

/* Function prototypes */
void parse_and_execute(stack_t **stack, char *line);
void execute_instruction(stack_t **stack, char *instruction, char *argument);
void f_push(stack_t **stack, char *argument);
void f_pall(stack_t *stack);
void f_pint(stack_t **stack, unsigned int line_number);
void f_pop(stack_t **stack, unsigned int line_number);
void f_swap(stack_t **stack, unsigned int line_number);
void f_add(stack_t **stack, unsigned int line_number);
void f_nop(stack_t **stack);
void free_stack(stack_t **stack);
int is_numeric(const char *str);
#endif /* MONTY_H */
