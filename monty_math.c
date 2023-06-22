#include "monty.h"
/**
 * _sub - sub top of stack second top stack
 * @stack: point the lists of monty stack
 * @line_number: number of line opcode occurs
 * Return: none
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int sub = 0, index = 0;
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (temp)
	{
		temp = temp->next;
		index++;
	}

	if (stack == NULL || (*stack)->next == NULL || index <= 1)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sub = (*stack)->next->n - (*stack)->n;
	_pop(stack, line_number);

	(*stack)->n = sub;
}

/**
 * Return: none
 * _mul - mul stack
 * @line_number: line opcode occurs on
 * @stack: pointer to  stack
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int aeux;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		aeux = (*stack)->n;
		_pop(stack, line_number);
		(*stack)->n *= aeux;
	}
}

/**
 * Return: none
 * _div - div  second top stack
 * @line_number:  occurs on
 * @stack: for monty stack
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int division;

	division = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		division = (*stack)->n;
		_pop(stack, line_number);
		(*stack)->n /= division;
	}
}

/**
 * Return: non
 * _mod - stack y second top stack
 * @line_number: number occurs on
 * @stack: pointer lists
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int mode;

	mode = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		mode = (*stack)->n;
		_pop(stack, line_number);
		(*stack)->n %= mode;
	}
}
