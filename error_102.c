#include "monty.h"
/**
 * zero_err -  handles the zerro erro for op_div function program
 * @stack: a pointer to head node
 * @line_number: line number where error occured
 *
 */
void zero_err(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: division by zero\n", line_number);
	FREE_STACK(stack);
	exit(EXIT_FAILURE);
}
/**
 * mul_err - op_mul error handling program
 * @stack: double pointer to head node
 * @line_number: line number where error occured
 *
 * Return: nothing
 */
void mul_err(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
	FREE_STACK(stack);
	exit(EXIT_FAILURE);
}
/**
 * mod_err - handles error for op_mod function
 * @stack: a  pointer to head node
 * @line_number: line number where error occured
 *
 */
void mod_err(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
	FREE_STACK(stack);
	exit(EXIT_FAILURE);
}
/**
 * pchar_err - handles stack error for oP_char
 * @stack: a pointer to head node
 * @line_number: line number where error occured
 *
 */
void pchar_err(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
	FREE_STACK(stack);
	exit(EXIT_FAILURE);
}
/**
 *char_err- eror in chars
 *@stack: a ptr to head node
 *@line_number: number error occured at
 */

void char_err(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
	FREE_STACK(stack);
	exit(EXIT_FAILURE);
}
