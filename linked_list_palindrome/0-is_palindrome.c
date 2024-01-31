#include "lists.h"


/**
 * is_palindrome - Check if list is palindrome
 * @head: double pointer
 *
 * Return: 0 if !palindrome, 1 if palindrome
 */
int is_palindrome(listint_t **head)
{
	if (head == NULL)
		return (0);

	if (*head == NULL)
		return (1);

	return (pal_checker(head, *head));
}


/**
 * palindrome_check - Check if list is palindrome
 * @head: double pointer
 * @mover: single pointer
 *
 * Return: 0 if !palindrome, 1 if palindrome
 */
int pal_checker(listint_t **head, listint_t *mover)
{
	if (mover->next)
	{
		if (pal_checker(head, mover->next))
			(*head) = (*head)->next;
		else
			return (0);
	}

	if ((*head)->n == mover->n)
		return (1);

	return (0);
}
