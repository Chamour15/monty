#include "monty.h"

/**
 * _mod - opcode computes the rest of the division of the second element
 * by the top element of the stack
 * @head: head of the linked list
 * @cmdline_n: line number.
 *
 * Return: void, no return
 */
void _mod(stack_t **head, unsigned int cmdline_n)
{
	stack_t *elem_to_mod = *head;
	int i;

	i = 0;
	for (; elem_to_mod != NULL; elem_to_mod = elem_to_mod->next, i++)
		;

	if (i < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", cmdline_n);
		free_glbvar();
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", cmdline_n);
		free_glbvar();
		exit(EXIT_FAILURE);
	}

	elem_to_mod = (*head)->next;
	elem_to_mod->n = elem_to_mod->n % (*head)->n;
	_pop(head, cmdline_n);
}

