#include "binary_trees.h"

/**
 * tree_size - measures the number of nodes in a binary tree
 * @tree: pointer to the root node of the tree to measure
 *
 * Return: the number of nodes, 0 if @tree is NULL
 */
static size_t tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: the value to store in the node to be inserted
 *
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node, *parent;
	size_t index, mask;
	int tmp;

	if (root == NULL)
		return (NULL);
	if (*root == NULL)
		return (*root = binary_tree_node(NULL, value));

	index = tree_size(*root) + 1;
	parent = *root;
	for (mask = 1; (mask << 1) <= index; mask <<= 1)
		;
	for (mask >>= 1; mask > 1; mask >>= 1)
		parent = (index & mask) ? parent->right : parent->left;

	node = binary_tree_node(parent, value);
	if (node == NULL)
		return (NULL);
	if (index & 1)
		parent->right = node;
	else
		parent->left = node;

	while (node->parent != NULL && node->n > node->parent->n)
	{
		tmp = node->n;
		node->n = node->parent->n;
		node->parent->n = tmp;
		node = node->parent;
	}
	return (node);
}
