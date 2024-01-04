#define _GNU_SOURCE
#include "monty.h"

unsigned int line_number = 0;

/**
 * main - Entry point of the Monty program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
    stack_t *stack = NULL;
    char *line = NULL;
    size_t len = 0;
    size_t read;
    FILE *file;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;
        parse_and_execute(&stack, line);
    }

    free_stack(&stack);
    free(line);
    fclose(file);
    exit(EXIT_SUCCESS);
}
