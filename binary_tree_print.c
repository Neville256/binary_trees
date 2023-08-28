#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * print_t - Stores recursively each level in an array of strings
 *
 * @tree: print node to pointer
 * @offset: print offset
 * @depth: node depth
 * @s: Buffer
 *
 * Return: process lenght of printed tree
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[6];
	int width, left, right, is_left, k;

	if (!tree)
		return (0);
	is_left = (tree->parent && tree->parent->left == tree);
	width = sprintf(b, "(%03d)", tree->n);
	left = print_t(tree->left, offset, depth + 1, s);
	right = print_t(tree->right, offset + left + width, depth + 1, s);
	for (k = 0; k < width; k++)
		s[depth][offset + left + k] = b[k];
	if (depth && is_left)
	{
		for (k = 0; k < width + right; k++)
			s[depth - 1][offset + left + width / 2 + k] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (k = 0; k < left + width; k++)
			s[depth - 1][offset - width / 2 + k] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	return (left + width + right);
}

/**
 * _height - height of binary tree mesaured
 *
 * @tree: node to pointer is measurd by height
 *
 * Return: The height of the tree starting at @node
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	height_l = tree->left ? 1 + _height(tree->left) : 0;
	height_r = tree->right ? 1 + _height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_print - Prints a binary tree
 *
 * @tree: the tree to print pointer to the root
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	size_t height, k, m;

	if (!tree)
		return;
	height = _height(tree);
	s = malloc(sizeof(*s) * (height + 1));
	if (!s)
		return;
	for (k = 0; k < height + 1; k++)
	{
		s[k] = malloc(sizeof(**s) * 255);
		if (!s[k])
			return;
		memset(s[k], 32, 255);
	}
	print_t(tree, 0, 0, s);
	for (k = 0; k < height + 1; k++)
	{
		for (m = 254; m > 1; --m)
		{
			if (s[k][m] != ' ')
				break;
			s[k][m] = '\0';
		}
		printf("%s\n", s[k]);
		free(s[k]);
	}
	free(s);
}
