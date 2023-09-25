#include "monty.h"
/**
 * usage_err - to display usage error
 * Return: Always nothing
 */
void usage_err(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 * file_err - display file error
 * Return: Always nothing
 */
void file_err(void)
{
	fprintf(stderr, "Error: Can't open file %s\n", context.op_file);
	exit(EXIT_FAILURE);
}
/**
 * opcode_err - display op_code error
 * @stack: the code causing error
 * @line_num: the line_number of code
 * Return: Always Nothing
 */
void opcode_err(stack_t **stack, unsigned int line_num)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, context.ext_code);
	FREE_STACK(stack);
	exit(EXIT_FAILURE);
}
/**
 * malloc_err - free the stack
 * @head: head pointer to the stack
 * Return: Alway zero
 */
void malloc_err(stack_t **head)
{
	fprintf(stderr, "Error: malloc failed\n");
	FREE_STACK(head);
	exit(EXIT_FAILURE);
}
/**
 * push_err - display push_err
 * @head: head pointer to the stack
 * @line_num: line number which the error occured
 * Return: Always Nothing
 */

void push_err(stack_t **head, ssize_t line_num)
{
	fprintf(stderr, "L%ld: usage: push integer\n", line_num);
	FREE_STACK(head);
	exit(EXIT_FAILURE);
}
