#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to measure the size of
 * Return: size of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: tree to count the leaves from
 * Return: number of leaves
 *         0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    if (!tree->left && !tree->right)
        return (1);

    return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree to measure the height of
 * Return: height of the tree
 *         0 if tree is NULL
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
