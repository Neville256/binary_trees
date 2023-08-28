#include "binary_trees.h"

/**
 * binary_tree_preorder - pre-order traversal goes through binary tree
 *
 * @tree: tree to travers pointer to root node
 * @func: call for each node to pointer
 * parameter function node must be passed in value
 * If tree or func is NULL, do 0
 */

void binary_tree_preorder(const binary_tree_t *tree, void(*func)(int))
{
	if (!(tree) || !(func))
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
