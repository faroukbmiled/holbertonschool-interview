#include "binary_trees.h"

/**
 * is_bst - Check if a binary tree is a valid Binary Search Tree.
 *
 * @tree: Pointer to the root node of the tree.
 * @min: The minimum value that the node can take (for left subtree).
 * @max: The maximum value that the node can take (for right subtree).
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return (1);

    if (tree->n < min || tree->n > max)
        return (0);

    return (is_bst(tree->left, min, tree->n - 1) &&
            is_bst(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_height - Compute the height of a binary tree.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Return: The height of the tree or 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (1 + ((left_height > right_height) ? left_height : right_height));
}

/**
 * binary_tree_is_avl - Check if a binary tree is a valid AVL tree.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    if (!is_bst(tree, INT_MIN, INT_MAX))
        return (0);

    if (abs((int)binary_tree_height(tree->left) - (int)binary_tree_height(tree->right)) > 1)
        return (0);

    if (tree->left && !binary_tree_is_avl(tree->left))
        return (0);

    if (tree->right && !binary_tree_is_avl(tree->right))
        return (0);

    return (1);
}
