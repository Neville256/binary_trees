#include "binary_trees.h"
/**
 * binary_tree_size - size of a binary tree measures
 *
 * @tree: tree to measure size of root to pointer
 * Return: size or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t k = 1;

	if (!tree)
		return (0);

	k += binary_tree_size(tree->left);
	k += binary_tree_size(tree->right);

	return (k);
}
