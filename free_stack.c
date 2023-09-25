#include "monty.h"
/**
 *FREE_STACK - frees all elements of stack
 *@stack: a pointer to the head node
 */

void FREE_STACK(stack_t **stack)
{
	stack_t *node = NULL;

	if (!stack || !*stack)
		return;
	while (*stack)
	{
		node = *stack;
		*stack = (*stack)->next;
		free(node);
	}
	*stack = NULL;
}

/**
 *sub_err- handles error for op_sub
 *@stack: a ptr to head node
 *@line_number: a line wear error occured
 */
void sub_err(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	FREE_STACK(stack);
	exit(EXIT_FAILURE);
}
/**
 * _getline - get the string from the file stream
 *  @lineptr: a pointer to an allocated memory
 *  @n: total byte to be fetched from the stream
 *  @stream: the file stream to fetch strings
 *  Return: -1 on fialure, else return total lenght of string fetched
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *buffer = NULL;
	ssize_t len = 0;
	ssize_t size = 0;
	int c;

	if (!lineptr || !n || !stream)
	{
		return (-1);
	}
	*lineptr = NULL;
	while ((c = fgetc(stream)) != EOF)
	{
		if (len + 1 >= size)
		{
			size = size ? size * 2 : MAX_LINE_LENGTH;
			buffer = realloc(buffer, size * sizeof(char));
			if (!buffer)
			{
				return (-1);
			}
			*lineptr = buffer;
			*n = size;
		}
		buffer[len++] = c;
		if (c == '\n')
			break;
	}
	if (len == 0)
		return (-1);

	buffer[len] = '\0';
	return (len);
}
