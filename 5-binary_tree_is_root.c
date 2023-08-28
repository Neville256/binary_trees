#include "binary_trees.h"
/**
 * binary_tree_is_root - root checks if given node
 *
 * @node: node to check pointer
 * Return: 1 if node is a root, otherwise 0
 * If node is NULL, return 0
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node && !node->parent)
		return (1);
	return (0);
}
