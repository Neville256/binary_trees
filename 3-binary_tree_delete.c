#include "binary_trees.h"

/**
 * binary_tree_delete - entire binary tree deleted
 *
 * @tree: tree to delete to the pointer to root
 *If tree is NULL, do none
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);

	free(tree);
}
