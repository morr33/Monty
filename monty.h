#ifndef __MONTY_H__
#define __MONTY_H__
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#define MAX 20
#define MAX_LINE_LENGTH 1024

extern struct Montycontext
{
	char *ext_value;
	char *op_file;
	char *ext_code;
	int stack_type;
} context;


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void (*get_func(char *ex_op_code))(stack_t **, unsigned int);
void ops_push(stack_t **stack, unsigned int line_number);

/* opcode functions */
void ops_push(stack_t **stack, unsigned int line_number);
void ops_pall(stack_t **stack, unsigned int line_number);
void ops_pint(stack_t **stack, unsigned int line_number);
void ops_pop(stack_t **stack, unsigned int line_number);
void ops_swap(stack_t **stack, unsigned int line_number);
void ops_add(stack_t **stack, unsigned int line_number);
void ops_nop(stack_t **stack, unsigned int line_number);
void ops_sub(stack_t **stack, unsigned int line_number);
void ops_div(stack_t **stack, unsigned int line_number);
void ops_mul(stack_t **stack, unsigned int line_number);
void ops_mod(stack_t **stack, unsigned int line_number);
void ops_pchar(stack_t **stack, unsigned int line_number);

void FREE_STACK(stack_t **stack);


/*errors*/
void usage_err(void);
void malloc_err(stack_t **head);
void file_err(void);


void push_err(stack_t **head, ssize_t line_number);
void opcode_err(stack_t **stack, unsigned int line_number);
void pint_err(stack_t **stack, unsigned int line_number);
void pop_err(stack_t **stack, unsigned int line_number);
void swap_err(stack_t **stack, unsigned int line_number);
void add_err(stack_t **stack, unsigned int line_number);
void sub_err(stack_t **stack, unsigned int line_number);
void div_err(stack_t **stack, unsigned int line_number);
void zero_err(stack_t **stack, unsigned int line_number);
void mul_err(stack_t **stack, unsigned int line_number);
void mod_err(stack_t **stack, unsigned int line_number);
void pchar_err(stack_t **stack, unsigned int line_number);
void char_err(stack_t **stack, unsigned int line_number);

#endif
