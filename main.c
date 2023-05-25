#include "monty.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of argc
 * Return: success on exit, exit failure otherwise
 */
int main(int argc, char **argv)
{
	char s[500];
	size_t line_count = 0;

	glob.get_file = NULL;
	glob.stk = NULL;
	glob.s_or_q = 's';
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	glob.get_file = fopen(argv[1], "r");
	if (glob.get_file != NULL)
	{
		while (fgets(s, sizeof(s), glob.get_file) != NULL)
		{
			line_count++;
			instruc(s, line_count);
		}
		fclose(glob.get_file);
	}
	else
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		fclose(glob.get_file);
		clean(glob.stk);
		exit(EXIT_FAILURE);
	}

	return (0);
}
