#include "monty.h"

/**
 * Return: none
 * _pstr - mod top of stack y second top stack
 * @line_number: line opcode occurs on
 * @stack: point the lists for monty stack
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	int count = 0;
	stack_t *temp = *stack;


	(void)line_number;

	while (temp)
	{
		count = temp->n;
		if (count == 0 || _isalpha(count) == 0)
			break;
		putchar(count);
		temp = temp->next;
	}
	putchar('\n');
}

/**
 * Return: none
 * _rotl - top of stack y second top stack
 * @line_number: line opcode occurs on
 * @stack: point the lists for monty stack
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	int monty_aux1 = 0;
	stack_t *monty_runner = *stack;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	monty_aux1 = monty_runner->n;

	while (monty_runner->next)
	{
		monty_runner = monty_runner->next;
		monty_runner->prev->n = monty_runner->n;
	}

	monty_runner->n = monty_aux1;
}

/**
 * Return: none
 * _rotr - mod top of stack y second top stacks
 * @line_number: number of line opcode occurs on
 * @stack: pointer to lists for monty stack
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	int monty_aux1 = 0;
	stack_t *monty_runner = *stack;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	while (monty_runner->next)
		monty_runner = monty_runner->next;

	monty_aux1 = monty_runner->n;

	while (monty_runner->prev)
	{
		monty_runner = monty_runner->prev;
		monty_runner->next->n = monty_runner->n;
	}

	monty_runner->n = monty_aux1;
}
