#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"


/**
 * sort - ....
 * @tmp: ....
 * Return: ....
 **/
heap_t *sort(heap_t *tmp)
{
	int n;

	while (tmp->left || tmp->right)
	{
		if (!tmp->right || tmp->left->n > tmp->right->n)
		{
			n = tmp->n;
			tmp->n = tmp->left->n;
			tmp->left->n = n;
			tmp = tmp->left;
		}
		else if (!tmp->left || tmp->left->n < tmp->right->n)
		{
			n = tmp->n;
			tmp->n = tmp->right->n;
			tmp->right->n = n;
			tmp = tmp->right;
		}

	}
	return (tmp);
}


/**
 * preorder - ....
 * @root: ....
 * @node: ....
 * @h: ....
 * @l: ....
 **/
void preorder(heap_t *root, heap_t **node, size_t h, size_t l)
{
	if (!root)
		return;
	if (h == l)
		*node = root;
	l++;
	if (root->left)
		preorder(root->left, node, h, l);
	if (root->right)
		preorder(root->right, node, h, l);
}


/**
 * checklen - ....
 * @tree: ....
 * Return: ....
 */
static size_t checklen(const binary_tree_t *tree)
{
	size_t h_left;
	size_t h_right;

	h_left = tree->left ? 1 + checklen(tree->left) : 0;
	h_right = tree->right ? 1 + checklen(tree->right) : 0;
	return (h_left > h_right ? h_left : h_right);
}

/**
 * heap_extract - ....
 * @root: ....
 * Return: ....
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *tmp, *node;

	if (!root || !*root)
		return (0);
	tmp = *root;
	value = tmp->n;
	if (!tmp->left && !tmp->right)
	{
		*root = NULL;
		free(tmp);
		return (value);
	}
	preorder(tmp, &node, checklen(tmp), 0);
	tmp = sort(tmp);
	tmp->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	return (value);
}
