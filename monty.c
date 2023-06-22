#include "monty.h"
global_var var_global;
/**
 * Return: 0
 * main - monty program
 * @av: opcode file
 * @ac: arguments
 */
int main(int ac, char **av)
{
	stack_t *stack;

	stack = NULL;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE:\n");
		exit(EXIT_FAILURE);
	}

	read_file(av[1], &stack);

	free_dlistint(stack);
	return (0);
}
