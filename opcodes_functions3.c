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

/**
 * _pchar - opcode print the char value of the first element.
 * @head: head of the linked list
 * @cmdline_n: line number.
 *
 * Return: void, no return.
 */
void _pchar(stack_t **head, unsigned int cmdline_n)
{
	if (head == NULL || *head == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", cmdline_n);
		free_glbvar();
		exit(EXIT_FAILURE);
	}

	if ((*head)->n < 0 || (*head)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", cmdline_n);
		free_glbvar();
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*head)->n);
}

/**
 * _pstr - opcod prints the string of the stack.
 * @head: head of the doubly linked list.
 * @cmdline_n: line number.
 *
 * Return: void, no return.
 */
void _pstr(stack_t **head, unsigned int cmdline_n)
{
	stack_t *int_to_char = *head;

	UNUSED(cmdline_n);

	while (int_to_char && int_to_char->n > 0 && int_to_char->n < BUFFER)
	{
		printf("%c", int_to_char->n);
		int_to_char = int_to_char->next;
	}

	printf("\n");
}

/**
 * _rotl - opcode rotates the first element to the bottom and
 * the second to the top.
 * @head: head of the doubly linked list.
 * @cmdline_n: line number.
 *
 * Return: void, no return.
 */
void _rotl(stack_t **head, unsigned int cmdline_n)
{
	stack_t *tmp = NULL, *elem_rot = NULL;

	UNUSED(cmdline_n);

	if (*head == NULL)
	{
		return;
	}

	if ((*head)->next == NULL)
	{
		return;
	}

	tmp = (*head)->next;
	elem_rot = *head;

	for (; elem_rot->next != NULL; elem_rot = elem_rot->next)
		;

	tmp->prev = NULL;
	elem_rot->next = *head;
	(*head)->next = NULL;
	(*head)->prev = elem_rot;
	*head = tmp;
}

/**
 * _rotr - opcode rotates the stack to the bottom.
 * @head: head of the linked list
 * @cmdline_n: line number.
 *
 * Return: void, no return
 */
void _rotr(stack_t **head, unsigned int cmdline_n)
{
	stack_t *stack_rot = NULL;

	UNUSED(cmdline_n);

	if (*head == NULL)
	{
		return;
	}

	if ((*head)->next == NULL)
	{
		return;
	}

	stack_rot = *head;

	for (; stack_rot->next != NULL; stack_rot = stack_rot->next)
		;

	stack_rot->prev->next = NULL;
	stack_rot->next = *head;
	stack_rot->prev = NULL;
	(*head)->prev = stack_rot;
	*head = stack_rot;
}

