#include "monty.h"
/**
 * ops_nop - does nothing
 * @stack: a pointer to head node
 * @line_number: line being interpreted from Monty file
 *
 * Return: Always Nothing
 */
void ops_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * ops_mod - modulos the values of the top two elements of the stack
 * @head: double pointer to head node
 * @line_number: line number being interpreted from Monty file
 *
 * Description: result is stored in 2nd top element, top element is removed
 * Return: nothing, exit with code EXIT_FAILURE on failure
 */
void ops_mod(stack_t **head, unsigned int line_number)
{
	int first, second;

	if (!head || !*head || !(*head)->next)
		mod_err(head, line_number);
	if ((*head)->n == 0)
		zero_err(head, line_number);
	first = (*head)->n;
	second = (*head)->next->n;
	*head = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
	(*head)->n = second % first;
}
/**
 * ops_pchar - prints the value at the top of the stack as a character
 * @head: a pointer to head node of stack
 * @line_number: line number being interpreted from Monty file
 * Return: Always Nothing
 *
 */
void ops_pchar(stack_t **head, unsigned int line_number)
{
	if (!head || !*head)
		pchar_err(head, line_number);
	if ((*head)->n > 127 || (*head)->n < 0)
		char_err(head, line_number);
	printf("%c\n", (*head)->n);
}
/**
 * ops_add - adds the values of the top two elements of the stack
 * @head: a double pointer to head node
 * @line_number: line number being interpreted from Monty file
 *
 * Description: result is stored in 2nd top element, top element is removed
 * Return: Always nothing, exit with code EXIT_FAILURE on failure
 */
void ops_add(stack_t **head, unsigned int line_number)
{
	int first, second;

	if (!head || !*head || !(*head)->next) /* short stack error */
		add_err(head, line_number);
	first = (*head)->n;
	second = (*head)->next->n;
	*head = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
	(*head)->n = first + second;
}
