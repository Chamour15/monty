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

/**
 * _sub - opcode that subtracts the top element to
 * the second top element of the stack.
 * @head: head of the linked list.
 * @cmdline_n: line number.
 *
 * Return: void, no return.
 */
void _sub(stack_t **head, unsigned int cmdline_n)
{
	int i;
	stack_t *elem_to_sub = *head;

	i = 0;
	for (; elem_to_sub != NULL; elem_to_sub = elem_to_sub->next, i++)
		;

	if (i < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", cmdline_n);
		free_glbvar();
		exit(EXIT_FAILURE);
	}
	elem_to_sub = (*head)->next;
	elem_to_sub->n = elem_to_sub->n - (*head)->n;
	_pop(head, cmdline_n);
}

/**
 * _div - opcode divides the second element by the top element of the stack
 * @head: head of the dobly linked list.
 * @cmdline_n: line number.
 *
 * Return: void, no return.
 */
void _div(stack_t **head, unsigned int cmdline_n)
{
	stack_t *elem_to_div = *head;
	int i = 0;

	for (; elem_to_div != NULL; elem_to_div = elem_to_div->next, i++)
		;

	if (i < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", cmdline_n);
		free_glbvar();
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", cmdline_n);
		free_glbvar();
		exit(EXIT_FAILURE);
	}

	elem_to_div = (*head)->next;
	elem_to_div->n /= (*head)->n;
	_pop(head, cmdline_n);
}

