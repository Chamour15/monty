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

/**
 * _pint - opcode that prints the value at the top of the stack.
 * @head: head of the linked list.
 * @cmdline_n: line number.
 *
 * Return: void, no return.
 */
void _pint(stack_t **head, unsigned int cmdline_n)
{
	UNUSED(cmdline_n);

	if (*head == NULL)
	{
		dprintf(2, "L%u: ", cmdline_n);
		dprintf(2, "can't pint, stack empty\n");
		free_glbvar();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}

/**
 * _pop - opcode that removes the top element of the stack.
 * @head: head of the linked list.
 * @cmdline_n: line number.
 *
 * Return: void, no return.
 */
void _pop(stack_t **head, unsigned int cmdline_n)
{
	stack_t *elem_to_remove;

	if (head == NULL || *head == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", cmdline_n);
		free_glbvar();
		exit(EXIT_FAILURE);
	}

	elem_to_remove = *head;
	*head = (*head)->next;
	free(elem_to_remove);
}

/**
 * _swap - opcode that swaps the top two elements of the stack.
 * @head: head of the linked list.
 * @cmdline_n: line number.
 *
 * Return: void, no return
 */
void _swap(stack_t **head, unsigned int cmdline_n)
{
	stack_t *elem_to_swap = *head;
	int i;

	i = 0;
	for (; elem_to_swap != NULL; elem_to_swap = elem_to_swap->next, i++)
	;

	if (i < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", cmdline_n);
		free_glbvar();
		exit(EXIT_FAILURE);
	}

	elem_to_swap = *head;
	*head = (*head)->next;
	elem_to_swap->next = (*head)->next;
	elem_to_swap->prev = *head;
	(*head)->next = elem_to_swap;
	(*head)->prev = NULL;
}
