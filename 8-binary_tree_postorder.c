#include "binary_trees.h"

/**
 * binary_tree_postorder - tree using post-order traversal through binary tree
 * @tree: tree to travers pointer to root
 * @func: call for each node pointer
 * The value in the node must be passed as parameter function.
 * If tree or func is NULL, do 0
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!(tree) || !(func))
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
