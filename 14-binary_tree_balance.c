#include "binary_trees.h"

/**
 * binary_tree_height_balance - balance factor of a binary tree measures
 * @tree: pointer to the root node of tree measure balance factor
 *
 * Return: height
 * if tree is NULL, return 0
 */

size_t binary_tree_height_balance(const binary_tree_t *tree)
{
	size_t h_left = 0, h_right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		h_left = 1 + binary_tree_height_balance(tree->left);
	if (tree->right)
		h_right = 1 + binary_tree_height_balance(tree->right);

	if (h_left > h_right)
		return (h_left);
	return (h_right);
}

/**
 * binary_tree_balance - balance factor of a binary tree measured
 *
 * @tree: node of tree pointer to node
 * Return: factor balance
 * If tree is NUll, return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t h_left = 0, h_right = 0;

	if (!tree)
		return (0);
	if (tree->left)
		h_left = 1 + binary_tree_height_balance(tree->left);
	if (tree->right)
		h_right = 1 + binary_tree_height_balance(tree->right);
	return (h_left - h_right);
}

