#include "monty.h"
/**
 *pint_err- op_pint error handling function
 *@stack: a ptr pointing to  a head node
 *@line_number: linumber wear error ocured
 *
 */

void pint_err(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	FREE_STACK(stack);
	exit(EXIT_FAILURE);
}
/**
 *pop_err-handles error for op_pop function
 *@stack: a ptr pointing to  a head node
 *@line_number: linumber wear error ocured
 */
void pop_err(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	FREE_STACK(stack);
	exit(EXIT_FAILURE);
}
/**
 *swap_err-handles error for op_swap function
 *@stack: a ptr pointing to  a head node
 *@line_number: linumber wear error ocured
 */
void swap_err(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't swap, stack to short\n", line_number);
	FREE_STACK(stack);
	exit(EXIT_FAILURE);
}
/**
 *add_err - handles error for op_add function
 *@stack: a ptr pointing to  a head node
 *@line_number: linumber wear error ocured
 */
void add_err(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't add, stack too short \n", line_number);
	FREE_STACK(stack);
	exit(EXIT_FAILURE);
}
/**
 * div_err - handles error for op_div function
 * @stack: a  pointer to head node
 * @line_number: line number where error occured
 *
 * Return: Always nothing
 */
void div_err(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
	FREE_STACK(stack);
	exit(EXIT_FAILURE);
}
