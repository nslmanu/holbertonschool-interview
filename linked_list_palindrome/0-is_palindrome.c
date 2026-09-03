#include "lists.h"
#include <stdlib.h>

/**
 * list_len - counts the number of nodes in a listint_t list
 * @head: pointer to the head of the list
 *
 * Return: the number of nodes
 */
static size_t list_len(listint_t *head)
{
	size_t n = 0;

	while (head != NULL)
	{
		n++;
		head = head->next;
	}
	return (n);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to pointer of the head of the list
 *
 * Return: 1 if the list is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	size_t n, i;
	int *values;
	listint_t *current;

	if (head == NULL || *head == NULL)
		return (1);

	n = list_len(*head);
	values = malloc(sizeof(int) * n);
	if (values == NULL)
		return (0);

	current = *head;
	for (i = 0; i < n; i++)
	{
		values[i] = current->n;
		current = current->next;
	}

	for (i = 0; i < n / 2; i++)
	{
		if (values[i] != values[n - 1 - i])
		{
			free(values);
			return (0);
		}
	}

	free(values);
	return (1);
}