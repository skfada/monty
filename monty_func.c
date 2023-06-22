#include "monty.h"
/**
 * Return: none
 * read_file - reads  file and runs commands
 * @stack: the top of the stack pointer to
 * @filename: file pathname
 */
void read_file(char *filename, stack_t **stack)
{
	int status;
	int reader;
	char *line;
	size_t i = 0;
	int line_count = 1;
	instruct_func s;

	var_global.file = fopen(filename, "r");

	if (var_global.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((reader = getline(&var_global.buffer, &i, var_global.file)) != -1)
	{
		line = parse_line(var_global.buffer, stack, line_count);
		if (line == NULL || line[0] == '#')
		{
			line_count++;
			continue;
		}
		s = get_op_func(line);
		if (s == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_count, line);
			exit(EXIT_FAILURE);
		}
		s(stack, line_count);
		line_count++;
	}
	free(var_global.buffer);
	status = fclose(var_global.file);
	if (status == -1)
		exit(-1);
}

/**
 * Return:  NULL on failure returns a functions,
 * get_op_func - returns the correct function
 * @str: the opcode
 */
instruct_func get_op_func(char *str)
{
	int count;

	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL},
	};

	count = 0;
	while (instruct[count].f != NULL && strcmp(instruct[count].opcode, str) != 0)
	{
		count++;
	}

	return (instruct[count].f);
}

/**
 * Return: returns 1 or 0
 * @str: string being passed
 * isnumber - checks if is a number
 */
int isnumber(char *str)
{
	unsigned int count;

	if (str == NULL)
		return (0);
	count = 0;
	while (str[count])
	{
		if (str[0] == '-')
		{
			count++;
			continue;
		}
		if (!isdigit(str[count]))
			return (0);
		count++;
	}
	return (1);
}

/**
 * @line_number: current line number
 * Return: opcode or null
 * parse_line - parses a line for an opcode and arguments
 * @stack: point the head of the stack
 * @line: line to be parsed
 */
char *parse_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *argument;
	char *op_code;
	char *push;
	(void)stack;

	push = "push";
	op_code = strtok(line, "\n ");
	if (op_code == NULL)
		return (NULL);

	if (strcmp(op_code, push) == 0)
	{
		argument = strtok(NULL, "\n ");
		if (isnumber(argument) == 1 && argument != NULL)
		{
			var_global.push_arg = atoi(argument);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	return (op_code);
}
