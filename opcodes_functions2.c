#include "monty.h"

/**
* _add - opcode that adds the top two elements of the stack.
* @head: head of the linked list.
* @cmdline_n: line number.
*
* Return: void, no return.
*/
void _add(stack_t **head, unsigned int cmdline_n)
{
	int i;
	stack_t *elems_to_add = *head;

	i = 0;
	for (; elems_to_add != NULL; elems_to_add = elems_to_add->next, i++)
		;

	if (i < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", cmdline_n);
		free_glbvar();
		exit(EXIT_FAILURE);
	}

	elems_to_add = (*head)->next;
	elems_to_add->n = elems_to_add->n + (*head)->n;
	_pop(head, cmdline_n);
}

/**
 * _nop - opcode that doesn't do anythinhg.
 * @head: head of the linked list
 * @cmdline_n: line number.
 *
 * Return: void, no return.
 */
void _nop(stack_t **head, unsigned int cmdline_n)
{
	UNUSED(head);
	UNUSED(cmdline_n);
}

