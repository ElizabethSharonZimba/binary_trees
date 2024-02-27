#include "binary_trees.h"
#include <math.h>

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if the tree is perfect, 0 otherwise or if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    size_t height, nodes, power;

    if (!tree)
        return (0);

    if (!tree->left && !tree->right)
        return (1);

    height = binary_tree_height(tree);
    nodes = binary_tree_size(tree);

    power = (size_t)pow(2, height + 1) - 1;
    return (power == nodes);
}

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
