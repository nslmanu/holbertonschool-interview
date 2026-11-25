#include <stdlib.h>
#include "binary_trees.h"

/**
 * create_node - allocates and initializes a new AVL node
 * @parent: pointer to the parent node
 * @value: integer to store in the node
 *
 * Return: pointer to the new node, or NULL on failure
 */
static avl_t *create_node(avl_t *parent, int value)
{
	avl_t *node;

	node = malloc(sizeof(avl_t));
	if (node == NULL)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

/**
 * build_avl - recursively builds a balanced AVL from a sorted slice
 * @array: the sorted array
 * @lo: lower index of the current slice
 * @hi: upper index of the current slice
 * @parent: pointer to the parent node
 *
 * Return: pointer to the subtree root, or NULL on failure
 */
static avl_t *build_avl(int *array, int lo, int hi, avl_t *parent)
{
	avl_t *node;
	int mid;

	if (lo > hi)
		return (NULL);

	mid = (lo + hi) / 2;
	node = create_node(parent, array[mid]);
	if (node == NULL)
		return (NULL);

	node->left = build_avl(array, lo, mid - 1, node);
	node->right = build_avl(array, mid + 1, hi, node);
	return (node);
}

/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array
 * @array: pointer to the first element of the sorted array
 * @size: number of elements in the array
 *
 * Return: pointer to the root node of the created AVL tree, or NULL
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (build_avl(array, 0, (int)size - 1, NULL));
}
