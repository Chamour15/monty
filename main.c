#include "monty.h"

global_var_t glob;
void global_var(FILE *file);

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, error code otherwise.
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	char *cmdlines[2] = {NULL, NULL};
	size_t buff_size = BUFF_SIZE;
	ssize_t  cmdl = 0;
	FILE *file;

	file = input(argc, argv);
	global_var(file);
	cmdl = getline(&glob.buff, &buff_size, file);

	while (cmdl != EOF)
	{
		cmdlines[0] = _strtok(glob.buff, " \t\n");
		if (cmdlines[0] && cmdlines[0][0] != '#')
		{
			f = opcodes(cmdlines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", glob.cnt);
				dprintf(2, "unknown instruction %s\n", cmdlines[0]);
				free_glbvar();
				exit(EXIT_FAILURE);
			}
			glob.argm = _strtok(NULL, " \t\n");
			f(&glob.head, glob.cnt);
		}
		cmdl = getline(&glob.buff, &buff_size, file);
		glob.cnt++;
	}
	free_glbvar();

	return (0);
}

/**
 * global_var - global variables init function.
 * @file: file descriptor.
 *
 * Return: void, no return.
 */
void global_var(FILE *file)
{
	glob.argm = NULL;
	glob.head = NULL;
	glob.buff = NULL;
	glob.lifo = 1;
	glob.cnt = 1;
	glob.file = file;
}

/**
 * free_glbvar - function that frees the global variables.
 *
 * Return: void, no return.
 */
void free_glbvar(void)
{
	free_dlistint(glob.head);
	free(glob.buff);
	fclose(glob.file);
}

