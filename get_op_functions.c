#include "monty.h"
/**
 * get_func - check for the ops_code
 * @ex_op_code: ops code to be checked
 * Return: Always Nothing
 */

void (*get_func(char *ex_op_code))(stack_t **, unsigned int)
{
	instruction_t inst[] = {
		{"push", ops_push},
		{"pall", ops_pall},
		{"pint", ops_pint},
		{"pop", ops_pop},
		{"swap", ops_swap},
		{"add", ops_add},
		{"nop", ops_nop},
		{"sub", ops_sub},
		{"div", ops_div},
		{"mul", ops_mul},
		{"mod", ops_mod},
		{"pchar", ops_pchar},
		{"#", ops_nop},
		{NULL, NULL}
	};
	int idx = 0;

	while (inst[idx].opcode != NULL)
	{
		if (strcmp(ex_op_code, inst[idx].opcode) == 0)
			return (inst[idx].f);
		idx++;
	}
	return (NULL);
}
