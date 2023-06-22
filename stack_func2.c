#include "monty.h"
/**
 * Return: none
 * _swap - swap top of stack y second top stack
 * @line_number: line opcode occurs on
 * @stack: point the lists of monty stack
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *monty_runner;

	monty_runner = *stack;
	if (monty_runner == NULL || monty_runner->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = monty_runner->n;
	monty_runner->n = monty_runner->next->n;
	monty_runner->next->n = temp;
}

/**
 * Return: none
 * _add - add top of stack y second top stack
 * @line_number: the line opcode occurs on
 * @stack: point the lists for monty stack
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	int count = 0;
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (temp)
	{
		temp = temp->next;
		count++;
	}

	if (stack == NULL || (*stack)->next == NULL || count <= 1)
	{
		fprintf(stderr, "L%d: error, just dey play\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n + (*stack)->n;
	_pop(stack, line_number);

	(*stack)->n = sum;
}

/**
 * Return: none
 * _nop - nop top of stack y second top stack
 * @line_number: the line opcode occurs on
 * @stack: point the lists for monty stack
 */
void _nop(__attribute__ ((unused))stack_t **stack,
		__attribute__ ((unused)) unsigned int line_number)
{
	;
}

/**
 * Return: none
 * _pchar - prints the ASCII value of a number
 * @line_number: the index of the current line
 * @stack: pointer to the top of the stack
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int monty_value;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	monty_value = (*stack)->n;
	if (monty_value > 127 || monty_value < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	putchar(monty_value);
	putchar('\n');
}

/**
 * Return: 1 or 0 for yes and no
 * @c: int
 * _isalpha - checks if int is in alphabet
 */
int _isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	else
		return (0);
}
