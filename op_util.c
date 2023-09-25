#include "monty.h"

/**
 * ops_push -function to push to the stack
 * @head: a pointer to the stack
 * @line_num: the line number for the ops_code
 * Return: Nothing
 */

void ops_push(stack_t **head, unsigned int line_number)
{
	stack_t *new_node = NULL, *tail = NULL;
	unsigned int idx = 0;

	if (!head || !line_number)
		exit(EXIT_FAILURE);
	if (context.ext_value[0] == '\0')
		push_err(head, line_number);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		free(new_node);
		malloc_err(head);
	}
	while (context.ext_value[idx] != '\0')
	{
		if (isdigit(context.ext_value[idx]) == 0 && context.ext_value[idx] != '-')
			push_err(head, line_number);
		idx++;
	}
	new_node->n = atoi(context.ext_value);
	if (context.stack_type == 1)
	{
		new_node->next = NULL;
		if (!*head)
		{
			new_node->prev = NULL;
			*head = new_node;
		}
		else
		{
			tail = *head;
			while (tail->next)
				tail = tail->next;
			new_node->prev = tail;
			tail->next = new_node;
		}
	}
	else
	{
		new_node->prev = NULL;
		new_node->next = *head;
		if (*head)
			(*head)->prev = new_node;
		*head = new_node;
	}
}

/**
 * ops_pall - prints all the value on the stack from the top
 * @stack: double pointer to stack node
 * @line_number: line number where ops_code was found
 *
 * Return: nothing, exit with code EXIT_FAILURE on failure
 */
void ops_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;

	if (!line_number)
	{
		FREE_STACK(stack);
		return;
	}
	if (context.ext_value[0] != '\0')
		opcode_err(stack, line_number);
	node = *stack;

	while (node)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}

/**
 * ops_pint - prints the value at the top of the stack
 * @head: pointer to head node of stack
 * @line_number: line number being interpreted from Monty file
 *
 * Return: Always NOthing, exit with code EXIT_FAILURE on failure
 */
void ops_pint(stack_t **head, unsigned int line_number)
{
	if (!head || !*head) /* empty stack error */
		pint_err(head, line_number);
	printf("%d\n", (*head)->n);
}
/**
 * ops_pop - removes the top element of the stack
 * @head: double pointer to head node
 * @line_number: line number where error occured
 *
 * Return: Always Nothing, exit with code EXIT_FAILURE on failure
 */
void ops_pop(stack_t **head, unsigned int line_number)
{
	stack_t *node;

	if (!head || !*head) /* empty stack error */
		pop_err(head, line_number);
	node = *head;
	if (!node->next)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		(*head) = (*head)->next;
		(*head)->prev = NULL;
		free(node);
	}
}
/**
 * ops_swap - swaps the values of the top two elements of the stack
 * @head: double pointer to head node
 * @line_number: line number being interpreted from Monty file
 *
 * Return: Alway Nothing, exit with code EXIT_FAILURE on failure
 */
void ops_swap(stack_t **head, unsigned int line_number)
{
	int temp_n;

	if (!head || !*head || (*head)->next == NULL)
		swap_err(head, line_number);
	temp_n = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = temp_n;
}
