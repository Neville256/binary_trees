#include "binary_trees.h"
/**
 * binary_tree_inorder - in-order traversal through binary tree
 * @tree: tree to traverse pointer to root
 * @func: function to call for each node to pointer
 * Value in node must be passed as parameter function
 * If tree or func is NULL, do 0
 */

void binary_tree_inorder(const binary_tree_t *tree, void(*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
