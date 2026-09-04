#include "lists.h"

/**
 * reverse_list - reverses a singly linked list in place
 * @head: pointer to the first node of the list to reverse
 *
 * Return: pointer to the new head of the reversed list
 */
static listint_t *reverse_list(listint_t *head)
{
	listint_t *prev = NULL;
	listint_t *next = NULL;

	while (head != NULL)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	return (prev);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to pointer of the head of the list
 *
 * Return: 1 if the list is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow, *fast, *second_half, *first_half, *temp;
	int result = 1;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return (1);

	slow = *head;
	fast = *head;
	while (fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	second_half = reverse_list(slow->next);
	first_half = *head;

	temp = second_half;
	while (temp != NULL)
	{
		if (first_half->n != temp->n)
		{
			result = 0;
			break;
		}
		first_half = first_half->next;
		temp = temp->next;
	}

	slow->next = reverse_list(second_half);

	return (result);
}