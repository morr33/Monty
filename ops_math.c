#include "monty.h"
/**
 * ops_sub - subtracts the values from the top two elements of the stack
 * @head: double pointer to head node
 * @line_number: line number being intrepreted from Monty file
 */
void ops_sub(stack_t **head, unsigned int line_number)
{
	int first, second;

	if (!head || !*head || !(*head)->next)
		sub_err(head, line_number);
	first = (*head)->n;
	second = (*head)->next->n;
	*head = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
	(*head)->n = second - first;
}
/**
 * ops_div - divides the values from the top two elements of the stack
 * @head: double pointer to head node
 * @line_number: line number being intrepreted from Monty file
 */
void ops_div(stack_t **head, unsigned int line_number)
{
	int first, second;

	if (!head || !*head || !(*head)->next)
		div_err(head, line_number);
	if ((*head)->n == 0)
		zero_err(head, line_number);

	first = (*head)->n;
	second = (*head)->next->n;
	*head = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
	(*head)->n = second / first;
}
/**
 * ops_mul - adds the values of the top two elements of the stack
 * @head: double pointer to head node
 * @line_number: line number being interpreted from Monty file
 *
 * Return: Always nothing, exit with code EXIT_FAILURE on failure
 */
void ops_mul(stack_t **head, unsigned int line_number)
{
	int first, second;

	if (!head || !*head || !(*head)->next) /* short stack error */
		mul_err(head, line_number);
	first = (*head)->n;
	second = (*head)->next->n;
	*head = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
	(*head)->n = first * second;
}
