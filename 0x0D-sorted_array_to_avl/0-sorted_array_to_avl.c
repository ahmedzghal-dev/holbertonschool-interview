#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * add_new_node - Create a new node for AVL tree
 * @n: Value of node to create
 * @parent: Parent node of new node to create
 *
 * Return: New node or NULL on failure
 */
avl_t *add_new_node(int n, avl_t *parent)
{
    avl_t *new_node = malloc(sizeof(*new_node));

    if (!new_node)
    {
        return (NULL);
    }
    new_node->parent = parent;
    new_node->n = n;
    new_node->left = NULL;
    new_node->right = NULL;
    return (new_node);
}

/**
 * avl_run - Build AVL tree from sorted array
 * @parent: Parent node of current node being created
 * @array: Pointer to first element of array
 * @left: Index of leftmost element in current segment of array
 * @right: Index of rightmost element in current segment of array
 *
 * Return: Root node of AVL tree or NULL on failure
 */
avl_t *avl_run(avl_t *parent, int *array, int left, int right)
{
    avl_t *new;
    int i;

    if (left > right)
    {
        return (NULL);
    }
    i = (left + right) / 2;
    new = add_new_node(array[i], parent);
    if (!new)
    {
        return (NULL);
    }
    new->left = avl_run(new, array, left, i - 1);
    new->right = avl_run(new, array, i + 1, right);
    return (new);
}

/**
 * sorted_array_to_avl - Build AVL tree from sorted array
 * @array: Pointer to first element of array
 * @size: Number of elements in array
 *
 * Return: Root node of AVL tree or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    return (avl_run(NULL, array, 0, size - 1));
}