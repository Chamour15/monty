#include "monty.h"

/**
 * _push - opcode that pushes an element to the stack.
 * @head: head of the linked list
 * @cmdline_n: line number.
 *
 * Return: void, no return.
 */
void _push(stack_t **head, unsigned int cmdline_n)
{
	int i, elem_to_push;

	if (!glob.argm)
	{
		dprintf(2, "L%u: ", cmdline_n);
		dprintf(2, "usage: push integer\n");
		free_glbvar();
		exit(EXIT_FAILURE);
	}

	for (i = 0; glob.argm[i] != '\0'; i++)
	{
		if (!isdigit(glob.argm[i]) && glob.argm[i] != '-')
		{
			dprintf(2, "L%u: ", cmdline_n);
			dprintf(2, "usage: push integer\n");
			free_glbvar();
			exit(EXIT_FAILURE);
		}
	}

	elem_to_push = atoi(glob.argm);

	if (glob.lifo == 1)
	{
		add_dnodeint(head, elem_to_push);
	}
	else
	{
		add_dnodeint_end(head, elem_to_push);
	}
}

/**
 * _pall - opcode that prints all values on the stack,
 * starting from the top of the stack.
 * @head: head of the linked list.
 * @cmdline_n: line numbers.
 *
 * Return: void, no return.
 */
void _pall(stack_t **head, unsigned int cmdline_n)
{
	stack_t *val_to_print;

	UNUSED(cmdline_n);

	val_to_print = *head;

	while (val_to_print)
	{
		printf("%d\n", val_to_print->n);
		val_to_print = val_to_print->next;
	}
}

