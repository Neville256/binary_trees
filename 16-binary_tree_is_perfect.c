#include "binary_trees.h"

/**
 * compare_depth - size compare
 *
 * @tree: root to pointer
 * Return: size
 */
int compare_depth(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	else
		return (compare_depth(tree->left) + 1 + compare_depth(tree->right));
}
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect function
 *
 * @tree: tree to check pointer to root
 * Return: 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int h_left = 0, h_right = 0;

	if (!tree)
		return (0);

	if (tree && (!tree->left && !tree->right))
		return (1);

	h_left = compare_depth(tree->left);
	h_right = compare_depth(tree->right);

	if ((h_left - h_right) == 0)
		return (1);

	return (0);
}
