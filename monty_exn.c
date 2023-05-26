#include "monty.h"
/**
 * instruc - make decision which func to call
 * @s: string
 * @line_num: line number in the file
 * Return: Nothing
 */
void instruc(char *s, unsigned int line_num)
{
	int i = 0;
	char *op = NULL;
	instruction_t ins[] = {
				{"push", push},
				{"pall", pall},
				{"pint", pint},
				{"pop", pop},
				{"swap", swap},
				{"add", add},
				{"nop", nop},
				{"sub", sub},
				{"div", divi},
				{"mul", mul},
				{"mod", mod},
				{"pchar", pchar},
				{"pstr", pstr},
				{"rotl", rotl},
				{"rotr", rotr},
				{"queue", queue},
				{"stack", stack},
				{NULL, NULL}};
	op = strtok(s, " \n\t\r\v\f");
	if (!op || op[0] == '#')
	return;
	while (ins[i].opcode && op)
	{
		if (!strcmp(op, ins[i].opcode))
		{
			ins[i].f(&(op), line_num);
			return;
		}
	i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op);
	clean(glob.stk);
	exit(EXIT_FAILURE);
}
