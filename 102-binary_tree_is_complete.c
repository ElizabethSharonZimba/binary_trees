#include "binary_trees.h"

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
void btlo_helper(const binary_tree_t *tree, void (*func)(int), size_t level);
size_t binary_tree_height(const binary_tree_t *tree);

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    size_t size;

    if (!tree)
        return (0);
    size = binary_tree_size(tree);

    return (btic_helper(tree, 0, size));
}

/**
 * btic_helper - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 * @index: node index to check
 * @size: number of nodes in the tree
 * Return: 1 if the tree is complete, 0 otherwise
 */
int btic_helper(const binary_tree_t *tree, size_t index, size_t size)
{
    if (!tree)
        return (1);

    if (index >= size)
        return (0);

    return (btic_helper(tree->left, 2 * index + 1, size) &&
            btic_helper(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to measure the size of
 * Return: size of the tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (binary_tree_size(tree->left) +
            binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_levelorder - traverses a binary tree using level-order traversal
 * @tree: tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    size_t level, maxlevel;

    if (!tree || !func)
        return;

    maxlevel = binary_tree_height(tree) + 1;

    for (level = 1; level <= maxlevel; level++)
        btlo_helper(tree, func, level);
}

/**
 * btlo_helper - goes through a binary tree using post-order traverse
 * @tree: tree to traverse
 * @func: pointer to a function to call for each node
 * @level: the level of the tree to call func upon
 */
void btlo_helper(const binary_tree_t *tree, void (*func)(int), size_t level)
{
    if (level == 1)
        func(tree->n);
    else
    {
        btlo_helper(tree->left, func, level - 1);
        btlo_helper(tree->right, func, level - 1);
    }
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree to measure the height of
 * Return: height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t height_l = 0;
    size_t height_r = 0;

    if (!tree)
        return (0);

    height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
    height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
    return (height_l > height_r ? height_l : height_r);
}
