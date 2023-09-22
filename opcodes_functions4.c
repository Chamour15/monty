#include "monty.h"

/**
 * _stack - opcode sets the format fo the data to a stack (LIFO).
 * @head: head of the doubly linked list.
 * @cmdline_n: line number
 *
 * Return: void, no return.
 */
void _stack(stack_t **head, unsigned int cmdline_n)
{
	UNUSED(cmdline_n);
	UNUSED(head);

	glob.lifo = 1;
}

/**
 * _queue - opcode sets the format of the data to a queue (FIFO).
 * @head: head of the doubly linked list
 * @cmdline_n: line number.
 *
 * Return: void no return
 */
void _queue(stack_t **head, unsigned int cmdline_n)
{
	UNUSED(head);
	UNUSED(cmdline_n);

	glob.lifo = 0;
}

