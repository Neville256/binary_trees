#include "binary_trees.h"
/**
 * binary_tree_nodes - 1 child in a binary tree counts the nodes
 *
 * @tree: node of tree to count number of nodes pointer to root
 * Return: If tree is NULL, function must return 0
 * A NULL pointer is a node
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree)
		return (0);

	if (tree->left || tree->right)
		count = 1;

	count += binary_tree_nodes(tree->left);
	count += binary_tree_nodes(tree->right);

	return (count);
}
