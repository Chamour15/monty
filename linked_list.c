#include "monty.h"

/**
 * add_dnodeint - add new node at the begining of the doubly link list
 * @head: head of doubly linked linked list.
 * @n: integer number to add.
 *
 * Return: head of new added node
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *add_node;

	if (head == NULL)
	{
		return (NULL);
	}

	add_node = malloc(sizeof(stack_t));
	if (!add_node)
	{
		dprintf(2, "Error: malloc failed\n");
		free_glbvar();
		exit(EXIT_FAILURE);
	}

	add_node->n = n;

	if (*head == NULL)
	{
		add_node->next = *head;
		add_node->prev = NULL;
		*head = add_node;
		return (*head);
	}

	(*head)->prev = add_node;
	add_node->next = (*head);
	add_node->prev = NULL;
	*head = add_node;

	return (*head);
}

/**
 * add_dnodeint_end - function that add new node at the end
 * of a doubly link list.
 * @head: head of doubly linked linked list.
 * @n: integer number to add.
 *
 * Return: new node at the end of doubly linked list.
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *add_node_end, *tmp_node;

	if (head == NULL)
	{
		return (NULL);
	}

	tmp_node = malloc(sizeof(stack_t));
	if (!tmp_node)
	{
		dprintf(2, "Error: malloc failed\n");
		free_glbvar();
		exit(EXIT_FAILURE);
	}

	tmp_node->n = n;

	if (*head == NULL)
	{
		tmp_node->next = *head;
		tmp_node->prev = NULL;
		*head = tmp_node;
		return (*head);
	}

	add_node_end = *head;

	while (add_node_end->next)
	{
		add_node_end = add_node_end->next;
	}

	tmp_node->next = add_node_end->next;
	tmp_node->prev = add_node_end;
	add_node_end->next = tmp_node;

	return (add_node_end->next);
}

/**
 * free_dlistint - function that frees the doubly linked list.
 * @head: head of the doubly linked list
 *
 * Return: void, no return
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp_node;

	while ((tmp_node = head) != NULL)
	{
		head = head->next;
		free(tmp_node);
	}
}

