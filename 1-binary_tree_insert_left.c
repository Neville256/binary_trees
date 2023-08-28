#include "binary_trees.h"
/**
 * binary_tree_insert_left - inserts a node as left child node of another
 *
 * @parent: left child in pointer to node to insert
 * @value: new node value to store
 * Return: create new node to pointer. NULL on failure
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *pleft = NULL, *new_node = NULL;

	if (!parent)
		return (NULL);
	new_node = malloc(sizeof(binary_tree_t));

	if (!new_node)
		return (NULL);

	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->n = value;

	pleft = parent->left;
	parent->left = new_node;

	if (pleft)
	{
		pleft->parent = new_node;
		new_rode->left = pleft;
	}

	return (new_node);
}
