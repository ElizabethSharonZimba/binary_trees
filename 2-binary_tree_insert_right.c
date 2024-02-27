#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert - inserts a new node as the left or right child
 * @parent: pointer to the parent node
 * @value: value to store in the new node
 * @is_left: flag to determine left (1) or right (0) insertion
 *
 * Return: pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_insert(binary_tree_t *parent, int value, int is_left)
{
	if (parent == NULL)
		return (NULL);

	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	if (is_left)
	{
		new_node->left = parent->left;
		parent->left = new_node;
	}
	else
	{
		new_node->right = parent->right;
		parent->right = new_node;
	}

	if (is_left && new_node->left)
		new_node->left->parent = new_node;
	else if (!is_left && new_node->right)
		new_node->right->parent = new_node;

	return (new_node);
}
