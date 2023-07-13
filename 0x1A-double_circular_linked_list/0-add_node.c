#include <stdlib.h>
#include "list.h"

/**
 *add_node_end - add a new node to the end of a doubly linked list
 *@list: list to modify
 *@str: string to copy into the new node
 *
 *Return: address of the new node, or NULL
 */
List *add_node_end(List **list, char *str)
{
	List *new_node, *temp;

	if (list == NULL || str == NULL)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	if (*list == NULL)
	{
		new_node->prev = new_node;
		new_node->next = new_node;
		*list = new_node;
	}
	else
	{
		temp = (*list)->prev;

		new_node->prev = temp;
		new_node->next = *list;
		temp->next = new_node;
		(*list)->prev = new_node;
	}

	return (new_node);
}

/**
 *add_node_begin - add a new node to the end of a doubly linked list
 *@list: list to modify
 *@str: string to copy into the new node
 *
 *Return: adress of the new node, or NULL
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node, *temp;

	if (list == NULL || str == NULL)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	if (*list == NULL)
	{
		new_node->prev = new_node;
		new_node->next = new_node;
		*list = new_node;
	}
	else
	{
		temp = (*list)->prev;

		new_node->prev = temp;
		new_node->next = *list;
		temp->next = new_node;
		(*list)->prev = new_node;
		*list = new_node;
	}

	return (new_node);
}
