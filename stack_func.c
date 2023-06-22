#include "monty.h"
/**
 * @line_number: line opcode
 * _push - adding  to a stack
 * @stack: linked lists for monty stack
 */
void _push(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *at_top;
	(void)line_number;

	at_top = malloc(sizeof(stack_t));
	if (at_top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	at_top->n = var_global.push_arg;
	at_top->next = *stack;
	at_top->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = at_top;
	*stack = at_top;
}

/**
 * Return: none
 * _pall - printing all function
 * @line_number: line of opcode occurs on
 * @stack: point to linked list stack
 */
void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *monty_runner;

	monty_runner = *stack;
	while (monty_runner != NULL)
	{
		printf("%d\n", monty_runner->n);
		monty_runner = monty_runner->next;
	}
}

/**
 * Return: none
 * _pint - print int a top of stack
 * @line_number: line of opcode occurs on
 * @stack: point to linked list stack
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *monty_runner;

	monty_runner = *stack;
	if (monty_runner == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", monty_runner->n);
}

/**
 *Return: void
 * _pop - remove element a list
 *@line_number: integer
 *@stack: pointer to first node
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *monty_node = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = monty_node->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(monty_node);
}

/**
 * Return: none
 * @head: point the first node
 * free_dlistint - free a list
 */
void free_dlistint(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
