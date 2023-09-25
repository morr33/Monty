#include "monty.h"
/**
 * main - entry point
 * @argc: argument count
 * @argv: argument variable
 * Return: 0 on success
 */

struct Montycontext context = {NULL, NULL, NULL, 0};

int main(int argc, char **argv)
{
	FILE *file_ptr;
	ssize_t byte_read = 0, line_len = 0, line_num = 1;
	size_t lin_buf = 0;
	char *line_read = NULL;
	char op_code[MAX], op_value[MAX];
	stack_t *STACK = NULL;

	if (argc != 2 || !argv[1])
		usage_err();

	context.stack_type = 0;
	context.op_file = argv[1];
	file_ptr = fopen(context.op_file, "r");

	if (!file_ptr)
		file_err();
	while ((byte_read = _getline(&line_read, &lin_buf, file_ptr)) != -1)
	{
		line_len = sscanf(line_read, "%s %s", op_code, op_value);
		if (line_len > 2)
		{
			free(line_read);
			line_read = NULL;
			FREE_STACK(&STACK);
			usage_err();
		}
		line_num++;
		context.ext_code = op_code;
		context.ext_value = op_value;

		if (line_len > 0 && op_code[0] != '#')
			get_func(context.ext_code)(&STACK, line_num);
		memset(op_code, '\0', sizeof(op_code));
		memset(op_value, '\0', sizeof(op_value));
		free(line_read);
		line_read = NULL;
	}
	free(line_read);
	FREE_STACK(&STACK);
	fclose(file_ptr);
	return (0);
}
