#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * @brief Stores recursively each level of a binary tree in an array of strings
 * @param tree Pointer to the root node of the tree to print
 * @param offset Offset for the current level
 * @param depth Depth of the current level
 * @param s Array of strings to store the tree representation
 * @return Width of the node representation
 */
static int print_binary_tree(const binary_tree_t *tree, int offset, int depth, char **s)
{
    char node_str[8];
    int width, left, right, is_left, i;

    if (!tree)
        return 0;

    is_left = (tree->parent && tree->parent->left == tree);
    width = sprintf(node_str, "(%03d)", tree->n);
    left = print_binary_tree(tree->left, offset, depth + 1, s);
    right = print_binary_tree(tree->right, offset + left + width, depth + 1, s);

    for (i = 0; i < width; i++)
        s[depth][offset + left + i] = node_str[i];

    if (depth && is_left)
    {
        for (i = 0; i < width + right; i++)
            s[depth - 1][offset + left + width / 2 + i] = '-';
        s[depth - 1][offset + left + width / 2] = '.';
    }
    else if (depth && !is_left)
    {
        for (i = 0; i < left + width; i++)
            s[depth - 1][offset - width / 2 + i] = '-';
        s[depth - 1][offset + left + width / 2] = '.';
    }

    return left + width + right;
}

/**
 * @brief Measures the height of a binary tree
 * @param tree Pointer to the root node of the tree
 * @return Height of the tree
 */
static size_t calculate_tree_height(const binary_tree_t *tree)
{
    size_t height_left, height_right;

    height_left = tree->left ? 1 + calculate_tree_height(tree->left) : 0;
    height_right = tree->right ? 1 + calculate_tree_height(tree->right) : 0;

    return (height_left > height_right ? height_left : height_right);
}

/**
 * @brief Prints a binary tree
 * @param tree Pointer to the root node of the tree to print
 */
void pretty_print_binary_tree(const binary_tree_t *tree)
{
    char **tree_repr;
    size_t height, i, j;

    if (!tree)
        return;

    height = calculate_tree_height(tree);
    tree_repr = malloc(sizeof(*tree_repr) * (height + 1));

    if (!tree_repr)
        return;

    for (i = 0; i < height + 1; i++)
    {
        tree_repr[i] = malloc(sizeof(**tree_repr) * 255);

        if (!tree_repr[i])
            return;

        memset(tree_repr[i], 32, 255);
    }

    print_binary_tree(tree, 0, 0, tree_repr);

    for (i = 0; i < height + 1; i++)
    {
        for (j = 254; j > 1; --j)
        {
            if (tree_repr[i][j] != ' ')
                break;
            tree_repr[i][j] = '\0';
        }
        printf("%s\n", tree_repr[i]);
        free(tree_repr[i]);
    }
    free(tree_repr);
}
