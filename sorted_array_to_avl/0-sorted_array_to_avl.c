#include "binary_trees.h"

/**
 *sorted_array_to_avl -  makes an avl tree from sorted array
 *
 *@array: Pointer to the first element
 *@size: Number of elements
 *
 *Return: Pointer to the root node
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	int result = 0;

	if (array == NULL || size < 1)
		return (NULL);

	result = add_avl_nodes(array, size, &root, 1);
	if (result)
	{
		free_avl(&root);
		return (NULL);
	}

	return (root);
}

/**
 *add_avl_nodes - makes an avl tree from sorted array
 *
 *@array: Pointer to the first element
 *@size: Number of elements
 *@tree: Double pointer
 *@add_left: Flag
 *
 *Return: 0 or -1
 */
int add_avl_nodes(int *array, size_t size, avl_t **tree, int add_left)
{
	size_t mid_index = (size - 1) / 2;
	avl_t *new_node = NULL;
	int result = 0;

	if (array == NULL || size < 1)
		return (0);

	new_node = malloc(sizeof(avl_t));
	if (new_node == NULL)
		return (-1);

	new_node->n = array[mid_index];
	new_node->parent = (*tree);
	new_node->left = NULL;
	new_node->right = NULL;

	if ((*tree) == NULL)
		(*tree) = new_node;
	else if (add_left)
		(*tree)->left = new_node;
	else
		(*tree)->right = new_node;

	result = add_avl_nodes(array, mid_index, &new_node, 1);
	if (result == -1)
		return (-1);

	mid_index++;
	result = add_avl_nodes(&array[mid_index], size - mid_index, &new_node, 0);
	if (result == -1)
		return (-1);

	return (0);
}

/**
 *free_avl - free avl tree
 *
 *@tree: Double pointer
 */
void free_avl(avl_t **tree)
{
	avl_t *left = NULL, *right = NULL;

	if (tree == NULL || (*tree) == NULL)
		return;

	left = (*tree)->left;
	right = (*tree)->right;

	free(*tree);

	free_avl(&left);
	free_avl(&right);
}
